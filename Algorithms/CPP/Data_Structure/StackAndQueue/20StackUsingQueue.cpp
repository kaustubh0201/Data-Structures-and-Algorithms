#include<iostream>
#include<queue>

using namespace std;

class Stack{
  queue<int> q1, q2;

  int size;

public:
  
  Stack(){
    size = 0;
  }

  void push(int x){
    
    size++;

    q2.push(x);

    while(!q1.empty()){
      q2.push(q1.front());
      q1.pop();
    }

    swap(q1, q2);
  }

  int pop(){

    size--;

    if(q1.empty()){
      return -1;
    }

    int a = q1.front();
    q1.pop();

    return a;
  }

  int top(){

    if(q1.empty())
      return -1;

    return q1.front();
  }
  
  int get_size(){
    return size;
  }

};

int main(void){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
 
    cout << "current size: " << s.get_size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
 
    cout << "current size: " << s.get_size()
         << endl;
  return 0;
}
