#include<iostream>
#include<stack>

using namespace std;

bool areBalanced(string s){
  
  int n = s.length();
  
  stack<char> stk;

  for(int i = 0; i < n; i++){
    if(stk.empty()){
      stk.push(s[i]);
    }else if((stk.top() == '(' and s[i] == ')') or (stk.top() == '{' and s[i] == '}') or (stk.top() == '[' and s[i] == ']')){
      stk.pop();
    }else{
      stk.push(s[i]);
    }
  }

  if(stk.empty())
    return true;

  return false;  
}

int main(void){

  string expr = "{()}[]";

  cout << areBalanced(expr) << endl;
  return 0;
}
