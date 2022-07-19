#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maximumSumSubsequence(vector<int> arr){

    int n = arr.size();
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        dp[i] = arr[i];
    }

    for(int i = 1; i < n; i++){

        for(int j = 0; j < i; j++){

            if(arr[j] < arr[i] and dp[i] < dp[j] + arr[i]){
                dp[i] = dp[j] + arr[i];
            }

        }

    }

    int maxi = INT_MIN;

    for(auto x: dp)
        maxi = max(maxi, x);

    return maxi;

}

int main(void){
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};

    cout << maximumSumSubsequence(arr) << endl;

    return 0;
}