#include <iostream>
#include <queue>
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

void levelOrder(Node *root) { // O(n)
  queue<Node *> fila;
  fila.push(root);
  // enquanto a fila não estiver vazia...
  while (!fila.empty()) {
    Node *atual = fila.front();
    cout << atual->data << " ";
    if (atual->left != NULL)
      fila.push(atual->left);
    if (atual->right != NULL)
      fila.push(atual->right);
    fila.pop(); // remover o elemento da frente
  }
  cout << endl;
}

int main()
{
  Node *root = NULL;
  
  insert(root, 10); insert(root, 15); insert(root, 5); insert(root, 4); insert(root, 8); insert(root, 12);
  levelOrder(root);
}
