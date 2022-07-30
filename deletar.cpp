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

Node *achaMin(Node *root) 
{ 
  Node *atual = root;     
  while (atual->left != NULL) { 
    atual = atual->left;
  }
  return atual; 
}

Node *deletar(Node *root, int valor)
{
  if(root == NULL) return root;
  else if(valor < root->data) root->left = deletar(root->left, valor);
  else if(valor > root->data) root->right = deletar(root->right, valor);
  else
  {
    // caso 1: sem filhos
    if(root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
      return root;
    }
    // caso 2: 1 filho
    else if(root->left == NULL)
    {
      Node *temp = root;
      root = root->right;
      delete temp;
      return root;
    }
    else if(root->right == NULL)
    {
      Node *temp = root;
      root = root->left;
      delete temp;
      return root;
    }
    else { // caso 3: 2 filhos
      Node *temp = achaMin(root->right);
      root->data = temp->data;
      delete temp;
    }
  }
  return root;
}

int main()
{
  int num;
  Node *root = NULL;
  
  insert(root, 10); insert(root, 15); insert(root, 5); insert(root, 4); insert(root, 8); insert(root, 12);
  cout << "Que valor vc quer remover? ";
  cin >> num;
  root = deletar(root, num);
}
