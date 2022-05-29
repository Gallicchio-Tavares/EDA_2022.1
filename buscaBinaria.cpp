// busca binária

#include <iostream>
using namespace std;
#define N 5

void bubble(int arr[])
{
    int aux;
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(arr[j] < arr[i])
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void busca(int num, int arr[], int inicio, int fim)
{
    int meio = (inicio + fim)/2; // inicialmente. inicio = 0 e fim = 5.
    if(num == arr[meio]) 
    {
        cout << "O número " << num << " está na posição " << meio + 1 << ".\n";
    }
    else if(num < arr[meio]) 
    {
        fim = meio - 1; // meio = 2, de inicio. Agr, fim passa a ser 1, para verificar os números menores que o meio.
        busca(num, arr, inicio, fim);
    }
    else if(num > meio)
    {
        inicio = meio + 1; // meio = 2, inicialmente. Agr, inicio passa a ser 3, verificando os números maiores que o meio.
        busca(num, arr, inicio, fim); 
    } 
}

int main()
{
    int arr[N] = {32, 22, 76, 89, 6}; // ordenado vai ficar {6, 22, 32, 76, 89}
    int num;

    cout << "Que número você quer procurar? ";
    cin >> num;

    bubble(arr);
    busca(num, arr, 0, N);
}
