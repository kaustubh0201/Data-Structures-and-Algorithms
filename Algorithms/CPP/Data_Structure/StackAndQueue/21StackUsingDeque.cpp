#include<iostream>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
      this->data = data;
      next = prev = NULL;
    }
};

class Deque{
  public:

  Node* tail;
  Node* head;

  Deque(){
    head = tail = NULL;
  }

  bool isEmpty(){
    return (!head);
  }

  void Insert_Last(int data){
    Node* temp = new Node(data);

    if(!head){
      head = tail = temp;
      return;
    }
    
    tail->next = temp;
    temp->prev = tail;

    tail = temp;
  }

  void Remove_Last(){
    
    if(!isEmpty()){
      Node* temp = tail;
      tail = tail->prev;
      if(tail) tail->next = NULL;

      delete temp;

      if(!tail) head = NULL;
      return;
    }

    cout << "Nothing to Remove" << endl;
  }
};

class Stack{

  public:

  Deque dq;

  void push(int x){
    dq.Insert_Last(x);
  }

  void pop(){
    dq.Remove_Last();
  }

  void display(){
    Node* temp = dq.head;

    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

};

int main(void){

    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
  return 0;
}
