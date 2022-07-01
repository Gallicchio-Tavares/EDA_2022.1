#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

struct Node *tail; // aponta pro final, ao inves do inicio

void imprimir() // O(n)
{
  if(tail == NULL)
    return;
  Node *temp = tail->next; 
  do 
    {
      cout << temp->data << " ";
      temp = temp->next;
    } while(temp != tail->next);
  cout << endl;
}

int quantNode() // O(n)
{
  int cont = 0;
  if(tail == NULL) return cont;
  else
  {
    Node *temp = tail->next;
    while(temp != tail)
    {
      temp = temp->next;
      cont++;
    }
    cont++;
    return cont;
  }
}

int buscar(int x) // O(n)
{
  struct Node *temp;
  int index = 0;
  if(tail == NULL)
  {
    return -2;
  }
  temp = tail->next;
  do{
    if(temp->data == x) return index;
    temp = temp->next;
    index++;
  }while(temp != tail->next);
  return -1;
}

struct Node* criarNode(int x) // generalizar a criação de um nó em uma função só
{
    Node* novoNode = new Node;
    novoNode->data = x;
    novoNode->next = novoNode;
    return novoNode;
}

void inserir(int x) // O(1)
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

void deletar(int posicao) // O(n)
{
  int quant = quantNode();
  
  if(tail == NULL) // se a lista estiver vazia
  {
    cout << "A lista já está vazia!\n";
    return;
  }
  if(quant < posicao)
  {
    cout << "Posição inválida!\n";
    return;
  }
  if(tail->next == tail) // se só tiver 1 elemento na lista
  {
    delete tail; // desalocar a memoria
    tail = NULL; // tail agr tá vazio
    return; // saio da função
  }
  Node *temp = tail->next; // começar no início
  if(posicao == 1)
  {
    tail->next = temp->next;
    return;
  }
  for(int i = 0; i < posicao - 2; i++)
  {
    temp = temp->next; // temp vai ser o nó logo atrás do q eu quero apagar
  }
  Node *apagar = temp->next; // temp->next tem o end que eu quero apagar
  temp->next = apagar->next;
  if(apagar == tail) // se o nó for o último
  {
    tail = temp; // tem q atualizar o temp
  }
  delete apagar;
  apagar = NULL;
}


int main() 
{
  tail = NULL;
  int opcao, num, pos, quant;
  do{
    cout << "\n[0] sair\n[1] adicionar elemento\n[2] deletar elemento\n[3] imprimir lista\n[4] contar elementos\n[5] buscar elemento\n";
    cin >> opcao;
    if(opcao == 1)
    {
      cout << "Insira um número: ";
      cin >> num;
      inserir(num);
    }
    else if(opcao == 2)
    {
      cout << "Insira a posição: ";
      cin >> pos;
      deletar(pos);
    }
    else if(opcao == 3)
      imprimir();
    else if(opcao == 4)
    {
      quant = quantNode();
      cout << "Há " << quant << " elementos na lista\n";
    }
    else if(opcao == 5)
    {
      cout << "Insira o número a ser buscado: ";
      cin >> num;
      int i = buscar(num);
      if(i == -1) cout << "Elemento não encontrado!\n";
      else if(i == -2) cout << "Lista vazia!\n";
      else cout << num << " está na posição " << i << "\n";
    }
  } while(opcao != 0);

  cout << "\033[33mAté mais!\033[m\n";
  
}
