#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x){
  
  if(s.empty()){
    s.push(x);
  }

  else {
    
    int a = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(a);
  }

}

int main(void){

  stack<int> s;
  
  for(int i = 0; i < 5; i++)
    s.push(i);

  insertAtBottom(s, 9);

  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  
  cout << endl;
  
  return 0;
}
