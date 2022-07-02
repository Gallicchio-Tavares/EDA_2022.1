#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *tail;

void imprimir()
{
  if(tail == NULL)
  {
    cout << "Lista vazia!\n";
    return;
  }
  Node *temp = tail->next;
  do{
    cout << temp->data << " ";
    temp = temp->next;
  }while(temp != tail->next);
  cout << endl;
}

struct Node* criarNode(int x) // generalizar a criação de um nó em uma função só
{
    Node* novoNode = new Node;
    novoNode->data = x;
    novoNode->next = novoNode;
    novoNode->prev = novoNode;
    return novoNode;
}

void inserirInicio(int x)
{
  Node *temp1 = criarNode(x);
  if(tail == NULL) // lista vazia
  {
    tail = temp1;
    return;
  }
  struct Node *temp2 = tail->next; // temp2 é o primeiro nó.
  temp1->prev = tail; // o prev do nó a ser inserido precisa apontar pro último elemento.
  temp1->next = temp2; // o next do nó a ser inserido precisa apontar pra o q antes era o primeiro nó.
  temp2->prev = temp1; // o primeiro nó agr é temp1, então o prev de temp2 precisa apontar pra ele.
  tail->next = temp1; // o último nó precisa apontar pro primeiro (temp1).
}

void inserirFinal(int x)
{
  Node *temp1 = criarNode(x); // novo nó
  if(tail == NULL) // lista vazia
  {
    tail = temp1;
    return;
  }
  Node *temp2 = tail->next; // auxiliar
  temp1->prev = tail; // prev do novo precisa apontar pro q era o último
  temp1->next = temp2; // next do novo tem q apontar pro primeiro nó
  tail->next = temp1; // o q antes era o último agr tem q apontar pro novo
  temp2->prev = temp1; // 
  tail = temp1; // tail tem q ser, agr, o último nó
}

int main() 
{
  tail = NULL;

  inserirInicio(1); inserirInicio(7); inserirInicio(14);
  imprimir();
  inserirFinal(55); inserirFinal(48);
  imprimir();
}
