#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007
#define ll long long int

ll friendsUtil(int n, vector<int> &dp){

    if(n <= 2)
        return n;

    if(dp[n] != -1)
        return dp[n];

    ll single = friendsUtil(n - 1, dp);
    ll paired = (((n - 1) % MOD) * friendsUtil(n - 2, dp) % MOD) % MOD;

    dp[n] = ((single % MOD) + (paired % MOD)) % MOD;

    return dp[n];
}


int friendsPairing(int n){

    vector<int> dp(n + 1, -1);

    return friendsUtil(n, dp);

}

int main(void){

    int n = 3;

    cout << friendsPairing(n) << endl;

    return 0;
}