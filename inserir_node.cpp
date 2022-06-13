// lista encadeada
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next; // vai guardar o endereço do próximo nó da lista
};
Node* head;

void inserir(int posicao, int valor)
{
    Node *temp1 = new Node(); // alocando memoria: a unica maneira de acessar dados na Heap é pelo ponteiro temp1
    temp1->data = valor; // inserindo o valor 
    temp1->next = NULL; // a posicao inicial
    if(posicao == 1) // se a posicao for no inicio
    {
        temp1->next = head; // o next passa a ter o NULL
        head = temp1; // o head agr aponta pro temp1
        return; // return pra sair dessa funcao inserir sem passar pelos de baixo.
    }
    Node *temp2 = head; // um novo nó vai receber o end q estava no head.
    for(int i = 0; i < posicao-2; i++) // se posicao = 1, nao entra aqui. se posicao = 2, nao entra aqui.
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; // nao mexemos no head pq ele continua certo.
    temp2->next = temp1;
}

void imprime()
{
    Node* temp = head; //começamos no endereço inicial, no topo: o head.
    cout << "\033[32mA lista é: \033[m";
    while(temp != NULL) // enquanto nao chegar no final...
    {
        cout << temp->data << " "; // ... imprime os dados.
        temp = temp->next; // assim que imprime um, passamos pro proximo endereço
    }
    cout << "\n";
}

int main()
{
    head = NULL;
    /*int num, posicao;
    cout << "Número a ser inserido: ";
    cin >> num;
    cout << "\n Posição: ";
    cin >> posicao;
    */
    inserir(1, 2); // lista: 2
    inserir(2, 3); // lista: 2 3
    inserir(1, 4); // lista: 4 2 3
    inserir(3, 5); // lista  4 2 5 3
    imprime();

}