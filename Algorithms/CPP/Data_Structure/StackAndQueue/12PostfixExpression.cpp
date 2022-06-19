#include<iostream>
#include<stack>

using namespace std;

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

  string exp = "123+*8-";
  cout << PostfixEvaluation(exp) << endl;
  return 0;
}
