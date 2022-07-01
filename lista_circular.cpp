#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

struct Node *tail;

void imprimir()
{
  Node *temp = tail->next; 
  do
    {
      cout << temp->data << " ";
      temp = temp->next;
    } while(temp != tail->next);
  cout << endl;
}

struct Node* criarNode(int x) // generalizar a criação de um nó em uma função só
{
    Node* novoNode = new Node;
    novoNode->data = x;
    novoNode->next = novoNode;
    return novoNode;
}

void inserir(int x)
{
  Node *temp = criarNode(x);
  if(tail == NULL) // se a lista estiver vazia
  {
    tail = temp;
    return;
  }
  temp->next = tail->next; // se não está vazia, o temp passa a apontar pro primeiro
  tail->next = temp; // o ultimo agr aponta pro temp, q virou o primeiro
}

int main() 
{
  tail = NULL;
  
  inserir(10);
  imprimir(); // 10
  inserir(20);
  imprimir(); // 20 10
  inserir(30);
  imprimir(); // 30 20 10
  inserir(40);
  inserir(50);
  imprimir(); // 50 40 20 10
}
