#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head; // var global

void imprimir()
{
    Node *temp = head;
    cout << "A partir da frente: ";
    if(temp == NULL)
    { 
        cout << "Lista vazia!\n";
        return;
    }
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void imprimirReverso()
{
    Node *temp = head;
    if(temp == NULL)
    { 
        cout << "Lista vazia!\n";
        return;
    }
    while(temp->next != NULL) // indo pro ultimo nó
    {
        temp = temp->next;
    }
    cout << "De trás pra frente: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev; // indo do ultimo pro primeiro, usando o prev.
    }
    cout << endl;
}

struct Node* criarNode(int x) // criamos um novo nó no Heap pra ele não ser apagado quando a funcao sair do stack frame
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void inserirInicio(int x) // inserir no inicio
{
    Node *temp = criarNode(x);
    if(head == NULL)
    {
        head = temp;
        return; 
    }
    head->prev = temp; // o head é atualmente o primeiro. ent, o end prev dele deve apontar pro que agr ficará no inicio.
    temp->next = head; // ajustando a conexao: o temp agr precisa apontar pro no que estava no Head
    head = temp; // agr head é esse novo nó temp.
}
/*
int inserirFinal(int x) // inserir no final
{ 
    
}
*/
void deletar() // deletar elemento do inicio
{
    Node *temp;
    temp = head;
    head = temp->next;
    temp->prev = NULL;
    free(temp);
}

int main()
{
    head = NULL; // começa vazia
    int opcao = -1, num;
    while(opcao != 0)
    {
        cout << "[0] sair\n[1] inserir início\n[2] imprimir\n[3]imprimir reverso\n[4] deletar primeiro Node\n[5]inserir final\n";
        cin >> opcao;

        if(opcao == 1)
        {
            cout << "Digite um numero: ";
            cin >> num;
            inserirInicio(num);
            cout << endl;
        }
        else if(opcao == 2)
        {
            imprimir();
            cout << endl;
        }
        else if(opcao == 3)
        {
            imprimirReverso();
            cout << endl;
        }
        else if(opcao == 4)
        {
            deletar();
        }
    }
}
