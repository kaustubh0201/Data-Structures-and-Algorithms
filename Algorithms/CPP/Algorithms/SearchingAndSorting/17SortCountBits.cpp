#include<iostream>
#include<vector>

using namespace std;

int CountBits(int num){

  int count = 0;

  while(num){
    if(num & 1)
      count++;

    num = num >> 1;
  }

  return count;
}

void SortCountBits(int *arr, int n){
  
  vector<vector<int>> v(32);

  for(int i = 0; i < n; i++){
    v[CountBits(arr[i])].push_back(arr[i]);
  }

  int j = 0;

  for(int i = 31; i >= 0; i--){
    vector<int> tmp = v[i];

    for(auto x: tmp)
      arr[j++] = x;
  }

}

int main(void){

  int nums[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(nums) / sizeof(nums[0]);
  
  SortCountBits(nums, n);

  for(int i = 0; i < n; i++)
    cout << nums[i] << " "; cout << endl;

  return 0;
}
