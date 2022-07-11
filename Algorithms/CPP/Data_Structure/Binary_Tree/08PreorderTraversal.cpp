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

void preorderTraversal(Node* root){
  
  if(!root)
    return;

  cout << root->data << " ";

  preorderTraversal(root->left);
  preorderTraversal(root->right);
  
}

void preorderTraversal_iterative(Node* root){

  stack<Node*> s;
  s.push(root);

  while(!s.empty()){
    
    Node* top = s.top();
    s.pop();

    cout << top->data << " ";

    if(top->right)
      s.push(top->right);

    if(top->left)
      s.push(top->left);

  }

}


int main(void){
  
  Node* root = new Node(1);
  root->left = new Node(5);
  root->right = new Node(7);
  root->left->left = new Node(13);
  root->left->right = new Node(14);
  root->right->left = new Node(17);

  preorderTraversal(root);
  cout << endl;

  preorderTraversal_iterative(root);
  cout << endl;

  return 0;
}
