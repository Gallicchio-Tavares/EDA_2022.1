// O(n²)

#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for(int i = 0; i < n; i++) // O(n)
    {
        for(int j = 0; j < n; j++) // O(n)
        {
            cout << i << " x " << j << " = " << i*j << endl;
        }
        cout << "---------\n";
    }
    // Temos dois O(n), sendo que um está dentro do outro (nested for loop). Quando isso acontece, devemos
    // multiplicar as complexidades: n*n. Isso significa que temos uma complexidade de O(n²). 
}