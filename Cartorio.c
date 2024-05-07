#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string


int registro() // Função para cadastrar usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese");	// todo o texto está em portugues
	
	//inicio da criação das variáveis
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da criação das variáveis
	// ";" = instrução
		
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf);	// %s salvar dentro de uma string
	
	strcpy(arquivo, cpf); // strcpy = copiar o valor da string (string cpf = string arquivo)
	
	FILE *file; //Procurar estrutura FILE porque será criado um arquivo file
	file = fopen(arquivo, "w");  // criar um arquivo "arquivo" e abrirá ("w" = wright = escrever)
	fprintf(file,cpf); // salvando o valor da variável cpf no arquivo file 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao invés de dar o printf para o usuário ele dará para o arquivo
	fclose(file); // fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); // salvando dentro da string
	
	file = fopen(arquivo, "a"); //atualizar o arquivo "arquivo"
	fprintf(file,nome); //dar printf para o arquivo
	fclose(file); // fechar arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao invés de dar o printf para o usuário ele dará para o arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o sobre nome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s",sobrenome); // salvando dentro da string
	
	file=fopen(arquivo, "a"); // atualizar arquivo "arquivo"
	fprintf(file,sobrenome); // dar printf para o arquivo
	fclose(file); // fechar arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // fprintf ao invés de dar o printf para o usuário ele dará para o arquivo
	fclose(file);// fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informação do usuário
	scanf("%s",cargo); // salvando dentro da string
	
	file=fopen(arquivo, "a"); // atualizando arquivo "arquivo"
	fprintf(file,cargo); // printf para o arquivo
	fclose(file); // fechando arquivo
	
	system("pause"); //esperar ação do usuário
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");	// todo o texto está em portugues
	
	// criando variáveis
	char cpf[40];
	char conteudo[200];
	// final das variáveis
	
	printf("Digite o cpf a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); // salvando na string
	
	FILE *file; // criando o arquivo "file"
	file = fopen(cpf,"r"); // "r" de read vai ler o arquivo 
	
	if (file == NULL) // Se não localizar o cpf
	{
		printf("Usuário não cadastrado \n"); // mensagem pro usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while = enquanto // fgets abrir arquivo (enquanto estiver escrevendo na string conteudo até 200 valores, enquanto for diferente de nulo ele irá apresentar  (!= Null = diferente de nulo)
	{
		printf("\nessas são as informações do usuário: "); //mensagem pro usuário
		printf("%s", conteudo); // salvando na string
		printf("\n\n"); // espaçamento
	}
	
	system("pause"); // esperar ação do usuário
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	// criação da variável
	char cpf[40];
	// final da variável
	
	printf ("Digite o CPF do usuário a ser deletado: "); // coletando informação do usuário
	scanf("%s",cpf); // salvando na string
	
	remove(cpf); // remove o CPF
	FILE *file; // cria o arquivo file
	file = fopen(cpf,"r"); // consultando string
	
	if (file == NULL) // se for nulo
	{
		printf("Usuário não cadastrado \n");
	}
	
	if (file != NULL) // se não for nulo
	{
		printf("Usuário deletado \n");
	}
	
	system("pause");
	
}


int main() //principal
{
	int opcao=0; // definindo variável
	int laco=1;
	
	for(laco=1;laco=1;) //++ adiciona +1 (x=1;x=10;x++) x=1; x=1+1, etc...
	{
			system("cls"); // limpar a tela
	
	
	
			setlocale(LC_ALL, "Portuguese");	// todo o texto está em portugues
	
			printf("### Cartório da EBAC ###\n\n"); // printf mostrar em tela //\n = pula linha
			printf("Escolha a opção deseja do menu:\n\n");
			printf("\t1 - Registrar nomes\n"); //\t espaço (t1,t2,t3 = sequencia numérica listada espaçada por linha)
			printf("\t2 - Consultar CPF\n");
			printf("\t3 - Deletar CPF\n\n");
			printf("\t4 - Sair do sistema");
	
			printf("Escolha a opção:");

			scanf("%d", &opcao);    // scanf = armazenar escolha do usuário    // "%d" variável do tipo inteiro // & = vincula a variável (opção)
	
			system("cls");  // usar o comando do sistema operacional CLS = limpar tela
			
			switch(opcao)
			{
				case 1: //opção 1
				registro(); // chamada de função
				break;
				
				case 2: //opção 2
				consulta(); // chamada de função
				break;
								
				case 3: //opção 3
				deletar();	// chamada de função			
				break;
				
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0; // sair do sistema
				break;
												
				default: //diferente do padrão; fim do switch (opção inexistente)
				printf("Essa opção não está disponível\n"); 
				system("pause");
				break;
			
			
			}//fim
				
			
	}
}
