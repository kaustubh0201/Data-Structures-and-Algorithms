#include<iostream>
#include<vector>

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

void solveRightView(Node* root, vector<int> &ans, int level){

  if(!root)
    return;

  if(level == ans.size()){
    ans.push_back(root->data);
  }

  solveRightView(root->right, ans, level + 1);
  solveRightView(root->left, ans, level + 1);
}

vector<int> RightView(Node* root){

  vector<int> ans;
  solveRightView(root, ans, 0);
  return ans;
}

int main(void){

  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(60);

  vector<int> ans = RightView(root);

  for(auto x: ans)
    cout << x << " ";
  cout << endl;

  return 0;
}
