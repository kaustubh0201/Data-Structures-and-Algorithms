#include<iostream>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

// Method 1: One method is to use the height function and then using that to find the diameter

int heightTree(Node* root){
  
  if(!root)
    return 0;

  int lheight = heightTree(root->left);
  int rheight = heightTree(root->right);

  return max(lheight, rheight) + 1;

}

int diameterTree(Node* root){
  
  if(!root)
    return 0;

  int leftSubTree = diameterTree(root->left);
  int rightSubTree = diameterTree(root->right);

  int fromRoot = heightTree(root->left) + heightTree(root->right) + 1;

  return max(leftSubTree, max(rightSubTree, fromRoot));
}

// Method 2: calculating the height and the diameter in the same function

// first -> diameter ; second -> height 
pair<int, int> diameterTree_same(Node* root){

  if(!root)
    return make_pair(0, 0);
  
  pair<int, int> ltree = diameterTree_same(root->left);
  pair<int, int> rtree = diameterTree_same(root->right);

  int diameterLTree = ltree.first;
  int diameterRTree = rtree.first;
  int fromTop = ltree.second + rtree.second + 1;

  pair<int, int> ans;

  ans.first = max(diameterLTree, max(diameterRTree, fromTop));
  ans.second = max(ltree.second, rtree.second) + 1;

  return ans;

}

int diameter(Node* root){
  return diameterTree_same(root).first;
}

int main(void)
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);


  cout << diameterTree(root) << endl;

  cout << diameter(root) << endl;

  return 0;
}
