// InsertionSort - Bianca Gallicchio Tavares

#include <iostream>
using namespace std;
#define N 5

void insertion(int arr[])
{
    int j, chave; // chave -> variável intermediária que vai guardar a posição de i
    for(int i = 1; i < N; i++)
    {
        chave = arr[i];
        for(j = i-1; j >= 0 && arr[j] > chave; j--) // j vai ser o último elemento do array
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = chave;
    }
}

int main()
{
    int arr[N] = {35, 21, 90, 88, 10};
    insertion(arr);
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
