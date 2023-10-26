#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Atendimento {
    char nome[100];
    char cpf[15];
    int tipoAtendimento;
};

struct Atendimento atendimentos[100]; // Espaço para 100 atendimentos
int numAtendimentos = 0; // começa com zero

// Chamada 3
void cadastrarAtendimento() {
	setlocale(LC_ALL, "Portuguese");

    printf("Nome Completo: \n");
    fflush(stdin);
    gets(atendimentos[numAtendimentos].nome);
    printf("CPF Ex: XXX.XXX.XXX-XX: \n");
    gets(atendimentos[numAtendimentos].cpf);
    fflush(stdin); // passagem de script
    printf("Tipo de Atendimento:\n");
    printf("1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Fisica\n 4 - Gerente Pessoa Juridica\n"); //lista de escolha
    printf("Escolha o tipo: ");
    scanf("%d", &atendimentos[numAtendimentos].tipoAtendimento);
    numAtendimentos++;
    printf("Atendimento cadastrado com sucesso!\n");
    system("cls");

}

// escolha do usuario
void listarTodosAtendimentos() {
    for (int i = 0; i < numAtendimentos; i++) {
        printf("Nome do cliente: %s\n", atendimentos[i].nome);
        printf("CPF do cliente: %s\n", atendimentos[i].cpf);
        printf("Tipo Atendimento - %d - ", atendimentos[i].tipoAtendimento);
        switch (atendimentos[i].tipoAtendimento) {
            case 1:
                printf("Abertura de Conta\n");
                break;
            case 2:
                printf("Caixa\n");
                break;
            case 3:
                printf("Gerente Pessoa Fisica\n");
                break;
            case 4:
                printf("Gerente Pessoa Juridica\n");
                break;
            default:
                printf("Tipo de Atendimento desconhecido.\n");
                break;

        }

			   printf("===============================\n");

    }

}


    // resultado de cadastro
void listarAtendimentosPorTipo(int tipo) {
    printf("Atendimentos do tipo %d:\n", tipo);
    for (int i = 0; i < numAtendimentos; i++) {
        if (atendimentos[i].tipoAtendimento == tipo) {
            printf("Nome do cliente: %s\n", atendimentos[i].nome);
            printf("CPF do cliente: %s\n", atendimentos[i].cpf);
            printf("===============================\n");
        }
    }
}

// chamada 1 - Inicial
int main() {


    int opcao, tipo;

    while (1) {
        printf("Bem-vindo ao sistema de atendimento do Banco(Nome do Banco)\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAtendimento();
                break;
            case 2:
                listarTodosAtendimentos();
                break;
            case 3:

                printf("Digite o tipo de atendimento que deseja listar (1 a 4): ");
                scanf("%d", &tipo);
                listarAtendimentosPorTipo(tipo);
                break;
            case 4:
                exit(0);
                break;
            case 5:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
