#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void interleaveQueue(queue<int> &q){
  
  stack<int> s;
  int half = q.size() / 2;
  
  for(int i = 0; i < half; i++){
    s.push(q.front());
    q.pop();
  }

  while(!s.empty()){
    q.push(s.top());
    s.pop();
  }

  for(int i = 0; i < half; i++){
    q.push(q.front());
    q.pop();
  }

  for(int i = 0; i < half; i++){
    s.push(q.front());
    q.pop();
  }

  while(!s.empty()){
    q.push(s.top());
    s.pop();
    q.push(q.front());
    q.pop();
  }
}

int main(void){

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interleaveQueue(q);

    while(!q.empty()){
      cout << q.front() << " ";
      q.pop();
    }

    cout << endl;
  return 0;
}
