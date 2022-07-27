#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minJumpsToEnd(vector<int> arr){

    int n = arr.size();

    if(n == 1)
        return 0;

    if(arr[0] == 0)
        return -1;

    vector<int> dp(n);

    dp[0] = 0;

    for(int i = 1; i < n; i++){

        dp[i] = INT_MAX;

        for(int j = 0; j < i; j++){

            if(i <= j + arr[j] and dp[j] != INT_MAX){
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }

        }

    }

    return (dp[n - 1] == INT_MAX) ? -1 : dp[n - 1];

}

int minJumpsToEndLinear(vector<int> arr){

    int n = arr.size();

    if(n == 1)
        return 0;

    if(arr[0] == 0)
        return -1;

    int maxReach = arr[0];

    int step = arr[0];

    int jumps = 1;

    for(int i = 1; i < n; i++){

        if(i == n-1)
            return jumps;

        maxReach = max(maxReach, i + arr[i]);

        step--;

        if(step == 0){

            jumps++;

            if(i >= maxReach)
                return -1;

            step = maxReach - i;

        }

    }

    return jumps;

}

int main(void){

    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumpsToEnd(arr) << endl;

    cout << minJumpsToEndLinear(arr) << endl;

    return 0;
}