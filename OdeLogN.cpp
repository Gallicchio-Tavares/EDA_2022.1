// O(log n)

#include <iostream>
using namespace std;
#define N 5

// aplicável a funções recursivas, iterativas, etc. Aqui um exemplo com a busca binária:

int main()
{
    int menor = 0, maior = N-1, valor;
    int arr[N] = {12, 32, 55, 76, 89}; // array já organizado, senão dá ruim.

    cout << "Qual número você procura? ";
    cin >> valor;

    while(menor <= maior)
    {
        int meio = (menor + maior)/2;
        int i = 0;
        i++;
        if(arr[meio] == valor)
        {
            cout << "YAY! O número " << valor << " está na posição " << i+1 << endl;
            break;
        }
        else if(arr[meio] < valor)
        {
            menor = meio + 1;       
        }
        else if(arr[meio] > valor)
        {
            maior = meio - 1;
        }
        else
            cout << "Que pena! " << valor << " não está no array.\n";
    }
}

