// algoritmos de ordenação - BUBBLE SORT
#include <iostream>
using namespace std;
#define N 5
/* 
Serve para colocar elementos em ordem.  
Compara o primeiro c/ o segundo, o segundo c/ o terceiro... etc
*/

void crescente(int arr[])
{
    int aux;
    for(int i = 0; i < N - 1; i++) // vai só no 0, 1, 2 e 3. Não analisa a última pra n ser redundante
    {
        for(int j = i+1; j < N; j++) // analisa sempre um na frente do i, pra n ter redundância
        {
            if(arr[i] > arr[j]) // vai colocar em ordem CRESCENTE
            {
                aux = arr[i]; // auxiliar guarda o numero q estava na posição i inicial
                arr[i] = arr[j]; // se o num no j (1 seguinte ao i) for menor que em i, ele toma a posição de i.
                arr[j] = aux; // o numero que estava em i vai pro j.
            }
        }
    } // organizei tudo
    for(int a = 0; a < 5; a++)
    {
        cout << arr[a] << endl; // imprimir tudo
    }
}
void decrescente(int arr[])
{
    int aux;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(arr[i] < arr[j]) // decrescente
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    for(int a = 0; a < N; a++)
    {
        cout << arr[a] << endl;
    }
}

int main()
{
    int arr[N] = {15, 3, 20, 50, 5}; // variável composta homogenea -> reserva um espaço p/ armazenar dados na memoria
    int opcao;
    cout << "[1] Ordem crescente\n[2] Ordem decrescente\n";
    cin >> opcao;
    if(opcao == 1)
    {
        crescente(arr);
    }
    else if(opcao == 2)
    {
        decrescente(arr);
    }
    return 0;
}