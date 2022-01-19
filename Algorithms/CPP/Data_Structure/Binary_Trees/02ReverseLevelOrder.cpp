#include<iostream>
#include<stack>
#include<queue>

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

Node* newNode(int data)
{
  Node* temp = new Node(data);

  return temp;
}

int height(Node* root);
void currentLevel(Node* root, int level);

void reverseLevelOrderTraversal(Node* root)
{
   int h = height(root);

   for(int i = h; i >= 1; i--)
     currentLevel(root, i);
}

void currentLevel(Node* root, int level)
{
  if(!root)
    return;

  if(level == 1)
  {
    cout << root->data << " ";
  }
  else if(level > 1)
  {
    currentLevel(root->left, level-1);
    currentLevel(root->right, level-1);
  }
}

int height(Node* root)
{
  if(!root)
    return 0;

  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight > rheight)
    return lheight + 1;
  else
    return rheight + 1;
}

// We can also use the queue and stack to implement the reverse order traversal.  

//The idea is to use a deque(double-ended queue) to get the reverse level order. A deque allows insertion and deletion at both the ends. If we do normal level order traversal and instead of 
//printing a node, push the node to a stack and then print the contents of the deque, we get “5 4 3 2 1” for the above example tree, but the output should be “4 5 2 3 1”. So to get the correct sequence 
//(left to right at every level), we process children of a node in reverse order, we first push the right subtree to the deque, then process the left subtree.

void reverseOrderTraversal(Node* root)
{
  if(!root)
    return;

  queue<Node*> q;
  stack<Node*> s;

  q.push(root);

  while(!q.empty())
  {
    Node* temp = q.front();
    q.pop();
    s.push(temp);

    if(temp->right)
      q.push(temp->right);

    if(temp->left)
      q.push(temp->left);
  }

  while(!s.empty())
  {
    Node* temp = s.top();
    cout << temp->data << " ";
    s.pop();
  }
}

int main(void)
{
  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  reverseLevelOrderTraversal(root);

  cout << endl;

  return 0;
}
