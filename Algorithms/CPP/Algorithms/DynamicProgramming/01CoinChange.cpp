#include<iostream>
#include<vector>

#define ll long long int

using namespace std;

ll coinChangeUtil(vector<int> arr, int n, int sum, vector<vector<ll>> &dp){

    if(sum == 0)
        return 1;
    
    if(sum < 0)
        return 0;

    if(n <= 0)
        return 0;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    dp[n][sum] = coinChangeUtil(arr, n, sum - arr[n - 1], dp) + coinChangeUtil(arr, n - 1, sum, dp);

    return dp[n][sum];

}

ll coinChange(vector<int> arr, int sum){

    int n = arr.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, -1));

    return coinChangeUtil(arr, n, sum, dp);

}


int main(void){

    vector<int> arr = {2,5,3,6};

    cout << coinChange(arr, 10) << endl;

    return 0;
}