#include<iostream>
#include<stack>

using namespace std;

void StackInsert(stack<int> &s, int x){
  
  if(s.empty() or x > s.top()){
    s.push(x);
  }

  else{
    int a = s.top(); s.pop();

    StackInsert(s, x);

    s.push(a);
  }
}

void StackSort(stack<int> &s){

  if(!s.empty()){
    
    int a = s.top(); s.pop();

    StackSort(s);

    StackInsert(s, a);
  }
}

int main(void){

  stack<int> s;
  s.push(9);
  s.push(3);
  s.push(6);
  s.push(1);

  StackSort(s);

  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;
  
  return 0;
}
