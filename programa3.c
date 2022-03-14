#include <stdio.h>
#include <stdlib.h>
#define TAM 20


void exibir (int *vet, int qtElementos){
    printf("Elementos da pilha:\n");
    for (int i = 0 ; i < qtElementos; i++ ){
        printf("(%i) Elemento da Pillha: %i \n",i+1,vet[i]);
    }
    printf("\n");

}
void push (int *vet, int valor, int *qtElementos){

    if(*qtElementos==TAM){
            return printf("Você nao pode inserir mais valores, pois a lista está cheia.");
    }
    else{
        vet[*qtElementos]=valor;
        *qtElementos= *qtElementos+1;
    }
    printf("Operação push feita com sucesso!\n",valor);


}
void pop (int *vet, int *qtElementos){
    
        vet[*qtElementos-1] = NULL;
        *qtElementos=*qtElementos-1;
    printf("Operação pop feita com sucesso! \n");
    printf("\n");
    }

void consulta(int vet[], int qtElementos, int valor){
  for (int i=0; i < qtElementos; i++){
    if(vet[i]==valor){
        printf("Valor encontrado na pilha, no índice %i",i);
        return 1;
        
    }
  }
  printf("Valor nao encontrado na pilha. \n");
  return ;

}

int main()
{
    int *vet;
    int qtElementos;
    int opcao;
    int x;
    
    printf("Digite o tamanaho da pilha (máximo 20 elementos): \n");
    scanf("%i",&qtElementos);
    while(qtElementos>20){
        printf("Tamanho digitado acima do permitido\n");
        scanf("%i",&qtElementos);
    }
    vet = (int *) malloc(qtElementos *sizeof(int));

    printf("Digite os valores da pilha \n");
    for(int i=0;i<qtElementos;i++){
    printf("Digite o elemento numero %i da pilha: \n",i+1);
    scanf("%i",&vet[i]);
    }


    system("cls");
    printf("Pilha criada. Agora a pilha possui %i elementos \n", qtElementos);
    printf("\nEscolha a operação\n");
    printf("0 - Encerrar o programa\n");
    printf("1 - Exibir todos os elementos da pilha\n");
    printf("2 - Operaçao Push\n");
    printf("3 - Operaçao Pop\n");
    printf("4 - Operaçao Consulta\n");




    scanf("%i",&opcao);

    while (opcao!= 0){
    switch (opcao){
        case 1:
        exibir(vet, qtElementos);
        break;
        case 2:
        printf("Digite o valor que deseja inserir na Pilha\n");
        scanf("%i",&x);
        push(vet, x, &qtElementos);
        break;
        case 3:
        pop(vet,&qtElementos);
        break;
        case 4:
        printf("Digite o número que pretende pesquisar\n");
        scanf("%i",&x);
        consulta(vet,qtElementos, x);
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
    scanf("%i",&opcao);
    printf("\n");
    }

    return 0;
}
 
