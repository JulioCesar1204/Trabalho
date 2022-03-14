#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct Pilha{
    int valor;
    struct Pilha *proxValor;
}Pilha;

typedef Pilha *ConsPilha;
void exibir(ConsPilha base){
    ConsPilha p;
    p=base;
    while (p!= NULL){
        printf("%8d",(*p).valor);
        p = (*p).proxValor;

    }
    printf("\n");
}
ConsPilha push (int valor, ConsPilha base){
    ConsPilha p;

    p = (ConsPilha)malloc(sizeof(Pilha));
   (*p).valor = valor;
   (*p).proxValor = base;
   base = p;
return base;
}

ConsPilha pop (ConsPilha base){
    ConsPilha p;

    if (base == NULL){
        return NULL;
    } else {
        p = (*base).proxValor;
        free(base);
        base = p;
    }
    return base;
}



ConsPilha consulta (int valor, ConsPilha base){
    ConsPilha p;
    p = base;

    if (base == NULL){
        printf("Lista Vazia!\n");
        return base;
    } else {
        while ( p != NULL){
            if ((*p).valor == valor){
               printf("Valor encontrado na pilha\n");
               return base;
            }
            else{
                p=(*p).proxValor;
            }
    }
        printf("Valor não encontrado na pilha\n");
        return base;
}
}

int main()
{
    ConsPilha base = NULL;
    int x;
    int opcao;

    printf("\nEscolha a operação\n");
    printf("0 - Encerrar o programa\n");
    printf("1 - Exibir todos os elementos da pilha\n");
    printf("2 - Operaçao Push\n");
    printf("3 - Operaçao Pop\n");
    printf("4 - Operaçao de Consulta\n");

    scanf("%i",&opcao);

    while (opcao!= 0){


    switch (opcao){
        case 1:
        exibir(base);
        break;
        case 2:
        printf("Digite o valor que deseja inserir na Pilha\n");
        scanf("%i",&x);
        base = push(x, base);
        break;
        case 3:
        base = pop(base);
        break;
        case 4:
        printf("Digite o número que pretende pesquisar\n");
        scanf("%i",&x);
        base = consulta(x, base);
        break;
}

    printf("\n");
    system("pause");
    printf("\n");
    printf("Deseja continuar fazendo operaçoes?\n");
    printf("0 - Encerrar o programa\n");
    printf("1 - Exibir todos os elementos da pilha\n");
    printf("2 - Operaçao Push\n");
    printf("3 - Operaçao Pop\n");
    printf("4 - Operaçao de Consulta\n");
'   scanf("%i",&opcao);
    printf("\n");
    }
    return 0;
}

 
