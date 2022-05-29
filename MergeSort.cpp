//MergeSort

#include <iostream>
using namespace std;
#define N 10

void intercala(int arr[], int inicio, int fim, int meio)
{
    int i, aux[N], posLivre = inicio, inicioArr1 = inicio, inicioArr2 = meio +1;

    while(inicioArr1 <= meio && inicioArr2 <= fim)
    {
        if(arr[inicioArr1] > arr[inicioArr2])
        {
            aux[posLivre] = arr[inicioArr2];
            inicioArr2++;
        }
        else
        {
            aux[posLivre] = arr[inicioArr1];
            inicioArr1++;
        }
        posLivre++;
    } 
    for(i = inicioArr1; i <= meio; i++) // elementos do primeiro array que não foram intercalados
    {
        aux[posLivre] = arr[i];
        posLivre++;
    }
    for(i = inicioArr2; i <= fim; i++) // elementos do segundo array que não foram intercalados
    {
        aux[posLivre] = arr[i];
        posLivre++;
    }
    for(i = inicio; i <= fim; i++) // atualiza o array conforme o array aux
    {
        arr[i] = aux[i];
    }
}

void mergeSort(int arr[], int inicio, int final)
{
    int meio;
    if(inicio < final)
    {
        meio = (inicio + final) / 2; // vai dividindo o array pela metade
        mergeSort(arr, inicio, meio); // RECURSÃO -> essa parte vai dividindo a primeira metade do array
        mergeSort(arr, meio+1, final); // RECURSÃO -> vai dividindo a segunda metade do array
        intercala(arr, inicio, final, meio);
    }
}

int main()
{
    // Método dividir para consquistar + recursão
    int arr[N] = {12, 33, 21, 15, 95, 100, 9, 7, 54, 666};
    int inicio = 0, final = N-1; // posição 0 do array e a última posição
    
    mergeSort(arr, inicio, final); //chamo a função que vai organizar
    
    for(int i = 0; i < N; i++) //imprimir o array organizado
    {
        cout << arr[i] << "\t";
    }
}