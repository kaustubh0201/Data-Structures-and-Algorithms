#include<iostream>
#include<stack>

using namespace std;

struct Node{
  
  int data;
  Node *left, *right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

int findIndex(string str, int si, int ei){
  
  if(si > ei)
    return -1;

  stack<char> s;

  for(int i = si; i <= ei; i++){
    if(str[i] == '('){
      
      s.push(str[i]);
    
    }else if(str[i] == ')'){
      
      if(s.top() == '('){
        s.pop();
      }

      if(s.empty()){
        return i;
      }
    }
  }

  return -1;
}

Node* makeBinaryTree(string s, int si, int ei){
  
  if(si > ei)
    return NULL;

  Node* root = new Node(s[si] - '0');
  
  int index = -1;

  if(s[si + 1] == '(' and si + 1 <= ei){
    
    index = findIndex(s, si + 1, ei);

  }

  if(index != -1){
    root->left = makeBinaryTree(s, si + 2, index - 1);

    root->right = makeBinaryTree(s, index + 2, ei - 1);
  }

  return root;
}

void inorderTraveral(Node* root){
  
  if(!root)
    return;

  inorderTraveral(root->left);
  cout << root->data << " ";
  inorderTraveral(root->right);

}

int main(void){

  string s = "4(2(3)(1))(6(5))";

  Node* root = makeBinaryTree(s, 0, s.length() - 1);

  inorderTraveral(root);
  cout << endl;

  return 0;
}
