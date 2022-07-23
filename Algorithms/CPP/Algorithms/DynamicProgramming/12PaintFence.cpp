#include<iostream>
#include<vector>

using namespace std;

int add(int a, int b){
    return (a + b);
}

int mul(int a, int b){
    return (a * b);
}

int fencePaintRecur(int n, int k){

    if(n == 1)
        return k;
    
    if(n == 2)
        return add(k, mul(k, k - 1));

    return add(mul(fencePaintRecur(n - 2, k), k - 1), mul(fencePaintRecur(n - 1, k), k - 1));
}

int fencePaintMem(int n, int k, vector<int> &dp){

    if(n == 1)
        return k;
    
    if(n == 2)
        return add(k, mul(k, k - 1));

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = add(mul(fencePaintMem(n - 2, k, dp), k - 1), mul(fencePaintMem(n - 1, k, dp), k - 1));    
}

int fencePaintTab(int n, int k){

    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for(int i = 3; i <= n; i++){
    
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));

    }

    return dp[n];

}

int fencePaintSO(int n, int k){

    int prev1 = k;
    int prev2 = add(k, mul(k, k - 1));

    for(int i = 3; i <= n; i++){

        int tmp = add(mul(prev1, k - 1), mul(prev2, k - 1));

        prev1 = prev2;
        prev2 = tmp;

    }

    return prev2;
}




int main(void){

    int n = 2;
    int k = 4;

    vector<int> dp(n + 1, -1);

    cout << fencePaintRecur(n, k) << endl;

    cout << fencePaintMem(n, k, dp) << endl;

    cout << fencePaintTab(n, k) << endl;

    cout << fencePaintSO(n, k) << endl;

    return 0;
}