#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int maximum(int a, int b, int c){
    
    vector<int> tmp = {a, b, c};
    
    return *max_element(tmp.begin(), tmp.end());
    
}

int lcsUtil(int n1, int n2, int n3, string A, string B, string C, vector<vector<vector<int>>> &dp){
    
    if(n1 == 0 or n2 == 0 or n3 == 0)
        return 0;
        
    if(A[n1 - 1] == B[n2 - 1] and B[n2 - 1] == C[n3 - 1]){
        return dp[n1][n2][n3] = 1 + lcsUtil(n1 - 1, n2 - 1, n3 - 1, A, B, C, dp);
    }
    
    if(dp[n1][n2][n3] != -1)
        return dp[n1][n2][n3];
        
    return dp[n1][n2][n3] = maximum(lcsUtil(n1 - 1, n2, n3, A, B, C, dp), lcsUtil(n1, n2 - 1, n3, A, B, C, dp), lcsUtil(n1, n2, n3 - 1, A, B, C, dp));
    
}

int main(void){

    string A = "geeks", B = "geeksfor", C = "geeksforgeeks";
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();

    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

    cout << lcsUtil(n1, n2, n3, A, B, C, dp) << endl;

    return 0;
}