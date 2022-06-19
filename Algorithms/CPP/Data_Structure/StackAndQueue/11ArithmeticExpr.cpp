#include<iostream>
#include<stack>
#include<string>

using namespace std;

int prec(char c){
  if(c == '^')
    return 3;
  else if(c == '*' or c == '/')
    return 2;
  else if(c == '+' or c == '-')
    return 1;
  else 
    return -1;
}

string infixToPostfix(string s){
  int n = s.length();

  stack<char> st;

  string result = "";

  for(int i = 0; i < n; i++){
    char c = s[i];

    if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'))
      result += c;

    else if(c == '('){
      st.push(c);
    }

    else if(c == ')'){
      while(st.top() != '('){
        result += st.top(); st.pop();
      }
      st.pop();
    }

    else{
      while(!st.empty() and prec(c) <= prec(st.top())){
        if(st.top() == '^' and c == '^')
          break;
        else{
          result += st.top(); st.pop();
        }
      }
      st.push(c);
    }
  }

  while(!st.empty()){
    result += st.top(); st.pop();
  }

  return result;
}

int PostfixEvaluation(string s){
  
  int n = s.length();

  stack<int> st;

  for(int i = 0; i < n; i++){
    
    char c = s[i];

    if(isdigit(c))
      st.push(c - '0');

    else {
      
      int A = st.top(); st.pop();
      int B = st.top(); st.pop();

      if(c == '*')
        st.push(B * A);
      else if(c == '/')
        st.push(B / A);
      else if(c == '+')
        st.push(B + A);
      else if(c == '-')
        st.push(B - A);
    }
  }

  return st.top();
}

int main(void){

  string exp = "a+b*(c^d-e)^(f+g*h)-i";
  cout << infixToPostfix(exp) << endl;

  exp = "123+*8-";
  cout << PostfixEvaluation(exp) << endl;
  return 0;
}

