// O(n)

#include <iostream>
#include <cmath>
using namespace std;

void linear(int num)
{
    for(int i = 0; i < num; i++) // esse for que faz com que a função seja O(n). É a quantidade de comparações que vai aumentar a escala
    {                            
        cout << 1000 * 100000 << endl; // essa linha sempre vai mostrar o mesmo resultado. É uma constante: O(1).
    }
}

int main()
{
    cout << "O(n):\n";
    int num = 7;
    linear(num); 
}