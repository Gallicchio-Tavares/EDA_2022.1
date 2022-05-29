#include <iostream>
using namespace std;

int main()
{
    int a, * p;
    a = 5;
    p = &a;
    //cout<< a << endl; // vai mostrar "5" normalmente.
    //cout <<  &a << endl; // mostra o endereço 
    cout << "O endereço de p é " << p << endl; // mostra o endereço -> 140737488346188 (conversão do valor em hexadecimal)
    cout << "O valor no endereço p é " << *p << endl; // como p é um ponteiro que recebeu o que está em a, mostra "5".
    cout << "O tamanho do inteiro é de " << sizeof(int) << " bytes.\n";
    cout << "Endereço de p+1 é " << p+1 << endl; // 140737488346192 -> esse endereço tem 4 bytes a mais que o anterior. mostra o prox end
    cout << "O valor no endereço p+1 é " << *(p+1) << endl; // vai mostrar um valor aleatorio q n existe de fato
    cout << "\n";
    
    char b;
    char *q;
    b = 'b';
    q = &b; 

    cout << "O endereço de q é " << q << endl; 
    cout << "O caracter no endereço p é " << *q << endl; 
    cout << "O tamanho do caracter é de " << sizeof(char) << " bytes.\n";
    cout << "Endereço de p+1 é " << q+1 << endl; 
    cout << "O caracter no endereço p+1 é " << *(q+1) << endl; 
    cout << "\n";
    
    float c;
    float *r;
    c = 3.14;
    r = &c;

    cout << "O endereço de r é " << r << endl; 
    cout << "O valor no endereço r é " << *r << endl; 
    cout << "O tamanho do float é de " << sizeof(float) << " bytes.\n";
    cout << "Endereço de r+1 é " << r+1 << endl; 
    cout << "O valor no endereço r+1 é " << *(r+1) << endl; 

}