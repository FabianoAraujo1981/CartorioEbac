#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //função responsável pelo cadastro dos dados no sistema
{
	//inicio da criação de variáveis e strings (conjunto de variáveis)
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//final da criação de variáveis
		
		printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
		scanf("%s", cpf); //%s refere-se ao armazenamento de strings
		strcpy(arquivo, cpf); //responsável por copiar os valores das strings
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo w=write
		fprintf(file,cpf); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");					
}

int consultar ()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. Dados inexistentes no arquivo!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	
	{
		printf("\nEstas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n\n");
		fclose(file);
	}
	
	{
		system("pause");
	}
	
}

int deletar ()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado do sistema! \n");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("Este CPF não se encontra neste sistema! \n");
			system("pause");
		}
			
}


int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco+1;)
	{
	
		system("cls"); //responsável por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
	
		printf("##### Cadastro dos Alunos da EBAC #####\n\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu a seguir:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("OPÇÃO: "); //final do menu
	
		scanf("%d", &opcao); //armazenando as escolhas do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1: //chamada das funções
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("ESTA OPÇÃO NÃO EXISTE!!!!\n\n\n");
			system("pause");
			break;
				
		}
	
		
		
	
			
	}
}

