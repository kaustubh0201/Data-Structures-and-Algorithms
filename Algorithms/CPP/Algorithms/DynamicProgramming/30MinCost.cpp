#include<iostream>
#include<vector>

using namespace std;

int minCostFillUtil(vector<int> &cost, int n, int w, vector<vector<int>> &dp){

    if(n == -1 and w == 0)
        return 0;

    if(n == -1)
        return 1e9;

    if(w == 0)
        return 0;

    if(dp[n][w] != -1)
        return dp[n][w];

    if((n + 1) > w or cost[n] == -1)
        return dp[n][w] = minCostFillUtil(cost, n - 1, w, dp);

    int without = minCostFillUtil(cost, n - 1, w, dp);
    int with = cost[n] + minCostFillUtil(cost, n, w - (n + 1), dp);

    return dp[n][w] = min(with, without);
}

int main(void){

    vector<int> cost = {20, 10, 4, 50, 100};
    int n = cost.size();
    int w = 5;

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    int res = minCostFillUtil(cost, n - 1, w, dp);

    cout << ((res >= 1e9) ? -1 : res) << endl;

    return 0;
}