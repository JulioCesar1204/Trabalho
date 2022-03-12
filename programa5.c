#include <stdio.h>
#include <stdlib.h>

typedef struct Noh
{
    int valor;
    struct Noh *prox;
} Noh;

typedef Noh *NohPtr;

NohPtr acharUltimoNoh(NohPtr inicio)
{
    NohPtr noh = inicio->prox;
    while (noh->prox != inicio)
        noh = noh->prox;

    return noh;
}

NohPtr inserir(int valor, NohPtr inicio)
{
    NohPtr nohAtual, nohAnterior, novoNoh;
    if (inicio == NULL)
    {
        novoNoh = (NohPtr)malloc(sizeof(Noh));
        novoNoh->valor = valor;
        novoNoh->prox = novoNoh;
        inicio = novoNoh;
    }
    else
    {
        novoNoh = (NohPtr)malloc(sizeof(Noh));
        novoNoh->valor = valor;
        if (valor <= inicio->valor)
        {
            novoNoh->prox = inicio;

            // reajustar ponteiro do ultimo nó
            NohPtr ultimoNoh = acharUltimoNoh(inicio);
            ultimoNoh->prox = novoNoh;

            inicio = novoNoh;
        }
        else
        {
            nohAtual = inicio;
            nohAnterior = inicio;
            while (valor > nohAtual->valor)
            {
                nohAnterior = nohAtual;
                nohAtual = nohAtual->prox;
                if (nohAtual == inicio)
                    break;
            }
            novoNoh->prox = nohAnterior->prox;
            nohAnterior->prox = novoNoh;
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
        if (inicio->prox == inicio)
        {
            free(inicio);
            return NULL;
        }
        else
        {
            NohPtr novoPrimeiroNoh = inicio->prox;

            // reajustar ponteiro do ultimo nó
            NohPtr ultimoNoh = acharUltimoNoh(inicio);
            ultimoNoh->prox = novoPrimeiroNoh;

            free(inicio);
            return novoPrimeiroNoh;
        }
    }

    NohPtr nohAtual = inicio->prox;
    NohPtr nohAnterior = inicio;
    while (nohAtual != inicio)
    {
        if (nohAtual->valor == valor)
        {
            NohPtr proxNoh = nohAtual->prox;
            nohAnterior->prox = proxNoh;
            free(nohAtual);
            break;
        }
        else
        {
            nohAnterior = nohAtual;
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
    printf("[");
    do
    {
        printf("%d, ", nohAtual->valor);
        nohAtual = nohAtual->prox;
    } while (nohAtual != inicio);
    printf("]\n");
}

int main()
{
    NohPtr inicio = NULL;
    int opcao = -1;
    while (opcao != 0)
    {
        opcao = 0;
        printf("Escolha a operação: \n");
        printf("0 - Encerrar o programa\n");
        printf("1 - Exibir todos os elementos da lista\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf(": ");
        scanf("\n%d", &opcao);

        switch (opcao)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Lista: ");
            listar(inicio);
            break;
        case 2:
        {
            int numero;
            printf("Digite o numero a ser inserido: ");
            scanf("\n%d", &numero);
            inicio = inserir(numero, inicio);
            break;
        }
        case 3:
        {
            int numero;
            printf("Digite o numero a ser removido: ");
            scanf("\n%d", &numero);
            inicio = retirar(numero, inicio);
            break;
        }
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }
    return 0;
}
