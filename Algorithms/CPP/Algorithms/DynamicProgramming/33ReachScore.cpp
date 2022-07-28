#include<iostream>
#include<vector>

using namespace std;

int minReachUtil(int n, int cost[], int index, vector<vector<int>> &dp){

    if(n == 0)
        return 1;

    if(n < 0)
        return 0;

    if(index <= 0)
        return 0;

    if(dp[index][n] != -1)
        return dp[index][n];

    return dp[index][n] = minReachUtil(n - cost[index - 1], cost, index, dp) + minReachUtil(n, cost, index - 1, dp);
}

int minReachScore(int n){

    int cost[] = {3, 5, 10};

    vector<vector<int>> dp(4, vector<int>(n + 1, -1));

    return minReachUtil(n, cost, 3, dp);
}

int main(void){

    cout << minReachScore(13) << endl;
    cout << minReachScore(20) << endl;


    return 0;
}