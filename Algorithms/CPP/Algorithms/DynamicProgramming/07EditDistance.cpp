#include<iostream>
#include<vector>

using namespace std;

int editDisUtil(string s, string t, int m, int n, vector<vector<int>> &dp){

    if(n == 0)
        return m;

    if(m == 0)
        return n;

    if(dp[m][n] != -1)
        return dp[m][n];

    if(s[m - 1] == t[n - 1])
        return dp[m][n] = editDisUtil(s, t, m - 1, n - 1, dp);

    int insert_ele = editDisUtil(s, t, m - 1, n, dp);
    int remove_ele = editDisUtil(s, t, m, n - 1, dp);
    int replace_ele = editDisUtil(s, t, m - 1, n - 1, dp);

    dp[m][n] = 1 + min(insert_ele, min(remove_ele, replace_ele));

    return dp[m][n];
}

int editDistance(string s, string t){

    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return editDisUtil(s, t, m, n, dp);
}

int main(void){

    string s = "voldemort";
    string t = "dumbledore";

    cout << editDistance(s, t) << endl;

    return 0;
}