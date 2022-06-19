#include<iostream>
#include<vector>

using namespace std;

int maxLootDP(int *houseVal, int n){

  if(n == 0)
    return 0;

  if(n == 1)
    return houseVal[0];

  if(n == 2)
    return max(houseVal[0], houseVal[1]);

  int dp[n] = { -1 };

  dp[0] = houseVal[0];
  dp[1] = max(houseVal[0], houseVal[1]);

  for(int i = 2; i < n; i++){
    dp[i] = max(houseVal[i] + dp[i - 2], dp[i - 1]);
  }

  return dp[n - 1];

}

int maxLootUtil(int *houseVal, int n, vector<int> &dp){

  if(n < 0)
    return 0;

  if(n == 0)
    return houseVal[0];

  if(dp[n] != -1)
    return dp[n];

  int pick = houseVal[n] + maxLootUtil(houseVal, n - 2, dp);
  int notPick = maxLootUtil(houseVal, n - 1, dp);

  return dp[n] = max(pick, notPick);
}

int maxLoot(int arr[], int n){
  
  vector<int> dp(n + 1, -1);

  return maxLootUtil(arr, n - 1, dp);
}

int main(void){

  int arr[] = {6, 7, 1, 3, 8, 2, 4};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << maxLootDP(arr, n) << endl;
  return 0;
}
