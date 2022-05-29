// sequencia de fibonacci

#include <iostream>
using namespace std;

int fib(int n) // inicialmente, quando o for do int main() começar a imprimir os valores, esse n = 1.
{
    if(n <= 2) // n = 1 vai entrar aqui. O primeiro numero da seq de fib é 1. Dps o for diz n = 2. tb entra aqui: o segundo num da seq é 1.
    {
        return 1;
    }
    else // n = 3 entra aqui. fib(n-1) vai chamar n = 2 (ideia de recursão: esse n=2 vai entrar no primeiro if dessa função), que é 1; 
    {    // fib(n-2) vai chamar n = 1, que é 1. Somamos: 1 + 1 = 2. Terceiro num da seq de fib.
        return (fib(n-1)+fib(n-2));
    }   // n = 4 -> fib(n-1) vai chamar n = 3, que vai chamar fib(n-1) e fib(n-2) que é 1+1=2; fib(n-2) vai chamar n = 2, que é 1. 2 + 1 = 3: quarto num da seq de fib 
}

int main()
{
    int n;

    cout << "Quantos números da sequência de Fibonacci você quer ver? ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << fib(i+1) << ", ";
    }
    cout << "FIM.\n";
    return 0;
}