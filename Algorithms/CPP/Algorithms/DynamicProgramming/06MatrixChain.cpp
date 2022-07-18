#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int matrixChainUtil(vector<int> arr, int i, int j, vector<vector<int>> &dp){

    if(i == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    
    for(int k = i; k < j; k++){

        int res = matrixChainUtil(arr, i, k, dp) + matrixChainUtil(arr, k + 1, j, dp) + arr[i - 1] * arr[j] * arr[k];
        mini = min(mini, res);

    }

    return dp[i][j] = mini;
}

int matrixChainMultiplication(vector<int> arr){

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return matrixChainUtil(arr, 1, n - 1, dp);

}

int main(void){

    vector<int> arr = {1, 2, 3, 4};
    arr = {40, 20, 30, 10, 30};
    cout << matrixChainMultiplication(arr) << endl;

    return 0;
}