#include<iostream>

using namespace std;

char flip(char c){

    return (c == '1') ? '0' : '1';
}

int MinFlipsExpected(string s, char e){

    int n = s.length();

    int count = 0;
    
    for(int i = 0; i < n; i++){
        
        if(s[i] != e)
            count++;

        e = flip(e);
    }

    return count;
}

int MinFlips(string s){

    return min(MinFlipsExpected(s, '1'), MinFlipsExpected(s, '0'));
}

int main(void){

    string s = "0001010111";
    cout << MinFlips(s) << endl;
    return 0;
}
