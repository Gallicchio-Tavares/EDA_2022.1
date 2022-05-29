// Busca de um elemento do array

#include <iostream>
using namespace std;
#define N 10

int main()
{
    int arr[N] = {12, 54, 9, 8, 1, 0, 22, 49, 91, 100};
    int num, indice = 0;
    cout << "Que número você está procurando? ";
    cin >> num;
    for(int i =0; i < N; i++)
    {
        if(arr[i] == num)
        {
            cout << "O número " << num << " está na posição " << i + 1 << " do array.\n";
            indice++; // vai incrementar a minha variavel pra não mostrar a mensagem ali embaixo
        }
    }
    if(indice == 0) // mostra se o numero nao está no array.
    {
        cout << "Que pena! O número " << num << " não está no array.\n";
    }
    return 0;
}
