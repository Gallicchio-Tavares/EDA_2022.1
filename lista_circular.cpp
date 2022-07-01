#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

struct Node *tail; // aponta pro final, ao inves do inicio

void imprimir() // O(n)
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

void inserirInicio(int x) // O(1)
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

void inserirFinal(int x) // 0(1)
{
    Node *temp = criarNode(x);
    if(tail == NULL) // se a lista estiver vazia
    {
        tail = temp;
        return;
    }
    temp->next = tail->next; // o temp agr tem q apontar pro primeiro
    tail->next = temp; // o que antes era o ultimo agr aponta pro meu novo nó
    tail = tail->next; // tail agr aponta pro meu novo último nó
}

void inserirMeio(int valor, int posicao) // O(n)
{
    if(posicao == 1)
    {
        inserirInicio(valor);
        return;
    }
    Node *temp1 = criarNode(valor);
    Node *temp2 = tail->next;
    while(posicao-1 > 1)
    {
        temp2 = temp2->next;
        posicao--;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    if(temp2 == tail)
    {
        tail = tail->next;
    }
}

void deletarInicio()
{
    if(tail == NULL) // se a lista estiver vazia
    {
        cout << "A lista já está vazia!\n";
        return;
    }
    if(tail->next == tail) // se só tiver 1 elemento na lista
    {
        delete tail; // desalocar a memoria
        tail = NULL; // tail agr tá vazio
        return; // saio da função
    }
    Node *temp = tail->next; // temp tem q ser o primeiro nó
    tail->next = temp->next; // tail tem q apontar pro segundo nó
    delete temp;
}

void deletarFinal()
{
    if(tail == NULL) // se a lista estiver vazia
    {
        cout << "A lista já está vazia!\n";
        return;
    }
    if(tail->next == tail) // se só tiver 1 elemento na lista
    {
        delete tail; // desalocar a memoria
        tail = NULL; // tail agr tá vazio
        return; // saio da função
    }
    Node *temp = tail->next;
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    delete tail;
    tail = temp;

}

void inserirMeio(int valor, int posicao) // O(n)
{
    if(posicao == 1)
    {
        inserirInicio(valor);
        return;
    }
    Node *temp1 = criarNode(valor);
    Node *temp2 = tail->next;
    while(posicao-1 > 1)
    {
        temp2 = temp2->next;
        posicao--;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    if(temp2 == tail)
    {
        tail = tail->next;
    }
}

int main() 
{
  tail = NULL;
  
  inserirInicio(10); inserirInicio(20); inserirInicio(30); inserirInicio(40); inserirInicio(50);
  imprimir(); // 50 40 30 20 10
  inserirFinal(5); inserirFinal(6);
  imprimir(); // 50 40 30 20 10 5 6
  inserirMeio(100, 1); inserirMeio(200, 2); inserirMeio(400, 8);
  imprimir();  // 100 200 50 40 30 20 10 400 5 6
  deletarInicio(); deletarInicio(); deletarInicio();
  imprimir();  // 40 30 20 10 400 5 6  
  deletarFinal(); 
  imprimir(); // 40 30 20 10 400 5
  deletarMeio(1); deletarMeio(2); deletarMeio(4);
  imprimir(); // 30 10 400
}

