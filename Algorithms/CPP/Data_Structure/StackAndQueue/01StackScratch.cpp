#include<iostream>

using namespace std;

class Stack{
  private:
    int max_size;
    int *container;
    int top;

  public:
    Stack(int n){
      max_size = n;
      container = new int[n];
      top = -1;
    }

    void push(int num){
      container[++top] = num;
    }

    int pop(){
      return container[top--];
    }

    int peek(){
      return container[top];
    }

    bool isEmpty(){
      return (top == -1);
    }

    bool isFull(){
      return (top == max_size - 1);
    }
};

int main(void){

  Stack s(5);

  s.push(53);
  s.push(31);
  s.push(13);
  s.push(67);
  s.push(43);

  while(!s.isEmpty()){
    cout << s.pop() << " ";
  }

  cout << endl;


  return 0;
}
