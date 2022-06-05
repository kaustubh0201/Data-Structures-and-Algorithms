#include<iostream>

using namespace std;

int LongestCommonSubsequence(string s1, string s2){
    
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){

            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(void){

    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    
    cout << LongestCommonSubsequence(str1, str2) << endl;

    return 0;
}
