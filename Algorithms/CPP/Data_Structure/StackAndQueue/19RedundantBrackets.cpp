#include<iostream>
#include<stack>

using namespace std;

bool isRedundantBrackets(string s){
  int n = s.length();
  
  stack<char> stk;

  for(int i = 0; i < n; i++){
    
    int c = s[i];

    if(c == ')'){
      
      bool flag = true;
      char ch = stk.top(); stk.pop();

      while(!stk.empty() and ch != '('){

        if(ch == '+' or ch == '-' or ch == '*' or ch == '/'){
          flag = false;
        }

        ch = stk.top();
        stk.pop();
      }

      if(flag)
        return true;
    }

    else 
      stk.push(c);
  }

  return false;

}

int main(void){

    string str = "((a+b))";
    cout << isRedundantBrackets(str) << endl;
 
    str = "(a+(b)/c)";
    cout << isRedundantBrackets(str) << endl;
 
    str = "(a+b*(c-d))";
    cout << isRedundantBrackets(str) << endl;
  return 0;
}
