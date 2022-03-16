#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 20

void exibirElemento(int * vetor, int quantidadeElementos)
{

    printf("\n\nExibindo a lista abaixo:\n", quantidadeElementos);
    for (int i = 0 ; i < quantidadeElementos; i++ ){
        printf("%i ",vetor[i]);
    }

    printf("\n\n");
}

int inserirElemento(int elemento, int * vetor, int quantidadeElementos)
{

    if (quantidadeElementos >= TAMANHO_MAX)
    {
        printf("\nO vetor está cheio");
        return quantidadeElementos;
    }

    int aux, aux2, i;
    aux = vetor[0];

    if(quantidadeElementos == 0) {
        vetor[0] = elemento;
        printf("returning more");
        return ++quantidadeElementos;

    }

    else {
        for (i = 0; i < quantidadeElementos; i++)
        {
            aux2 = aux;
            aux = vetor[i + 1];
            vetor[i + 1] = aux2;
        }
        vetor[0] = elemento;
        return ++quantidadeElementos;
    }
}

int removerElemento(int indice, int *vetor, int quantidadeElementos)
{
    if(indice >= quantidadeElementos) {
        printf("\n\nElemento nao existe\n\n");
        return;
    }

    int i, aux, aux2;
    aux = vetor[quantidadeElementos - 1];
    for (i = quantidadeElementos - 1; i > indice; i--)
    {
        aux2 = aux;
        aux = vetor[i - 1];
        vetor[i - 1] = aux2;
    }
}

void buscarElemento(int elemento, int* vetor, int quantidadeElementos)
{
    int ul = 0;
    for (int i = 0; i < quantidadeElementos - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
        {
            ul = ul + 1;
        }
    }

    if (ul >= 1)
    {
        printf("O vetor está desordenado");
        return;
    }

    int menor, maior, meio;
    menor=0;
    maior=quantidadeElementos-1;
    while(menor<=maior)
    {
        meio=(maior+menor)/2;
        if(elemento==vetor[meio])
        {
            printf("O valor desejado esta na posicao %d", meio);
        }else
        {
            if(elemento<vetor[meio])
            {
                maior=meio-1;
            }else
            {
                menor=meio+1;
            }
        }
    }
    if(meio=!elemento)
    {
        printf("O valor desejado nao se encontra no vetor");
    }
}

void ordenarListaPorInsercao(int *vetor, int quantidadeElementos)
{
    int i, j, aux;
    for (i = 0; i < quantidadeElementos - 1; i++)
    {
        j = i;
        while ((j > 0) && (vetor[j - 1] > vetor[j]))
        {
            aux = vetor[j - 1];
            vetor[j - 1] = vetor[j];
            vetor[j] = aux;
            j = j - 1;
        }
    }
}

void selectionSort(int vetor[], int qtdelementos)
{
    int i, j, min, aux;
    for (i = 0; i < (qtdelementos - 1); i++)
    {
        min = i;
        for (j = i + 1; j < qtdelementos; j++)
        {
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

void merge(int vetor[], int comeco, int meio, int fim)
{

    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int *vetAux;
    vetAux = (int *)malloc(tam * sizeof(int));

    while (com1 <= meio && com2 <= fim)
    {
        if (vetor[com1] < vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while (com1 <= meio)
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while (com2 <= fim)
    {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for (comAux = comeco; comAux <= fim; comAux++)
    {
        vetor[comAux] = vetAux[comAux - comeco];
    }
}

void mergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int meio = (fim + comeco) / 2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main()
{

    int quantidadeElementos = 0;
    int *vetor;

    int operacao, elemento, indice, busca;
    do
    {
        printf("digite a operacao que deseja realizar:\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento no inicio da lista\n4 - Remover elemento\n5 - Buscar elemento\n6 - Ordenar lista");
        printf("\n: ");
        scanf("%d", &operacao);
        switch (operacao)
        {
        case 1:
            exibirElemento(vetor, quantidadeElementos);
            break;
        case 2:
            printf("Digite um numero:");
            scanf("%d", &elemento);
            quantidadeElementos = inserirElemento(elemento, vetor, quantidadeElementos);
            break;
        case 4:
            printf("Digite o indice do elemento que deseja remover", indice);
            scanf("%d", &indice);
            removerElemento(indice, vetor, quantidadeElementos);
            break;
        case 5:
            printf("Digite o elemento que esta buscando: ");
            scanf("%d", &busca);
            buscarElemento(busca, vetor, quantidadeElementos);
            break;
        case 6:
            ordenarListaPorInsercao(vetor, quantidadeElementos);
            break;
        case 7:
            selectionSort(vetor, quantidadeElementos);
            break;
        default:
            printf("Digite um numero valido:");
            scanf("%d", &operacao);
        }
    } while (operacao != 0);
    return 0;
}
