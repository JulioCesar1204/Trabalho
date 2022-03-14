#include <stdio.h>
#include <stdlib.h>


typedef struct Fila{
    int valor;
    struct Fila *proxValor;
}Fila;

typedef Fila *ConsFila;

void exibir(ConsFila inicio){
    ConsFila f;
    f = inicio;
    
    while(f != NULL){
        printf("%8d",(*f).valor);
        f = (*f).proxValor;

    }
    printf("\n");
}

ConsFila enqueue (int valor, ConsFila inicio){
    
    ConsFila f;
    f = (ConsFila)malloc(sizeof(Fila));
   (*f).valor = valor;
   (*f).proxValor = inicio;
   inicio = f;
   return inicio;
}

ConsFila dequeue (ConsFila inicio){
    ConsFila X, Y;
    
    if (inicio == NULL){
        printf("Lista vazia\n");
        return inicio;
    } else {
    X = inicio;
    Y = inicio;
    while ((*X).proxValor != NULL){
        Y = X;
        X = (*X).proxValor;
    }
        (*Y).proxValor = NULL;
        free(X);
    }
    return inicio;
}



ConsFila consulta (int valor, ConsFila inicio){
    ConsFila f;
    f = inicio;

    if (inicio == NULL){
        printf("Lista Vazia!\n");
        return inicio;
    } else {
        while ( f != NULL){
            if ((*f).valor == valor){
               printf("Valor encontrado\n");
               return inicio;
            }
            else{
                f=(*f).proxValor;
            }
    }
        printf("Valor não encontrado na fila\n");
        return inicio;
}
}

int main()
{
    ConsFila inicio = NULL;
    int n;
    int opcao;

    printf("Escolha a operaçao\n");
    printf("0 - Encerrar o programa\n");
    printf("1 - Exibir todos os elementos da pilha\n");
    printf("2 - Operaçao Enqueue\n");
    printf("3 - Operaçao Dequeue\n");
    printf("4 - Operaçao Consulta\n");

    scanf("%i",&opcao);

    while (opcao!= 0){
    switch (opcao){
        case 1:
        exibir(inicio);
        break;
        case 2:
        printf("Digite o valor que deseja inserir na fila\n");
        scanf("%i",&n);
        inicio = enqueue(n, inicio);
        break;
        case 3:
        inicio = dequeue(inicio);
        break;
        case 4:
        printf("Digite o número que pretende pesquisar\n");
        scanf("%i",&n);
        inicio = consulta(n, inicio);
        break;
}

    printf("\n");
    system("pause");
    printf("\n");
    printf("Deseja fazer outra opereçao?\n");
    printf("0 - Encerrar o programa\n");
    printf("1 - Exibir todos os elementos da pilha\n");
    printf("2 - Operaçao Enqueue\n");
    printf("3 - Operaçao Dequeue\n");;
    printf("4 - Operaçao Consulta\n");
    scanf("%i",&opcao);
    printf("\n");
    }

    return 0;
}
 
