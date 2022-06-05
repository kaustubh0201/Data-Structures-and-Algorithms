#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

void computeLPS(int* lps, char pat[]){
    
    int len = 0;
    int i = 1;
    int n = strlen(pat);

    lps[0] = 0;

    while(i < n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0)
                len = lps[len - 1];

            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char txt[], char pat[]){
    
    int n = strlen(txt);
    int m = strlen(pat);
    
    int lps[m];

    computeLPS(lps, pat);

    int i = 0, j = 0;

    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }

        if(j == m){
            cout << "Index found at " << i - j << endl;
            j = lps[j - 1];
        }
        
        else if(i < n and pat[j] != txt[i]){
            if(j != 0)
                j = lps[j -1];
            else
                i++;
        }
    }
}

int main(void){
    
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";

    KMP(txt, pat);

    return 0;
}
