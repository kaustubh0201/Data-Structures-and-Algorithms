#include<iostream>
#include<queue>
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

vector<int> zigzagTraversal(Node* root){
  
  vector<int> result;

  if(!root){
    return result;
  }

  queue<Node*> q;
  q.push(root);

  bool leftToRight = true;

  while(!q.empty()){
    
    int n = q.size();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
      Node* temp = q.front();
      q.pop();
      
      (leftToRight) ? ans[i] = temp->data : ans[n - 1 - i] = temp->data;

      if(temp->left)
        q.push(temp->left);

      if(temp->right)
        q.push(temp->right);
    }

    for(int i = 0; i < n; i++)
      result.push_back(ans[i]);

    leftToRight = !leftToRight;
  }

  return result;

}

int main(void){

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);

  vector<int> ans = zigzagTraversal(root);

  for(auto x: ans)
    cout << x << " ";
  cout << endl;

  return 0;
}
