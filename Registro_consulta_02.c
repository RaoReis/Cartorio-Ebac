#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação espaço em memoria
#include <locale.h> //biblioteca de texto por região
#include <string.h> //biblioteca responsavel pelas strings

int registro()//criamos as funçoes registro, consulta e deletar
{
	setlocale(LC_ALL,"Portuguese");
	
	printf("#########################################\n");
	printf("Voce escolheu a opção (1) - Registro ! ##\n");
	printf("#########################################\n");
	
	char arquivo[40];//criar as variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("#################\n");
	printf("Vamos começar: ##\n");
	printf("#################\n");
	printf("Digite o Cpf: ");
	scanf("%s",cpf);
	
	
	strcpy(arquivo,cpf);//string copy - copiar a string cpf na variavel arquivo
	
	FILE *file;//usando a função FILE criar um arquivo para ser armazenado nossos dados
	file = fopen(arquivo,"w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo,"a");//"a" - atualização do arquivo que foi armazenado
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // atualizamos o registro com o nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); // atualizamos o registro com o sobrenome
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo: "); // atualizamos o registro com o cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,".");
	fclose(file);
	
	printf("##################################\n");
	printf("Cadastro finalizado. Bem vindo. ##\n");
	printf("##################################\n");
			
	system("pause");	// fim da função registro
	
}
int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char consulta[200];	
	
	printf("#########################################\n");
	printf("Voce escolheu a opção (2) - Consulta ! ##\n");
	printf("#########################################\n");
	
	printf("#################\n");
	printf("Vamos começar: ##\n");
	printf("#################\n");
	printf("Digite o Cpf que deseja consultar: "); //pegamos com o usuario o que ele quer consultar
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" - read - ler o que tem dentro do arquivo
	
	if(file == NULL); //se - o arquivo nao existir
	{
		printf("#####################################################\n");
		printf("Desculpe, não achamos nenhum registro com esse cpf. #\n");
		printf("#####################################################\n");
	}
	
	while(fgets(consulta,200,file) != NULL);//enquanto - voce preencher a variavel consulta com o q tem dentro do arquivo file ele continua
	{
		printf("########################################\n");
		printf("Essas são as informações do registro: ##\n");
		printf("########################################\n\n"); // dizemos para o usuario o que ele consultou
		printf("%s",consulta);
		printf("\n\n");		
		printf("######################\n");
		printf("Consulta finalizada.##\n");	
		printf("######################\n\n");	
	}
	
	system("pause"); //fim da função consulta
}
int deletar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("#########################################\n");
	printf("Voce escolheu a opção (3) - Deletar ! ###\n");
	printf("#########################################\n\n");
	
	printf("#################\n");
	printf("Vamos começar: ##\n");
	printf("#################\n");
	printf("Digite o Cpf que deseja deletar: "); //pegamos com o usuario o que ele quer deletar
	scanf("%s",cpf);
	
	remove(cpf); //deletamos o que o usuario deseja
	
	printf("#####################################\n");
	printf("Registro no Cpf desejado deletado. ##\n");
	printf("#####################################\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //lemos a pasta
	
	if(file == NULL)
	{
		printf("########################################\n");
		printf("O usuário não se encontra no sistema! ##\n");
		printf("########################################\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0;
	int x = 1;
	
	for(x=1;x=1;) //Iniciar a repetição da tela
	{
		
		system("cls"); //Limpar a tela

		setlocale(LC_ALL,"Portuguese"); //setar o texto para português 
	
		printf("########### Cartório da EBAC ############\n");
		printf("#########################################\n");
		printf("## Olá! Escolha uma das opções abaixo: ##\n");
		printf("#########################################\n"); //Primeira tela - A do menu e a escolha do usuário
		printf("#####       1 - Registro            #####\n"); 
		printf("#####       2 - Consulta            #####\n");
		printf("#####       3 - Deletar             #####\n");
		printf("#########################################\n\n");
		printf("Opção: ");
		scanf("%d",&opcao);
	
		system("cls"); //Limpar a tela
	
		//Inicio das ações que devem ser seguidas
		switch(opcao)
		{
			case 1:
				registro(); //ir para a função registro
				break;
				
			case 2:
				consulta(); //ir para a função consulta
				break;
				
			case 3:				
				deletar(); //ir para a função deletar
				break;
			
			default: // se utilizar alguma opção invalida
				printf("########################################################\n");
				printf("Escolha por favor uma opção válida do menu anterior ! ##\n");
				printf("########################################################\n\n");
				system("pause");
				break;
		}
		//Final das ações que devem ser seguidas
	}
	
	
}
