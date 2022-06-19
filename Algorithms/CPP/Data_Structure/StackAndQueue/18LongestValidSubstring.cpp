#include<iostream>
#include<stack>

using namespace std;

int longestSubstring(string s){
  
  int n = s.length();

  stack<int> stk;
  stk.push(-1);

  int result = 0;
  
  for(int i = 0; i < n; i++){
    
    if(s[i] == '(')
      stk.push(i);

    else{
      if(!stk.empty())
        stk.pop();

      if(!stk.empty())
        result = max(result, i - stk.top());

      else
        stk.push(i);
    }
  }

  return result;

}

int main(void){

  string s = "}{";
  cout << longestSubstring(s) << endl;
  return 0;
}
