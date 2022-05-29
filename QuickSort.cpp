// QuickSort

#include <iostream>
using namespace std;
#define N 8

/*
Método Dividir para Conquistar e Concatenar:
Dividir - dividir o array recursivamente em partes menores até que não seja mais possível
Conquistar - classificar essas partes. A cada divisão, os elementos do lado esquerdo são menores do que a chave;
os elementos do lado direito são maiores do que a chave.
Combinar - concatenar as partes formando uma única lista ordenada.
*/

void troca(int *x, int *y) // ponteiro
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux; // algoritmo padrão de troca
}

void quickSort(int arr[], int inicio, int fim)
{
    int i, j, chave;
    if(fim - inicio < 2)
    {
        if((fim - inicio) == 1)
        {
            if(arr[inicio] > arr[fim])
            {
                troca(&arr[inicio], &arr[fim]);
            }
        }
    }
    else
    {
        i = inicio;
        j = fim;
        chave = arr[inicio];
        while(j>i)
        {
            i++;
            while(arr[i] < chave)
            {
                i++;
            }
            while(arr[j] > chave)
            {
                j--;
            }
            if(j>i)
            {
                troca(&arr[i], &arr[j]);
            }
        } // fim do while
        troca(&arr[inicio], &arr[j]);
        quickSort(arr, inicio, j-1);
        quickSort(arr, j+1, fim);
    }
}

int main()
{
    int arr[N] = {21, 33, 12, 8, 76, 44, 89, 90};
    int inicio = 0, fim = N-1;

    quickSort(arr, inicio, fim);
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << "\t";
    }
}