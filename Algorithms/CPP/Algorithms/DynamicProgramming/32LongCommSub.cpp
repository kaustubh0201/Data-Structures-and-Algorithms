#include<iostream>
#include<vector>

using namespace std;

int longestCommonSubstring(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= m; j++){

            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }

    return result;
}

// space optimized
int longestCommonSubSO(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(2, vector<int>(m + 1, 0));

    int result = 0;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= m; j++){
            
            if(i == 0 or j == 0)
                dp[i % 2][j] = 0;
            else if(s1[i - 1] == s2[j - 1]){
                dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                result = max(result, dp[i % 2][j]);
            }else{
                dp[i % 2][j] = 0;
            }

        }
        
    }

    return result;
    
}

int main(void){

    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << longestCommonSubSO(s1, s2) << endl;

    return 0;
}