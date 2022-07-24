#include<iostream>
#include<vector>

using namespace std;

int lisTab(vector<int> arr){

    int n = arr.size();

    vector<int> dp(n);

    dp[0] = 1;

    for(int i = 1; i < n; i++){

        dp[i] = 1;

        for(int j = 0; j < i; j++){

            if(arr[j] < arr[i] and dp[i] < 1 + dp[j])
                dp[i] = 1 + dp[j];

        }
    }

    return dp[n - 1];

}

int main(void){

    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout << lisTab(arr) << endl;

    return 0;
}