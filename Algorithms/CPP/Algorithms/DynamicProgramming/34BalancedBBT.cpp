#include<iostream>
#include<vector>

using namespace std;

#define ll long long int
#define MOD 1000000007

ll countUtil(int h, vector<ll> &dp){

    if(h == 0 or h == 1)
        return 1;

    if(dp[h] != -1)
        return dp[h];

    return dp[h] = countUtil(h - 1, dp) % MOD * (2 * countUtil(h - 2, dp) + countUtil(h - 1, dp)) % MOD;
}

int countBBT(int h){

    vector<ll> dp(h + 1, -1);

    return countUtil(h, dp);
}


int main(void){

    cout << countBBT(3) << endl;

    return 0;
}