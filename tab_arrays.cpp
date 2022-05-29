#include <iostream>
using namespace std;
#define N 10

void insert(int arr[])
{
    int i, aux, num, indice;
    cout << "Qual numero vc quer inserir e em qual posição? ";
    cin >> num;
    cin >> indice;
    indice--; // pensando que o usuario começa a lista na posição 1, e não na 0.
    if(indice > N-1)
    {
        cout << "Voce excedeu o valor possível para o índice.\n";
    }
    else
    {
        for(i = indice; i < N; i++) // faz as trocas
        {
            aux = arr[i]; 
            arr[i] = num;
            num = aux;
        }
    }
}

void search(int arr[])
{
    int num, indice = 0;
    cout << "Qual número você procura? ";
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
}

void remove(int arr[])
{
    int num;
    cout << "Que número você quer remover? ";
    cin >> num;
    int i;
    for(i = 0; i < N; i++)
    {
        if(arr[i] == num)
        {
            arr[i] = 0;
        }
    }
}

int main()
{
   int array[N] = {12, 29, 3, 1, 45}; // vai preencher os outros 5 espaços com 0.
   int opcao = -1;
   
   while(opcao != 0)
   {
       cout << "\n    TABELA\n--------------\n[1] Inserir elemento\n[2] Remover elemento\n[3] Imprimir array\n[4] Buscar elemento\n[0] Sair\n";
       cin >> opcao;
       if(opcao == 1)
       {
           insert(array);
       }
       else if(opcao == 2)
       {
           remove(array);
       }
       else if(opcao == 3)
       {
           for(int i = 0; i < N; i++)
           {
               cout << array[i] << "\t";
           }
           cout << endl;
       }
       else if(opcao == 4)
       {
           search(array);
       }
   }
   
}
