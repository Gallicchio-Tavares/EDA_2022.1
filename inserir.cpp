#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* novoNode(int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* inserir(Node *root, int data) // O(logn)
{
  // há 3 casos: árvore vazia, 
  // num q quero inserir é menor que o da raíz
  // num q quero inserir é maior que o da raíz.
  if(root == NULL)
  {
    root = novoNode(data); // agr vou apontar pro novo end da raíz
    return root;
  }
  else if(data <= root->data){
    root->left =  inserir(root->left, data); // recursão
  }
  else{
    root->right = inserir(root->right, data);
  }
  return root;
}

int main()
{
  Node *root = NULL; // ponteiro que guarda o end da raíz, começa vazia
  root = inserir(root, 10);
  root = inserir(root, 6);
  root = inserir(root, 8);
  root = inserir(root, 15);
  root = inserir(root, 20);
  root = inserir(root, 1);
}
  
