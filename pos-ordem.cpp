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

void posOrder(Node *root) // O(n)
{
  if (root == NULL)
    return;
  preOrder(root->left); // recursão, começo com o da esquerda
  preOrder(root->right);
  cout << root->data << " "; // imprimo o primeiro
}

int main()
{
  Node *root = NULL;
  
  insert(root, 10); insert(root, 15); insert(root, 5); insert(root, 4); insert(root, 8); insert(root, 12);
  posOrder(root);
}
