#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *novoNode(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int data) // O(logn)
{
  if (root == NULL) {
    root = novoNode(data); 
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

bool buscar(Node *root, int data) // O(logn)
{
  if (root == NULL)
    return false; // arvore vazia, n tem o q buscar.
  else if (root->data == data)
    return true; // o num tá logo na raíz.
  else if (data <= root->data)
    return buscar(
        root->left,
        data); // vou checando os da esquerda. a recursão vai fazer com q
               // eventualmente eu caisa no segundo if desta função e retorne
               // true (se o numero estiver na árvore, no caso)
  else
    return buscar(root->right, data); // vou checando os da direita
}

int main()
{
  int num;
  Node *root = NULL;
  
  insert(root, 10); insert(root, 15); insert(root, 5); insert(root, 4); insert(root, 8); insert(root, 12);
  cout << "Que valor vc quer buscar? ";
  cin >> num;
  if (buscar(root, num) == true)
    cout << "O valor " << num << " está na árvore!\n";
  else
    cout << "Valor não foi encontrado\n\n";
}
