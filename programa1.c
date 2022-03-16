#include <stdio.h>
#include <stdlib.h>

#define vet 20

int v[vet];

void exibirElemento()
{
    int x;
    x=0;
    while(x<vet)
    {
        printf("v[%d] = %d \n", x, v[x]);
        x++;
    }
}

void inserirElemento(int elemento)
{
    int aux, aux2, i;
    aux=v[0];
    for(i=0;i<vet-1;i++)
    {
        aux2=aux;
        aux=v[i+1];
        v[i+1]=aux2;
    }
    v[0]=elemento;
}

void removerElemento(int indice)
{
    int i, aux, aux2;
    aux=v[vet-1];
    for(i=vet-1;i>indice;i--)
    {
        aux2=aux;
        aux=v[i-1];
        v[i-1]=aux2;
    }

void buscarElemento(int elemento)
{
    int menor, maior, meio;
    menor=0;
    maior=vet-1;
    while(menor<=maior)
    {
        meio=(maior+menor)/2;
        if(elemento==v[meio])
        {
            printf("O valor desejado esta na posicao %d", meio);
        }else
        {
            if(elemento<v[meio])
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

void ordenarListaPorInsercao()
{
    int i, j, aux;
    for(i=0;i<vet-1;i++)
    {
        j=i;
        while((j>0)&&(v[j-1]>v[j]))
        {
            aux=v[j-1];
            v[j-1]=v[j];
            v[j]=aux;
            j=j-1;
        }
    }
}

void selectionSort(int vetor[], int qtdelementos){
    int i,j,min,aux;
    for (i = 0; i < (qtdelementos - 1); i++) {
        min=i;
        for (j= i+1; j< qtdelementos;j++){
            if(vetor[j]<vetor[min]){
                min=j;
            }
        }
        if(i != min){
            aux = vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=aux;
        }
    }
}

void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }


}
void mergeSort(int vetor[], int comeco, int fim)/*passar a qtdelementos-1*/{
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main() {
     int operacao, elemento, indice, busca;
    do
    {
        printf("digite a operacao que deseja realizar:\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento no inicio da lista\n4 - Remover elemento\n5 - Buscar elemento\n6 - Ordenar lista");
        scanf("%d", operacao);
        switch(operacao)
        {
            case 1:
                exibirElemento();
                break;
            case 2:
                printf("Digite um numero:");
                scanf("%d", elemento);
                inserirElemento(elemento);
                break;
            case 4:
                printf("Digite o indice do elemento que deseja remover", indice);
                removerElemento(indice);
                break;
            case 5:
                printf("Digite o elemento que esta buscando");
                scanf("%d", busca);
                buscarElemento(busca);
                break;
            case 6:
                ordenarListaPorInsercao();
                break;
            case 7:
                selectionSort(v, vet);
                break
            default:
                printf("Digite um numero valido:");
                scanf("%d", operacao);
        }
    }
    while(operacao=!0);
    return 0;
}

