#include<iostream>

using namespace std;

string longestPalin (string S) {
        
        int n = S.length();
        
        int dp[n][n];
        
        int startIndex = 0;
        int maxLength = 1;
        
        
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        for(int i = 0; i < n - 1; i++){
            if(S[i] == S[i + 1]){
                dp[i][i+1] = 1;
                
                maxLength = 2;
                
                if(startIndex == 0){
                    startIndex = i;
                }
            }
            else{
                dp[i][i+1] = 0;
             }
        }
        
        
        
        for(int k = 3; k <= n; k++){
            
            int flag = 0;
            
            for(int i = 0; i < n - k + 1; i++){
                
                if((S[i] == S[i + k - 1]) and dp[i+1][i + k - 2] == 1){
                    dp[i][i + k - 1] =  1;
                    
                    if(flag == 0){
                        startIndex = i;
                        maxLength = k;
                        flag = 1;
                    }
                }else{
                    dp[i][i + k - 1] = 0;
                }
            }
        }

        
        return S.substr(startIndex, maxLength);
        
}

int main(void){

    string s = "owo";
    cout << longestPalin(s) << endl;
    return 0;
}
