#include<iostream>

using namespace std;

int* findMissing(int *arr, int n){
  
  int *ans;

  ans = new int[2];

  for(int i = 0; i < n; i++){
    if(arr[abs(arr[i] - 1)] > 0)
      arr[abs(arr[i] - 1)] = -arr[abs(arr[i] - 1)];
    else
      ans[0] = abs(arr[i]);
  }

  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  for(int i = 0; i < n; i++){
    if(arr[i] > 0){
      ans[1] = (i + 1);
      break;
    }
  }

  return ans;
}

int main(void){
  
  int arr[] = {1, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int *ans = findMissing(arr, n);
  cout << ans[0] << " " << ans[1] << endl;

  return 0;
}
