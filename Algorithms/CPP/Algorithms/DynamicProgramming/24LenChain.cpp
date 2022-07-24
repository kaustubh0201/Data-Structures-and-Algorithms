#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lenChainUtil(vector<pair<int, int>> pairs){

    sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    int n = pairs.size();

    vector<int> dp(n, 0);

    dp[0] = 1;

    for(int i = 1; i < n; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){

            if(pairs[i].first > pairs[j].second and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

        }
    }

    return *max_element(dp.begin(), dp.end());

}

int main(void){

    vector<pair<int, int>> pairs = { {5, 24} ,{39, 60}, {15, 28}, {27, 40}, {50, 90}};

    cout << lenChainUtil(pairs) << endl;

    return 0;
}