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

void ordenarLista()
{

}


int main() {
    
    return 0;
}

