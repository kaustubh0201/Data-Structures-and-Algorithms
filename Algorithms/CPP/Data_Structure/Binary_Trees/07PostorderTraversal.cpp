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

void postorderTraversal(Node* root){
  
  if(!root)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);

  cout << root->data << " ";

}

void postorderTraversal_iterative(Node* root){

  stack<Node*> s;
  s.push(root);
  Node* current = NULL;
  Node* previous = NULL;

  while(!s.empty()){
    current = s.top();

    if(!previous or previous->right == current or previous->left == current){
      if(current->left)
        s.push(current->left);
      else if(current->right)
        s.push(current->right);
      else{
        cout << current->data << " ";
        s.pop();
      }
    }

    else if(current->left == previous){
      if(current->right)
        s.push(current->right);
      else{
        cout << current->data << " ";
        s.pop();
      }
    }

    else{
      cout << current->data << " ";
      s.pop();
    }

    previous = current;
  }

}

int main(void){
  
  Node* root = new Node(1);
  root->left = new Node(5);
  root->right = new Node(7);
  root->left->left = new Node(13);
  root->left->right = new Node(14);
  root->right->left = new Node(17);
  
  postorderTraversal(root);
  cout << endl;

  postorderTraversal_iterative(root);
  cout << endl;

  return 0;
}
