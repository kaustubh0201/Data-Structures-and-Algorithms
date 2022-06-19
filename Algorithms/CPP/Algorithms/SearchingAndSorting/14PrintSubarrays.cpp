#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int ZeroSubarrays(int *arr, int n){
  
  unordered_map<int, vector<int>> mp;

  int count = 0;

  int sum = 0;

  for(int i = 0; i < n; i++){
    
    sum += arr[i];

    if(sum == 0)
      count++;

    if(mp.find(sum) != mp.end()){
      
      count += mp[sum].size();

    }

    mp[sum].push_back(i);
  }

  return count;

}

int main(void){

  int arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << ZeroSubarrays(arr, n) << endl;

  return 0;
}
