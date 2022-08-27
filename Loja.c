#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char nome_produto[MAX];
    double preco_produto;
    int codigo_produto;
} produto;

typedef struct {
    char name[MAX], cpf[MAX], fone[MAX];
    int code, quant_produtos;
    double preco_comprado;
} cadastro;

void cadastrar__Cliente(cadastro *p1);
void listagem_Cadastros(cadastro *p1);
void busca_Nome(cadastro *p1, char busca[]);
void cadastrar__produto(produto *p2);
void listagem_produtos(produto *p2);
void nome_produto(produto *p2, char busca[]);
void carrinho_cliente(produto *p2, cadastro *p1, int busca);
void remove_produto(cadastro *p1, produto *p2, int i, int busca);
void final_compra(cadastro *p1, int busca);

int main(int argc, char *argv[]) {
    cadastro *p1 = (cadastro *)calloc(MAX, sizeof(cadastro));
    produto *p2 = (produto *)calloc(MAX, sizeof(produto));

    int choice, i = 0, bCode;
    char busca[MAX];

    do {
        system("cls");
        puts("\nCLIENTE:");
        puts("  -(0)-Sair");
        puts("  -(1)-Cadastrar cliente");
        puts("  -(2)-Editar cadastro");
        puts("  -(3)-Listagem");
        puts("  -(4)-Buscar por nome");
        puts("\nPRODUTOS:");
        puts("  -(5)-Cadastrar produto");
        puts("  -(6)-Editar produto");
        puts("  -(7)-Listagem");
        puts("  -(8)-Buscar por nome");
        puts("\nCARRINHO:");
        puts("  -(9)-Adicao de produtos");
        puts("  -(10)-Remocao de produtos");
        puts("  -(11)-Finalizar compra");

        printf("\nOPCAO: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                cadastrar__Cliente(p1);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("CODIGO: ");
                setbuf(stdin, NULL);
                scanf("%d", &bCode);
                system("cls");

                for (int j = 0; j < MAX - 1; j++, p1++) {
                    if (bCode == p1->code) {
                        cadastrar__Cliente(p1);
                    } else if (p1 == NULL) {
                        puts("CADASTRO NAO LOCALIZADO!");
                    }
                }
                system("pause");
                break;

            case 3:
                system("cls");
                listagem_Cadastros(p1);
                system("pause");
                break;

            case 4:
                system("cls");
                busca_Nome(p1, busca);
                system("pause");
                break;

            case 5:
                system("cls");
                cadastrar__produto(p2);
                system("pause");
                break;

            case 6:
                system("cls");
                printf("CODIGO: ");
                scanf("%d", &bCode);

                for (int j = 0; j < MAX - 1; j++, p2++) {
                    if (bCode == p2->codigo_produto) {
                        cadastrar__produto(p2);
                    } else if (p2 == NULL) {
                        puts("PRODUTO NAO LOCALIZADO!");
                    }
                }
                system("pause");
                break;

            case 7:
                system("cls");
                listagem_produtos(p2);
                system("pause");
                break;
            case 8:
                system("cls");
                nome_produto(p2, busca);
                system("pause");
                break;

            case 9:
                system("cls");
                carrinho_cliente(p2, p1, bCode);
                system("pause");
                break;

            case 10:
                system("cls");
                remove_produto(p1, p2, i, bCode);
                i = 0;
                system("pause");
                break;

            case 11:
                system("cls");
                final_compra(p1, bCode);
                system("pause");
                break;

            default:
                break;
        }

        p1 -= i;
        p2 -= i;
    } while (choice != 0);

    return 0;
}

// CADASTRO BUSCA E EDIÇÃO DO CLIENTE

void cadastrar__Cliente(cadastro *p1) {
    for (int j = 0; j < MAX - 1; j++, p1++) {
        if (p1->code == 0) {
            printf("CODIGO: ");
            scanf("%d", &p1->code);

            printf("NOME: ");
            setbuf(stdin, NULL);
            fgets(p1->name, 50, stdin);

            printf("CPF: ");
            setbuf(stdin, NULL);
            fgets(p1->cpf, 50, stdin);

            printf("TELEFONE: ");
            setbuf(stdin, NULL);
            fgets(p1->fone, 50, stdin);

            break;
        }
    }
}

void listagem_Cadastros(cadastro *p1) {
    for (int j = 0; j < MAX - 1; j++, p1++) {
        if (p1->code != 0) {
            printf("NOME: %s", p1->name);
            printf("CPF: %s", p1->cpf);
            printf("TELEFONE: %s", p1->fone);
        }
    }
    puts("");
}

