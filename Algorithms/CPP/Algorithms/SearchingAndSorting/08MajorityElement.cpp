#include<iostream>

using namespace std;

int findCandidate(int arr[], int n){
  
  int maj_index = 0, count = 1;

  for(int i = 1; i < n; i++){
    if(arr[maj_index] == arr[i])
      count++;
    else
      count--;

    if(count == 0){
      maj_index = i;
      count = 1;
    }
  }
  
  return arr[maj_index];
}

bool isMajority(int arr[], int n, int cand){

  int count = 0;

  for(int i = 0; i < n; i++){
    if(arr[i] == cand)
      count++;
  }

  if(count > n / 2)
    return true;

  return false;
}

int MajorityElement(int arr[], int n){
  
  int cand = findCandidate(arr, n);

  bool ans = isMajority(arr, n, cand);

  if(ans)
    return cand;

  return -1;
}

int main(void){

    int arr[] = { 1, 3, 3, 1, 2 };
    int n = (sizeof(arr)) / sizeof(arr[0]);
    
    cout << MajorityElement(arr, n) << endl;

  return 0;
}
