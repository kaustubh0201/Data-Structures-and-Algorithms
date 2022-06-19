#include<iostream>
#include<algorithm>

using namespace std;

int middleThree(int A, int B, int C){
  
  if(min(A, min(B, C)) == C){
    return min(A, B);
  }else if(min(A, min(B, C)) == B){
    return min(A, C);
  }
  
  return min(B, C);
}

int main(void){

  int A = 978, B = 518, C = 300;
  cout << middleThree(A, B, C) << endl;
  return 0;
}
