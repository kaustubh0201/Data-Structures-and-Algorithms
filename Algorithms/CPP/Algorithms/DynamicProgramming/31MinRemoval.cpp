#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minRemovalUtil(vector<int> &arr, int left, int right, int k, vector<vector<int>> &dp){

    if(left >= right)
        return 0;

    if(arr[right] - arr[left] <= k)
        return 0;

    if(dp[left][right] != -1)
        return dp[left][right];

    else if(arr[right] - arr[left] > k)
        dp[left][right] = 1 + min(minRemovalUtil(arr, left + 1, right, k, dp), minRemovalUtil(arr, left, right - 1, k, dp));

    return dp[left][right];
}

int minRemoval(vector<int> &a, int k){

    int n = a.size();

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return minRemovalUtil(a, 0, n - 1, k, dp);

}

int main(void){

    vector<int> arr = {1,3,4,9,10,11,12,17,20};
    int k = 4;

    cout << minRemoval(arr, k) << endl;

    return 0;
}