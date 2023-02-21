#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o espa�o em memoria
#include <locale.h> //biblioteca de texto por regi�o
#include <string.h> //biblioteca responsavel pelas strings

int registro()//criamos as fun�oes registro, consulta e deletar
{
	setlocale(LC_ALL,"Portuguese");
	
	printf("#########################################\n");
	printf("Voce escolheu a op��o (1) - Registro ! ##\n");
	printf("#########################################\n");
	
	char arquivo[40];//criar as variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("#################\n");
	printf("Vamos come�ar: ##\n");
	printf("#################\n");
	printf("Digite o Cpf: ");
	scanf("%s",cpf);
	
	
	strcpy(arquivo,cpf);//string copy - copiar a string cpf na variavel arquivo
	
	FILE *file;//usando a fun��o FILE criar um arquivo para ser armazenado nossos dados
	file = fopen(arquivo,"w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo,"a");//"a" - atualiza��o do arquivo que foi armazenado
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
			
	system("pause");	// fim da fun��o registro
	
}
int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char consulta[200];	
	
	printf("#########################################\n");
	printf("Voce escolheu a op��o (2) - Consulta ! ##\n");
	printf("#########################################\n");
	
	printf("#################\n");
	printf("Vamos come�ar: ##\n");
	printf("#################\n");
	printf("Digite o Cpf que deseja consultar: "); //pegamos com o usuario o que ele quer consultar
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" - read - ler o que tem dentro do arquivo
	
	if(file == NULL); //se - o arquivo nao existir
	{
		printf("#####################################################\n");
		printf("Desculpe, n�o achamos nenhum registro com esse cpf. #\n");
		printf("#####################################################\n");
	}
	
	while(fgets(consulta,200,file) != NULL);//enquanto - voce preencher a variavel consulta com o q tem dentro do arquivo file ele continua
	{
		printf("########################################\n");
		printf("Essas s�o as informa��es do registro: ##\n");
		printf("########################################\n\n"); // dizemos para o usuario o que ele consultou
		printf("%s",consulta);
		printf("\n\n");		
		printf("######################\n");
		printf("Consulta finalizada.##\n");	
		printf("######################\n\n");	
	}
	
	system("pause"); //fim da fun��o consulta
}
int deletar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("#########################################\n");
	printf("Voce escolheu a op��o (3) - Deletar ! ###\n");
	printf("#########################################\n\n");
	
	printf("#################\n");
	printf("Vamos come�ar: ##\n");
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
		printf("O usu�rio n�o se encontra no sistema! ##\n");
		printf("########################################\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0;
	int x = 1;
	
	for(x=1;x=1;) //Iniciar a repeti��o da tela
	{
		
		system("cls"); //Limpar a tela

		setlocale(LC_ALL,"Portuguese"); //setar o texto para portugu�s 
	
		printf("########### Cart�rio da EBAC ############\n");
		printf("#########################################\n");
		printf("## Ol�! Escolha uma das op��es abaixo: ##\n");
		printf("#########################################\n"); //Primeira tela - A do menu e a escolha do usu�rio
		printf("#####       1 - Registro            #####\n"); 
		printf("#####       2 - Consulta            #####\n");
		printf("#####       3 - Deletar             #####\n");
		printf("#########################################\n\n");
		printf("Op��o: ");
		scanf("%d",&opcao);
	
		system("cls"); //Limpar a tela
	
		//Inicio das a��es que devem ser seguidas
		switch(opcao)
		{
			case 1:
				registro(); //ir para a fun��o registro
				break;
				
			case 2:
				consulta(); //ir para a fun��o consulta
				break;
				
			case 3:				
				deletar(); //ir para a fun��o deletar
				break;
			
			default: // se utilizar alguma op��o invalida
				printf("########################################################\n");
				printf("Escolha por favor uma op��o v�lida do menu anterior ! ##\n");
				printf("########################################################\n\n");
				system("pause");
				break;
		}
		//Final das a��es que devem ser seguidas
	}
	
	
}
