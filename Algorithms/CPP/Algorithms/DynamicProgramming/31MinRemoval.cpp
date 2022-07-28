#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// space complexity - O(n^2)
// time complexity - O(n^2)
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

// space optimized - O(1)
// time complexity - O(n)
int minRemovalLinear(vector<int> &a, int k){

    int n = a.size();

    sort(a.begin(), a.end());

    int i = 0;
    int max_len = INT_MIN;

    for(int j = i + 1; j < n and i < n; j++){

        if(a[i] - a[j] <= k){
            max_len = max(max_len, j - i + 1);
        }else{
            i++;
        }
    }

    return (n - max_len);
}

int main(void){

    vector<int> arr = {1,3,4,9,10,11,12,17,20};
    int k = 4;

    cout << minRemoval(arr, k) << endl;

    return 0;
}