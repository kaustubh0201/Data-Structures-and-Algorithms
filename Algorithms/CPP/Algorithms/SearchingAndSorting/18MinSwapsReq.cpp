#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int minSwaps(int *arr, int n){
  
  unordered_map<int, int> numPos;
  unordered_map<int, int> vis;

  for(int i = 0; i < n; i++){

    numPos[arr[i]] = i;
    vis[arr[i]] = 0;

  }

  sort(arr, arr + n);

  int swaps = 0;

  for(int i = 0; i < n; i++){
    
    if(vis[arr[i]] or numPos[arr[i]] == i)
      continue;

    int cycle = 0;
    int j = i;

    while(!vis[arr[j]]){
      
      vis[arr[j]] = 1;

      j = numPos[arr[j]];

      cycle++;
    }

    if(cycle > 0)
      swaps += (cycle - 1);
  }

  return swaps;
}

int minSwapsMap(int *arr, int n){
  
  unordered_map<int, int> mp;

  for(int i = 0; i < n; i++){
    mp[arr[i]] = i;
  }

  int i = 0, swaps = 0;

  for(auto x: mp){
    if(arr[i] != x.first){
      mp[arr[i]] = x.second;
      swap(arr[i], arr[x.second]);
      swaps++;
    }
    i++;
  }

  return swaps;

}

int main(void){

  int nums[] = {10, 19, 6, 3, 5};
  int n = sizeof(nums) / sizeof(nums[0]);
  
  cout << minSwapsMap(nums, n) << endl;

  return 0;
}
