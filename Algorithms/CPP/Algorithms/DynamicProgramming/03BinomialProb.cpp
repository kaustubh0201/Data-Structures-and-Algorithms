#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

int nCrUtil(int n, int r, vector<vector<int>> &dp){

    if(r > n)
        return 0;

    if(n == r)
        return 1;

    if(dp[n][r] != -1)
        return dp[n][r];

    dp[n][r] = (nCrUtil(n - 1, r, dp) % MOD + nCrUtil(n - 1, r - 1, dp) % MOD) % MOD;

    return dp[n][r];
}

int nCr(int n, int r){

    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return nCrUtil(n, r, dp);

}


int main(void){

    cout << nCr(5, 2) << endl;
    cout << nCr(3, 1) << endl;

    return 0;
}