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

int achaMin(Node *root) { // queremos andar pela esquerda até chegar no menor
  Node *atual = root;     // var temporaria
  int depth = 0;
  if (root == NULL) {
    cout << "ERRO, a árvore está vazia.\n";
    return -1;
  }
  while (atual->left != NULL) { // enquanto n chego no último...
    atual = atual->left;
    depth++;
  }
  cout << "Profundidade do menor valor: " << depth << "\n";
  return atual->data; // saio do loop, finalmente, depois de chegar no último
  // e retorno o valor menor da árvore.
}

int achaMax(Node *root) { // mesma logica do min, mas agr ficamos na direita
  Node *atual = root;
  int depth = 0;
  if (root == NULL) {
    cout << "ERRO, a árvore está vazia.\n";
    return -1;
  }
  while (atual->right != NULL) {
    atual = atual->right;
    depth++;
  }
  cout << "Profundidade do maior valor: " << depth << "\n";
  return atual->data;
}

int achaAltura(Node *root) { // O(logn)
  if (root == NULL) {
    return -1;
  }
  return max(achaAltura(root->left), achaAltura(root->right)) + 1;
}

int main()
{
  int num;
  Node *root = NULL;
  
  insert(root, 10); insert(root, 15); insert(root, 5); insert(root, 4); insert(root, 8); insert(root, 12);
  
  cout << "A altura da árvore é " << achaAltura(root) << "\n";
  cout << "O menor valor da árvore é " << achaMin(root) << "\n";
  cout << "O maior valor da árvore é " << achaMax(root) << "\n";
}
