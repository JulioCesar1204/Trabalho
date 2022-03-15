
#include <stdio.h>
#include <stdlib.h>

typedef struct Noh
{
    int valor;
    struct Noh *prox;
} Noh;
typedef Noh *NohPtr;

NohPtr inserirElemento(int valor, NohPtr inicio)
{
    NohPtr np, i, j = NULL;
    if (inicio == NULL)
    {
        np = (NohPtr)malloc(sizeof(Noh));
        (*np).valor = valor;
        (*np).prox = NULL;
        inicio = np;
    }
    else
    {
        i = inicio;
        np = (NohPtr)malloc(sizeof(Noh));
        (*np).valor = valor;
        while (valor > (*i).valor)
        {
            j = i;
            i = (*i).prox;
            if (i == NULL)
                break;
        }
        if (j != NULL)
        {
            (*j).prox = np;
        } else {
            inicio = np;
        }
        (*np).prox = i;
    }
    return inicio;
}

NohPtr removerElemento(int valor, NohPtr inicio)
{
    NohPtr i, j;
    i = inicio;
    if (inicio == NULL)
    {
        return NULL;
    }
    else
    {
        if ((*inicio).valor == valor)
        {
            i = (*inicio).prox;
            free(inicio);
            return i;
        }
        else
        {
            while ((*i).valor = !valor)
            {
                i = (*i).prox;
            }
            j = (*i).prox; 
            (*i).prox = (*j).prox; 
            free(j);
            return inicio;
        }
    }
}

void exibirElementos(NohPtr inicio)
{
    if (inicio == NULL)
    {
        printf("\n\nLista vazia");
        return;
    }

    NohPtr p;
    p = inicio;
    printf("\n\nLista: ");
    while (p != NULL)
    {
        printf("%d ", (*p).valor);
        p = (*p).prox;
    }
    printf("\n");
}

int main()
{
    int operacao, elemento;
    NohPtr inicio;
    inicio = NULL;

    do
    {
        printf("\n\n\nDigite um numero de acordo com a operacao que deseja realizar\n0-Encerrar o programa\n1-Exibir todos os elementos da lista\n2-Inserir elemento\n3- Remover elemento\n ");
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 0:
            return 0;
        case 1:
            exibirElementos(inicio);
            break;
        case 2:
            printf("Digite o elemento que deseja inserir:");
            scanf("%d", &elemento);
            inicio = inserirElemento(elemento, inicio);
            break;
        case 3:
            printf("Digite o elemento que deseja excluir");
            scanf("%d", &elemento);
            removerElemento(elemento, inicio);
            break;
        default:
            printf("O numero nao corresponde a nenhuma operacao.");
        }

    } while (operacao != 0);
    return 0;
}

 
