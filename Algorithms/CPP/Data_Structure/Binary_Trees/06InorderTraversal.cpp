#include<iostream>
#include<stack>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void inorderTraversal(Node* root){

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);

}

void inorderTraversal_iterative(Node* root){
  
  stack<Node*> s;
  Node* current = root;

  while(current || !s.empty()){
    
    while(current){
      s.push(current);
      current = current->left;
    }

    current = s.top();
    s.pop();

    cout << current->data << " ";

    current = current->right;

  }

}

int main(void){

  Node* root = new Node(1);
  root->left = new Node(5);
  root->right = new Node(7);
  root->left->left = new Node(13);
  root->left->right = new Node(14);
  root->right->left = new Node(17);

  inorderTraversal_iterative(root);
  cout << endl;
  
  return 0;
}
