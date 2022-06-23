#include<iostream>
#include<stack>

using namespace std;

class Queue{
  public:
    stack<int> s1, s2;

    void push(int x){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }

      s2.push(x);

      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
    }

    int pop(){
      if(s1.empty())
        return -1;

      int a = s1.top();
      s1.pop();

      return a;
    }
};

int main(void){

  Queue q;
  q.push(1);
  q.push(2);

  cout << q.pop() << endl;
  return 0;
}
