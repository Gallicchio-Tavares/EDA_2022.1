// Selection Sort
#include <iostream>
using namespace std;
#define N 5
/*
quando i=0 e entramos no for do j, vamos comparar todos os numeros no array com o num na primeira posição.
nesse exemplo, o computador decide que o num na posição 2 é o menor de todos, ent fica na var "menor".
saindo desse "for", então, a var auxiliar guarda o antigo valor em i e colocamos o menor valor em i.
Depois, colocamos esse antigo valor onde estava o valor menor, para não perde-lo.
Agora vamos comparar o num seguinte com todos os que estão adiante dele, sem ter que olhar pro menor de todos dnv.
== Mais otimizado que o Bubble.
*/
void cres(int arr[])
{
    int aux, menor;
    for(int i = 0; i < N - 1; i++)
    {
        menor = i; // admito que o primeiro é o menor
        for(int j = i+1; j < N; j++)
        {
            if(arr[menor] > arr[j]) // se o "menor" for maior que o num em questao, esse num passa a ser o menor
            {
                menor = j;
            }
        }
        aux = arr[i]; // auxiliar recebe o num em i
        arr[i] = arr[menor]; // a posição i recebe o menor
        arr[menor] = aux; // o menor recebe o que estava antes em i
    }
    for(int a = 0; a < N; a++)
    {
        cout << arr[a] << endl;
    }
}
void decres(int arr[])
{
    int aux, maior;
    for(int i = 0; i < N - 1; i++)
    {
        maior = i; // admito que o primeiro é o maior
        for(int j = i+1; j < N; j++)
        {
            if(arr[maior] < arr[j]) // se o "maior" for maior que o num em questao, esse num passa a ser o maior
            {
                maior = j;
            }
        }
        aux = arr[i]; // auxiliar recebe o num em i
        arr[i] = arr[maior]; // a posição i recebe o maior
        arr[maior] = aux; // o maior recebe o que estava antes em i
    }
    for(int a = 0; a < N; a++)
    {
        cout << arr[a] << endl;
    }
}

int main()
{
    int arr[N] = {12, 21, 1, 5, 6};
    int opcao;

    cout << "[1] Ordem crescente\n[2] Ordem decrescente\n";
    cin >> opcao;
    cout << "--------------\n";
    if(opcao == 1)
    {
        cres(arr);
    }
    else if(opcao == 2)
    {
        decres(arr);
    }
}