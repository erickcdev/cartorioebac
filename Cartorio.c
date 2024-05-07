#include <stdio.h> //biblioteca de comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string


int registro() // Fun��o para cadastrar usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese");	// todo o texto est� em portugues
	
	//inicio da cria��o das vari�veis
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da cria��o das vari�veis
	// ";" = instru��o
		
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf);	// %s salvar dentro de uma string
	
	strcpy(arquivo, cpf); // strcpy = copiar o valor da string (string cpf = string arquivo)
	
	FILE *file; //Procurar estrutura FILE porque ser� criado um arquivo file
	file = fopen(arquivo, "w");  // criar um arquivo "arquivo" e abrir� ("w" = wright = escrever)
	fprintf(file,cpf); // salvando o valor da vari�vel cpf no arquivo file 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao inv�s de dar o printf para o usu�rio ele dar� para o arquivo
	fclose(file); // fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); // salvando dentro da string
	
	file = fopen(arquivo, "a"); //atualizar o arquivo "arquivo"
	fprintf(file,nome); //dar printf para o arquivo
	fclose(file); // fechar arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao inv�s de dar o printf para o usu�rio ele dar� para o arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o sobre nome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s",sobrenome); // salvando dentro da string
	
	file=fopen(arquivo, "a"); // atualizar arquivo "arquivo"
	fprintf(file,sobrenome); // dar printf para o arquivo
	fclose(file); // fechar arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao inv�s de dar o printf para o usu�rio ele dar� para o arquivo
	fclose(file);// fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s",cargo); // salvando dentro da string
	
	file=fopen(arquivo, "a"); // atualizando arquivo "arquivo"
	fprintf(file,cargo); // printf para o arquivo
	fclose(file); // fechando arquivo
	
	system("pause"); //esperar a��o do usu�rio
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");	// todo o texto est� em portugues
	
	// criando vari�veis
	char cpf[40];
	char conteudo[200];
	// final das vari�veis
	
	printf("Digite o cpf a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); // salvando na string
	
	FILE *file; // criando o arquivo "file"
	file = fopen(cpf,"r"); // "r" de read vai ler o arquivo 
	
	if (file == NULL) // Se n�o localizar o cpf
	{
		printf("Usu�rio n�o cadastrado \n"); // mensagem pro usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while = enquanto // fgets abrir arquivo (enquanto estiver escrevendo na string conteudo at� 200 valores, enquanto for diferente de nulo ele ir� apresentar  (!= Null = diferente de nulo)
	{
		printf("\nessas s�o as informa��es do usu�rio: "); //mensagem pro usu�rio
		printf("%s", conteudo); // salvando na string
		printf("\n\n"); // espa�amento
	}
	
	system("pause"); // esperar a��o do usu�rio
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	// cria��o da vari�vel
	char cpf[40];
	// final da vari�vel
	
	printf ("Digite o CPF do usu�rio a ser deletado: "); // coletando informa��o do usu�rio
	scanf("%s",cpf); // salvando na string
	
	remove(cpf); // remove o CPF
	FILE *file; // cria o arquivo file
	file = fopen(cpf,"r"); // consultando string
	
	if (file == NULL) // se for nulo
	{
		printf("Usu�rio n�o cadastrado \n");
	}
	
	if (file != NULL) // se n�o for nulo
	{
		printf("Usu�rio deletado \n");
	}
	
	system("pause");
	
}


int main() //principal
{
	int opcao=0; // definindo vari�vel
	int laco=1;
	
	for(laco=1;laco=1;) //++ adiciona +1 (x=1;x=10;x++) x=1; x=1+1, etc...
	{
			system("cls"); // limpar a tela
	
	
	
			setlocale(LC_ALL, "Portuguese");	// todo o texto est� em portugues
	
			printf("### Cart�rio da EBAC ###\n\n"); // printf mostrar em tela //\n = pula linha
			printf("Escolha a op��o deseja do menu:\n\n");
			printf("\t1 - Registrar nomes\n"); //\t espa�o (t1,t2,t3 = sequencia num�rica listada espa�ada por linha)
			printf("\t2 - Consultar CPF\n");
			printf("\t3 - Deletar CPF\n\n");
			printf("\t4 - Sair do sistema");
	
			printf("Escolha a op��o:");

			scanf("%d", &opcao);    // scanf = armazenar escolha do usu�rio    // "%d" vari�vel do tipo inteiro // & = vincula a vari�vel (op��o)
	
			system("cls");  // usar o comando do sistema operacional CLS = limpar tela
			
			switch(opcao)
			{
				case 1: //op��o 1
				registro(); // chamada de fun��o
				break;
				
				case 2: //op��o 2
				consulta(); // chamada de fun��o
				break;
								
				case 3: //op��o 3
				deletar();	// chamada de fun��o			
				break;
				
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0; // sair do sistema
				break;
												
				default: //diferente do padr�o; fim do switch (op��o inexistente)
				printf("Essa op��o n�o est� dispon�vel\n"); 
				system("pause");
				break;
			
			
			}//fim
				
			
	}
}
