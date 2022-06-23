#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue<int> reverseK(queue<int> q, int k){
  
  stack<int> stk;
  int n = q.size();

  for(int i = 0; i < k; i++){
    stk.push(q.front());
    q.pop();
  }

  while(!stk.empty()){
    q.push(stk.top());
    stk.pop();
  }

  for(int i = 0; i < n - k; i++){
    int a = q.front();
    q.pop();
    q.push(a);
  }

  return q;
}

int main(void){

  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  q = reverseK(q, 3);

  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }

  cout << endl;

  return 0;
}
