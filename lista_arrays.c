#include <stdio.h>

// convencionamos usar o valor -1 para inicializar a lista, dado que 0 pode ser um valor válido.
int valores[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //(NULL)
int size = sizeof valores / sizeof valores[0];

//Adiciona um valor na primeira posição "vazia" (-1) disponível.
int adicionarValor(int valor)
{   
    int i;
    for (i = 0; i < size ; i++)
    {
        if (valores[i] == -1){
            valores[i] = valor;
            return 1;
        }        
    }
    return 0;
}

//Ordena a lista
void ordenarLista()
{
    
}

//Remove a primeira ocorrencia do valor procurado
int removerValor(int valor)
{
    int i;
    for (i = 0; i < size ; i++)
    {
        //"procura" o valor
        if (valores[i] == valor){
            //caso o valor encontrado não seja o último elemento da lista
            if(i != size -1)
            {
                //substitui o valor a ser removido pelo próximo elemento da lista 
                //e repete esse procedimento até que chegue a alguma posição vazia.
                int j = i;
                while(valores[j+1] != -1)
                {
                    valores[j] = valores[j+1];
                    j++;
                } 
                //remove o último valor válido (i.e., substitui o valor por -1) 
                valores[j] = -1;               
            } else {
                //caso o valor a ser removido seja o último, basta removê-lo (i.e., substituí-lo por -1) 
                 valores[i] = -1;
            }
            
            printf("valor %d removido com sucesso!\n", valor);
            return 1;
        }        
    }
    printf("valor %d não encontrado!\n", valor);
    return 0;
}

//Exibe a lista e a posição (índice) na lista, somente dos valores válidos.
void exibirLista()
{   
    int i;
    printf("|");
    for (i = 0; i < size ; i++)
    {
        if (valores[i] != -1){
            printf("(%d) %d |",i, valores[i]);
        }
    }
    printf("\n");
    
}



int main() {

//Aqui estão sendo chamados algumas funções diretamente, apenas para ver o comportamento.
//Seria melhor fazer uma "interface" que solicita ao usuário o que ele deseja fazer.
exibirLista();
adicionarValor(5);
adicionarValor(10);
adicionarValor(4);
adicionarValor(8);
adicionarValor(9);
exibirLista();

removerValor(11);
removerValor(10);

exibirLista();



return 0;
}   