#include<iostream>
#include<stack>

using namespace std;

char* reverseString(char *S, int n){
  
  stack<char> stk;

  for(int i = 0; i < n; i++){
    stk.push(S[i]);
  }

  for(int i = 0; i < n; i++){
    S[i] = stk.top();
    stk.pop();
  }

  return S;
}

int main(void){
  
  char s[] = "Kaustubh";
  int n = sizeof(s) / sizeof(s[0]);

  char* ans = reverseString(s, n);

  for(int i = 0; i < n; i++){
    cout << ans[i];
  }
  
  cout << endl;

  return 0;
}