void busca_Nome(cadastro *p1, char busca[]) {
    printf("NOME: ");
    setbuf(stdin, NULL);
    fgets(busca, MAX, stdin);

    for (int j = 0; j < MAX - 1; j++, p1++) {
        if (strcmp(p1->name, busca) == 0) {
            system("cls");
            printf("NOME: %s", p1->name);
            printf("CPF: %s", p1->cpf);
            printf("TELEFONE: %s", p1->fone);
            puts("");
        } else if (p1 == NULL) {
            puts("CADASTRO NAO LOCALIZADO!");
            break;
        }
    }
}

// CADASTRO BUSCA E EDIÇÃO PRODUTOS

void cadastrar__produto(produto *p2) {
    for (int j = 0; j < MAX - 1; j++, p2++) {
        if (p2->codigo_produto == 0) {
            printf("CODIGO: ");
            scanf("%d", &p2->codigo_produto);

            printf("NOME: ");
            setbuf(stdin, NULL);
            fgets(p2->nome_produto, 50, stdin);

            printf("PRECO: ");
            scanf("%lf", &p2->preco_produto);

            break;
        }
    }
}

void listagem_produtos(produto *p2) {
    for (int j = 0; j < MAX - 1; j++, p2++) {
        if (p2->codigo_produto != 0) {
            printf("\nNOME: %s", p2->nome_produto);
            printf("PRECO: %.2lf", p2->preco_produto);
        }
    }
    puts("");
}

void nome_produto(produto *p2, char busca[]) {
    printf("NOME: ");
    setbuf(stdin, NULL);
    fgets(busca, MAX, stdin);

    for (int j = 0; j < MAX - 1; j++, p2++) {
        if (strcmp(p2->nome_produto, busca) == 0) {
            system("cls");
            printf("NOME: %s", p2->nome_produto);
            printf("PRECO: %.2lf", p2->preco_produto);
            puts("");
        } else if (p2 == NULL) {
            puts("PRODUTO NAO LOCALIZADO!");
        }
    }
}

void carrinho_cliente(produto *p2, cadastro *p1, int busca) {
    printf("DIGITE O CODIGO DO PRODUTO QUE DESEJA ADICIONAR: ");
    scanf("%d", &busca);

    for (int j = 0; j < MAX - 1; j++) {
        if (busca == p2->codigo_produto) {
            p2 += j;
            break;
        } else {
            puts("PRODUTO NAO LOCALIZADO!");
        }
    }
    printf("DIGITE O CODIGO DO CADASTRO DO CLIENTE: ");
    scanf("%d", &busca);

    for (int j = 0; j < MAX - 1; j++, p1++) {
        if (busca == p1->code) {
            p1->quant_produtos++;
            p1->preco_comprado += p2->preco_produto;

            printf("QUANTIDADE DE PRODUTOS COMPRADOS: %d\n", p1->quant_produtos);
            printf("PRECO TOTAL DE PRODUTOS COMPRADOS: R$ %.2lf\n", p1->preco_comprado);
        }
    }
}

void remove_produto(cadastro *p1, produto *p2, int i, int busca) {
    printf("DIGITE O CODIGO DO PRODUTO: ");
    scanf("%d", &busca);

    for (int j = 0; j < MAX - 1; j++) {
        if (busca == p2->codigo_produto) {
            p2 += j;
            break;
        } else {
            puts("PRODUTO NAO LOCALIZADO!");
        }
    }

    printf("DIGITE O CODIGO DO CLIENTE:");
    scanf("%d", &busca);

    for (int j = 0; j < MAX - 1; j++, p1++) {
        if (busca == p1->code) {
            printf("QUANTIDADE QUE SERA REMOVIDA: ");
            scanf("%d", &i);

            p1->preco_comprado -= p2->preco_produto * i;
            p1->quant_produtos -= i;

            printf("QUANTIDADE DE PRODUTOS COMPRADOS: %d\n", p1->quant_produtos);
            printf("PRECO TOTAL DE PRODUTOS COMPRADOS: R$ %.2lf\n", p1->preco_comprado);

            break;
        } else {
            puts("CODIGO NAO LOCALIZADO");
            break;
        }
    }
}

void final_compra(cadastro *p1, int busca) {
    printf("CODIGO DO CLIENTE: ");
    scanf("%d", &busca);

    for (int j = 0; j < MAX - 1; j++) {
        if (busca == p1->code) {
            printf("QUANTIDADE DE ITENS ADQUIRIDOS: %d\n", p1->quant_produtos);
            printf("VALOR A SER PAGO: %.2lf\n", p1->preco_comprado);

            break;
        }else{
            puts("CODIGO NAO LOCALIZADO!");
            
        }
    }
}