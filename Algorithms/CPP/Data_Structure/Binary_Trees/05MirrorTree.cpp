#include<iostream>
#include<queue>

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

void levelOrderTraversal(Node* root){
  
  if(!root)
    return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();

    cout << front->data << " ";
   
    if(front->left)
      q.push(front->left);
    
    if(front->right)
      q.push(front->right);
  }
}

void inorderTraversal(Node* root){

  if(!root)
    return;

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void mirrorTree(Node* root, Node** mirror){
  if(!root){
    *mirror = NULL;
    return;
  }

  *mirror = new Node(root->data);
  mirrorTree(root->left, &(*mirror)->right);
  mirrorTree(root->right, &(*mirror)->left);
}

int main(void){
  
  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(6);
  root->left->left = new Node(2);
  root->left->right = new Node(4);

  inorderTraversal(root);
  cout << endl;

  Node* r;

  mirrorTree(root, &r);

  inorderTraversal(r);
  cout << endl;

  return 0;
}
