#include<iostream>
#include<vector>

using namespace std;

int subsetPartUtil(vector<int> arr, int n, int sum, vector<vector<int>> &dp){

    if(sum == 0)
        return 1;
    
    if(n == 0 and sum != 0)
        return 0;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(arr[n - 1] > sum)
        return dp[n][sum] = subsetPartUtil(arr, n - 1, sum, dp);

    dp[n][sum] = subsetPartUtil(arr, n - 1, sum, dp) or subsetPartUtil(arr, n - 1, sum - arr[n - 1], dp);

    return dp[n][sum];
}

int subsetPartition(vector<int> arr){

    int n = arr.size();

    int sum = 0;
    for(auto x: arr)
        sum += x;

    if(sum % 2 != 0)
        return false;

    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));

    return subsetPartUtil(arr, n, sum / 2, dp);
}

int main(void){

    vector<int> arr = { 3, 1, 5, 9, 12 };
    arr = {1, 5, 11, 5};
    arr = {1, 3, 5};

    cout << subsetPartition(arr) << endl;

    return 0;
}