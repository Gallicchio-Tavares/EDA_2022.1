// Busca sequencial (não é o meu)

#include <iostream>
using namespace std;
#define T 7

void sequencial(int arr[], int x)
{
    bool achei = false;
    int i = 0;

    while(!achei && i<T) // esse i<T serve pra sair do loop caso o num procurado n esteja no array.
    {
        if(arr[i]==x) // achou? entao mostra a posição e sai do loop while.
        {
            achei = true;
            cout << "Achei! O número está na posição: " << i+1;
            cout << endl;
        }
        else i++; // não achou? então soma e vai pro próximo.
    }
    if(i == T)
    {
        cout << "Número não encontrado.\n";
    }
}

int main()
{
    int num, arr[T] = {15,30,25,12,50,10,9};

    cout << "Numero a ser encontrado: ";
    cin >> num;
    sequencial(arr, num);
    return 0;
}