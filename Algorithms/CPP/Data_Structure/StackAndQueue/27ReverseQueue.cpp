#include<iostream>
#include<queue>

using namespace std;

void reverseQueue(queue<int> &q){
  
  if(q.empty())
    return;

  else{
    
    int a = q.front();
    q.pop();

    reverseQueue(q);

    q.push(a);
  }
}

queue<int> rev(queue<int> q){
  
  reverseQueue(q);

  return q;
}

int main(void){

  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  q = rev(q);

  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }

  cout << endl;

  return 0;
}
