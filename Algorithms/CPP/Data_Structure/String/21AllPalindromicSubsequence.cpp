#include<iostream>
#include<cstring>

using namespace std;

int PalindromicSubsequence(string s){
    
    int n = s.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }

    for(int l = 2; l <= n; l++){

        for(int i = 0; i <= n - l; i++){
            int k = l + i - 1;
            
            if(s[i] == s[k]){
                dp[i][k] = dp[i+1][k] + dp[i][k-1] + 1;
            }else{
                dp[i][k] = dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1];
            }
        }
    }

    return dp[0][n-1];
}

int dp[1001][1001];

int PalindromicSubsequence_rec(string s, int i, int j){
    
    if(i > j)
        return 0;

    if(dp[i][j] != 0)
        return dp[i][j];

    if(i == j)
        return dp[i][j] = 1;


    if(s[i] == s[j])
        return dp[i][j] = PalindromicSubsequence_rec(s, i+1, j) + PalindromicSubsequence_rec(s, i, j-1) + 1;
    else
        return dp[i][j] = PalindromicSubsequence_rec(s, i+1, j) + PalindromicSubsequence_rec(s, i, j-1) + PalindromicSubsequence_rec(s, i+1, j-1);

}

int main(void){

    string s = "abcb";
    memset(dp, 0, sizeof(dp));
    cout << PalindromicSubsequence_rec(s, 0, s.length()-1) << endl;
    cout << PalindromicSubsequence(s) << endl;
    return 0;
}
