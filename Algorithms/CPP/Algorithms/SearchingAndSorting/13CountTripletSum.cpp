#include<iostream>

using namespace std;

int TripleSumCalc(int *arr, int n, int sum){

  int count = 0;

  sort(arr, arr + n);

  for(int i = 0; i < n - 2; i++){
    
    int left = i + 1;
    int right = n - 1;

    int rem = sum - arr[i];

    while(left < right){
    
      if(arr[left] + arr[right] < rem){
        count += (right - left);
        left++;
      }else{
        right--;
      }
    }
  }

  return count;

}

int main(void){


  return 0;
}
