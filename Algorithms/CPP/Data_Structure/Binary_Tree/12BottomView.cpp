#include<iostream>
#include<map>
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

vector<int> bottomView(Node* root){
  vector<int> ans;

  if(!root)
    return ans;

  map<int, int> bottomNode;
  queue<pair<Node*, int>> q;

  q.push(make_pair(root, 0));

  while(!q.empty()){
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;
    
    bottomNode[hd] = frontNode->data;

    if(frontNode->left)
      q.push(make_pair(frontNode->left, hd - 1));

    if(frontNode->right)
      q.push(make_pair(frontNode->right, hd + 1));
  }

  for(auto x: bottomNode){
    ans.push_back(x.second);
  }

  return ans;
}

int main(void){
  
  Node* root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(5);
  root->left->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(25);
  root->left->right->left = new Node(10);
  root->right->left->right = new Node(14);

  vector<int> ans = bottomView(root);

  for(auto x: ans)
    cout << x << " ";
  cout << endl;


  return 0;
}
