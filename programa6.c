#include <stdio.h>
#include <stdlib.h>

typedef struct Noh
{
    int valor;
    struct Noh *ant;
    struct Noh *prox;
} Noh;

typedef Noh *NohPtr;

NohPtr inserir(int valor, NohPtr inicio)
{
    NohPtr nohAtual, novoNoh;
    if (inicio == NULL)
    {
        novoNoh = (NohPtr)malloc(sizeof(Noh));
        novoNoh->valor = valor;
        novoNoh->prox = NULL;
        novoNoh->ant = NULL;
        inicio = novoNoh;
    }
    else
    {
        novoNoh = (NohPtr)malloc(sizeof(Noh));
        novoNoh->valor = valor;
        if (valor <= inicio->valor)
        {
            novoNoh->prox = inicio;
            novoNoh->ant = NULL;
            inicio->ant = novoNoh;
            inicio = novoNoh;
        }
        else
        {
            // ...(anterior) <=> (novo) <=> (atual)...
            nohAtual = inicio;
            NohPtr nohAnterior = inicio;
            while (valor > nohAtual->valor)
            {
                nohAnterior = nohAtual;
                nohAtual = nohAtual->prox;
                if (nohAtual == NULL)
                    break;
            }
            novoNoh->prox = nohAtual;
            novoNoh->ant = nohAnterior;
            nohAnterior->prox = novoNoh;
            if (nohAtual != NULL)
            {
                nohAtual->ant = novoNoh;
            }
        }
    }
    return inicio;
}

NohPtr retirar(int valor, NohPtr inicio)
{
    if (inicio == NULL)
        return NULL;

    // edge case: remover primeiro nó
    if (inicio->valor == valor)
    {
        // lista possui um só nó
        if (inicio->prox == NULL)
        {
            free(inicio);
            return NULL;
        }
        else
        {
            NohPtr novoPrimeiroNoh = inicio->prox;
            novoPrimeiroNoh->ant = NULL;
            free(inicio);
            return novoPrimeiroNoh;
        }
    }

    NohPtr nohAtual = inicio->prox;
    while (nohAtual != NULL)
    {
        if (nohAtual->valor == valor)
        {
            NohPtr proxNoh = nohAtual->prox;
            nohAtual->ant->prox = proxNoh;
            if (proxNoh != NULL)
                proxNoh->ant = nohAtual->ant;
            free(nohAtual);
            break;
        }
        else
        {
            nohAtual = nohAtual->prox;
        }
    }
    return inicio;
}

void listar(NohPtr inicio)
{
    if (inicio == NULL)
        return;
    NohPtr nohAtual = inicio;
    printf("inicio em %u \n", inicio);
    printf("[");
    do
    {
        printf("%d, ", nohAtual->valor, nohAtual);
        nohAtual = nohAtual->prox;
    } while (nohAtual != NULL);
    printf("]\n");
}

int main()
{
    NohPtr inicio = NULL;
    int numero;
    int opcao = -1;
    while (opcao != 0)
    {
        opcao = 0;
        printf("\n\nEscolha a operação: \n");
        printf("0 - Encerrar o programa\n");
        printf("1 - Exibir todos os elementos da lista\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf(": ");
        scanf("\n%d", &opcao);
        printf("\n\n");

        switch (opcao)
        {
        case 0:
            return 0;
        case 1:
            printf("Lista: ");
            listar(inicio);
            break;
        case 2:
            printf("Digite o numero a ser inserido: ");
            scanf("\n%d", &numero);
            inicio = inserir(numero, inicio);
            break;
        case 3:
            printf("Digite o numero a ser removido: ");
            scanf("\n%d", &numero);
            inicio = retirar(numero, inicio);
            break;
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }
    return 0;
}
