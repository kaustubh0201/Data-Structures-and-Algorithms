#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void reverseStackUtil(vector<int> &v, stack<int> &s){
  
  if(s.empty())
    return;

  else{
    
    int a = s.top();
    s.pop();

    v.push_back(a);

    reverseStackUtil(v, s);
  }

}

vector<int> ReverseStackI(stack<int> s){

  vector<int> v;
  
  reverseStackUtil(v, s);

  return v;
}

void insertAtBottom(stack<int> &s, int x){
  if(s.empty()){
    s.push(x);
  }

  else{
    
    int a = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(a);
  }
}

void ReverseStackII(stack<int> &s){
  
  if(s.size() > 0){
    
    int a = s.top();
    s.pop();

    ReverseStackII(s);

    insertAtBottom(s, a);

  }
  
}

int main(void){

  stack<int> s;
  
  for(int i = 0; i < 5; i++){
    s.push(i);
  }

  ReverseStackII(s);

  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;

  return 0;
}
