#include<iostream>
#include<vector>

using namespace std;

int lcsRecur(int x, int y, string s1, string s2){

    if(x == 0 or y == 0)
        return 0;

    if(s1[x - 1] == s2[y - 1])
        return 1 + lcsRecur(x - 1, y - 1, s1, s2);

    return max(lcsRecur(x - 1, y, s1, s2), lcsRecur(x, y - 1, s1, s2));
}

int lcsMem(int x, int y, string s1, string s2, vector<vector<int>> &dp){

    if(x == 0 or y == 0)
        return 0;

    if(s1[x - 1] == s2[y - 1])
        return dp[x][y] = (1 + lcsMem(x - 1, y - 1, s1, s2, dp));

    if(dp[x][y] != -1)
        return dp[x][y];

    return dp[x][y] = max(lcsMem(x - 1, y, s1, s2, dp), lcsMem(x, y - 1, s1, s2, dp));

}

int lcsTab(int x, int y, string s1, string s2){

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){

            if(i == 0 or j == 0)
                dp[i][j] = 0;
            
            else if(s1[i - 1] == s2[j - 1]){

                dp[i][j] = 1 + dp[i - 1][j - 1];

            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[x][y];
}


int main(void){

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int x = 6;
    int y = 7;

    cout << lcsRecur(x, y, s1, s2) << endl;

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

    cout << lcsMem(x, y, s1, s2, dp) << endl;

    cout << lcsTab(x, y, s1, s2) << endl;

    return 0;
}