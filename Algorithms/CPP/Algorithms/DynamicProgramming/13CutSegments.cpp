#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int cutSegmentRecur(int n, int x, int y, int z){

    if(n == 0)
        return 0;

    if(n < 0)
        return INT_MIN;

    int a = cutSegmentRecur(n - x, x, y, z) + 1;
    int b = cutSegmentRecur(n - y, x, y, z) + 1;
    int c = cutSegmentRecur(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

int cutSegmentMem(int n, int x, int y, int z, vector<int> &dp){

    if(n == 0)
        return 0;

    if(n < 0)
        return INT_MIN;

    if(dp[n] != -1)
        return dp[n];

    int a = cutSegmentMem(n - x, x, y, z, dp) + 1;
    int b = cutSegmentMem(n - y, x, y, z, dp) + 1;
    int c = cutSegmentMem(n - z, x, y, z, dp) + 1;

    return dp[n] = max(a, max(b, c));
}

int cutSegmentTab(int n, int x, int y, int z){

    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    int a, b, c;
    a = b = c = INT_MIN;

    for(int i = 1; i <= n; i++){

        if(i - x >= 0){
            a = dp[i - x] + 1;
        }

        if(i - y >= 0){
            b = dp[i - y] + 1;
        }

        if(i - z >= 0){
            c = dp[i - z] + 1;
        }

        dp[i] = max(a, max(b, c));
    }

    return dp[n];    
}

int main(void){

    int n = 4;
    int x = 2;
    int y = 1;
    int z = 1;
    
    vector<int> dp(n + 1, -1);

    cout << cutSegmentRecur(n, x, y, z) << endl;

    cout << cutSegmentMem(n, x, y, z, dp) << endl;

    cout << cutSegmentTab(n, x, y, z) << endl; 

    return 0;
}