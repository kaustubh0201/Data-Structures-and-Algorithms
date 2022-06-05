#include<iostream>
#include<string>

using namespace std;

string CountUtil(string str){
    
        int prev = str[0] - '0';
        int count = 1;
        
        string ans = "";
        
        for(int i = 1; i < str.length(); i++){
            if(str[i] - '0' == prev){
                count++;
            }
            else{
                ans += to_string(count);
                ans += to_string(prev);
                
                prev = str[i] - '0';
                count = 1;
            }
        }
        
        ans += to_string(count);
        ans += to_string(prev);
        
        return ans;
}

string CountAndSay(int n){

    string s = "1";

    for(int i = 0; i < n-1; i++){
        s = CountUtil(s);
    }

    return s;
}

int main(void){
    
    string str = "3334444";
    cout << CountUtil(str) << endl;
    
    cout << CountAndSay(4) << endl;

    return 0;
}
