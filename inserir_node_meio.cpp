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

void inserir(int valor, int posicao)
{
  Node *temp1 = new Node();
  temp1->data = valor;
  temp1->next = NULL;
  temp1->prev = NULL;
  if(posicao == 1)
  {
    temp1->next = head;
    head = temp1;
    return;
  }
  Node *temp2 = head;
  for(int i = 0; i < posicao - 2; i++)
    {
      temp2 = temp2->next;
    }
  temp1->next = temp2->next;
  temp2->next = temp1;
  temp1->prev = temp2;
}

int main()
{
  inserir(1, 1);
  imprimir(); // 1
  inserir(2, 1); 
  imprimir(); // 2 1
  inserir(3, 3);
  imprimir(); // 2 1 3
  inserir(5, 2);
  imprimir(); // 2 5 1 3
}
