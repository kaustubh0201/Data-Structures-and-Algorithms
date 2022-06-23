#include<iostream>
#include<stack>
#include<queue>

using namespace std;

bool IsStackPermutation(int arr1[], int arr2[], int n){

  queue<int> in, out;
  stack<int> stk;

  for(int i = 0; i < n; i++)
    in.push(arr1[i]);

  for(int i = 0; i < n; i++)
    out.push(arr2[i]);

  while(!in.empty()){

    int front = in.front();
    in.pop();

    if(front == out.front()){
      
      out.pop();

      while(!stk.empty()){
        if(stk.top() == out.front()){
          stk.pop();
          out.pop();
        }else
          break;
      }
    }else
      stk.push(front);
  }


  return (stk.empty() and in.empty());
}

int main(void){

    int input[] = {1, 2, 3};
 
    int output[] = {2, 1, 3};
 
    int n = 3;
    
    cout << IsStackPermutation(input, output, n) << endl;

  return 0;
}
