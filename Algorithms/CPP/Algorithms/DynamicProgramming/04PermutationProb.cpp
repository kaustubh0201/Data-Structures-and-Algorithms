#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

int nPrUtil(int n, int r, vector<vector<int>> &dp){

    if(r > n)
        return 0;
    if(n == 1 and r <= 1)
        return 1;

    if(dp[n][r] != -1)
        return dp[n][r];

    dp[n][r] = (nPrUtil(n - 1, r, dp) % MOD + r * nPrUtil(n - 1, r - 1, dp) % MOD) % MOD;

    return dp[n][r];
}

int nPr(int n, int r){

    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return nPrUtil(n, r, dp);

}

int main(void){

    cout << nPr(10, 2) << endl;
    cout << nPr(10, 3) << endl;
    cout << nPr(10, 0) << endl;
    cout << nPr(10, 1) << endl;

    return 0;
}