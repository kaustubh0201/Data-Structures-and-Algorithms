#include<iostream>

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

pair<bool, int> isBalancedUtil(Node* root){

  if(!root){
    return make_pair(true, 0);
  }
  
  pair<bool, int> lTree = isBalancedUtil(root->left);
  pair<bool, int> rTree = isBalancedUtil(root->right);
  
  bool diff = abs(lTree.second - rTree.second) + 1;

  pair<bool, int> ans;

  if(lTree.first and rTree.first and diff){
    ans.first = true;
    ans.second = max(lTree.second, rTree.second) + 1;
  }else{
    ans.first = false;
  }

  return ans;
}

bool isBalanced(Node* root){
  
  return isBalancedUtil(root).first;

}

int main(void){
  
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(60);

  cout << isBalanced(root) << endl;

  return 0;
}
