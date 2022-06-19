#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int FindCelebrityTwoPointer(vector<vector<int>> M, int n){
  
  int left = 0, right = n - 1;

  while(left < right){
    
    if(M[left][right])
      left++;
    else
      right--;
  }

  int C = left;

  for(int i = 0; i < n; i++){
    if(i != C and (M[C][i] or !M[i][C]))
      return -1;
  }

  return C;

}

int FindCelebrity(vector<vector<int>> M, int n){
  
  stack<int> s;

  for(int i = 0; i < n; i++){
    s.push(i);
  }

  while(s.size() > 1){
    int A = s.top(); s.pop();
    int B = s.top(); s.pop();
    
    if(M[A][B]) 
      s.push(B);
    else 
      s.push(A);
  }

  int C = s.top(); s.pop();
  
  for(int i = 0; i < n; i++){
    if(i != C and (M[C][i] or !M[i][C]))
      return -1;
  }

  return C;
}

int main(void){

  vector<vector<int>> M = { { 0, 0, 1, 0 },
                          { 0, 0, 1, 0 },
                          { 0, 0, 0, 0 },
                          { 0, 0, 1, 0 } };
 
  cout << FindCelebrity(M, 4) << endl;
  return 0;
}
