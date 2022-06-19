#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void MakeLPS(string s, int* lps){
    
    int n = s.length();

    lps[0] = 0;

    int i = 1, k = 0;

    while(i < n){
        if(s[i] == s[k]){
            k++;
            lps[i] = k;
            i++;
        }else{

            if(k != 0){
                k = lps[k-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int MinCharLength(string s){

    string str = s + "#";
    reverse(s.begin(), s.end());
    str += s;

    int n = str.length();

    int lps[n];

    MakeLPS(str, lps);

    return (s.length() - lps[n-1]);

}

int main(void){

    string s = "AACECAAAA";
    cout << MinCharLength(s) << endl;
    return 0;
}
