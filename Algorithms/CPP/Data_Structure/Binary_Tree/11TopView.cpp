#include<iostream>
#include<queue>
#include<map>

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

vector<int> topView(Node* root){
  
  vector<int> ans;
  if(!root)
    return ans;

  map<int, int> topNode;
  queue<pair<Node*, int>> q;

  q.push(make_pair(root, 0));

  while(!q.empty()){
    pair<Node*, int> temp = q.front();
    q.pop();
    
    Node* frontNode = temp.first;
    int hd = temp.second;

    if(topNode.find(hd) == topNode.end())
      topNode[hd] = frontNode->data;

    if(frontNode->left)
      q.push(make_pair(frontNode->left, hd - 1));

    if(frontNode->right)
      q.push(make_pair(frontNode->right, hd + 1));
  }

  for(auto x: topNode){
    ans.push_back(x.second);
  }

  return ans;

}

int main(void){
  
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(60);
  root->right->left = new Node(90);
  root->right->right = new Node(100);

  vector<int> ans = topView(root);

  for(auto x: ans)
    cout << x << " ";

  cout << endl;

  return 0;
}
