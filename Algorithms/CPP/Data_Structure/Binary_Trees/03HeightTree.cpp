#include<iostream>

using namespace std;

struct Node
{
  int data;
  Node* right;
  Node* left;

  Node(int data)
  {
    this->data = data;
    right = NULL;
    left = NULL;
  }
};

int height(Node* root)
{
  if(!root)
    return 0;

  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight > rheight)
    return lheight + 1;
  else
    return rheight + 1;
}

int main(void)
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout << height(root) << endl;

  return 0;
}
