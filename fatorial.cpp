// fatorial
// 5! = 5 x 4 x 3 x 2 x 1
// n! = n x n-1 x n-2 x ... n - (n-1)
#include <iostream>
using namespace std;

/*
int fatorial(int n) // método old school
{
    int fat = 1;
    for(int i = n; i > 0; i--)
    {
        fat *= i;
    }
    return fat;
}
*/

int fatorial(int num)
{
    if (num == 0)
        return 1;
    else
        return(num * fatorial(num - 1)); // método da recursão
}

int main()
{
    int n;
    cout << "Deseja calcular o fatorial de qual número?\n";
    cin >> n;
    if(n < 0)
    {
        cout << "Número inválido.\n";
    }
    else 
    {
        cout << "O fatorial de " << n << " é " << fatorial(n) << endl;
    }
}