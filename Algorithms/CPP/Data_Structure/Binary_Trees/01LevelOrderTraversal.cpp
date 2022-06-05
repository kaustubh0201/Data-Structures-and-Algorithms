#include<iostream>
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

// for printing the curent level 
void currentLevel(Node* root, int level);

// height of the tree from that particular node 
int height(Node* root);

// for making a new node for the binary tree
Node* newNode(int data);

void levelOrderTraversal(Node* root)
{
  int h = height(root);

  for(int i = 1; i <= h; i++)
  {
    currentLevel(root, i); // the i is basically telling how much down the tree we have to go for printing
  }
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
    currentLevel(root->left, level - 1);
    currentLevel(root->right, level - 1);
  }
}

int height(Node* root)
{
  if(!root)
    return 0;
  else
  {
    // we are going to calculate the height for each of the subtree
    
    // left tree 
    int lheight = height(root->left);
    
    // right tree 
    int rheight = height(root->right);

    // whichever we found highest will be taken forward either left height or the right height
    if(lheight > rheight)
      return lheight + 1;
    else
      return rheight + 1;
  }  
}

Node* newNode(int data)
{
  return new Node(data);
}


// Approach 2 is using queues

void levelOrderTraversal_queue(Node* root)
{
  if(!root)
    return;

  queue<Node*> q;

  q.push(root);

  while(!q.empty())
  {
    Node* temp = q.front();
    cout << temp->data << " ";
    q.pop();

    if(temp->left)
      q.push(temp->left);

    if(temp->right)
      q.push(temp->right);
  }
}

Node* buildBinaryTree(Node* root){

  int data;

  if(!root){
    cout << "Enter the root node: " << endl;
    cin >> data;
    root = new Node(data);
  }

  cout << "Enter the data for the left node of  " << root->data << endl;
  cin >> data;

  if(data == -1){
    root->left = NULL;
  }else{
    root->left = new Node(data);
    buildBinaryTree(root->left);
  }

  cout << "Enter the data for the right node of " << root->data << endl;
  cin >> data;

  if(data == -1){
    root->right = NULL;
  }else{
    root->right = new Node(data);
    buildBinaryTree(root->right);
  }

  return root;
}

void inorderTraversal(Node* root){

  if(!root)
    return;

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}


void preorderTraversal(Node* root){

  if(!root)
    return;

  cout << root->data << endl;

  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
  
  if(!root)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);

  cout << root->data << endl;

}

void levelOrderTraversal_queue_levelwise(Node* root){

  if(!root)
    return;

  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();

    if(!front){
      cout << endl;

      if(!q.empty()){
        q.push(NULL);
      }

    }else{
      cout << front->data << " ";

      if(front->left)
      q.push(front->left);
    
      if(front->right)
        q.push(front->right);
    }    
  }
}

int main(void)
{
  Node* root = NULL;

  root = buildBinaryTree(root);
  cout << endl;
  // 1 5 13 -1 -1 14 -1 -1 7 17 -1 -1 -1  

  // root->left = newNode(2);
  // root->right = newNode(3);
  // root->left->left = newNode(4);
  // root->left->right = newNode(5);

  levelOrderTraversal_queue_levelwise(root);
  cout << endl;

  inorderTraversal(root);
  cout << endl;

  preorderTraversal(root);
  cout << endl;

  postorderTraversal(root);
  cout << endl;

  return 0;
}
