#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int specficDist(vector<int> arr, int k){

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int i = 1; i < n; i++){

        dp[i] = dp[i - 1];

        if(arr[i] - arr[i - 1] < k){

            if(i >= 2)
                dp[i] = max(dp[i], dp[i - 2] + arr[i] + arr[i - 1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i - 1]);
        }
 
    }

    return dp[n - 1];

}

int main(void){

    vector<int> arr = {3, 5, 10, 15, 17, 12, 9};

    cout << specficDist(arr, 4) << endl;

    return 0;
}