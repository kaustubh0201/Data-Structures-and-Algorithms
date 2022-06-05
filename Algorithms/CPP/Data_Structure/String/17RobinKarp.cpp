#include<iostream>
#include<cstring>

using namespace std;

#define d 256

void RobinKarp(char pat[], char txt[], int q){
    int n = strlen(txt);
    int m = strlen(pat);
    int p = 0;
    int t = 0;
    int h = 1;

    for(int i = 0; i < m-1; i++){
        h = (h * d) % q;
    }

    for(int i = 0; i < m; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for(int i = 0; i <= n - m; i++){
    
        if(p == t){
            
            bool flag = true;
            int j;
    
            for(j = 0; j < m; j++){
                if(pat[j] != txt[i+j]){
                    flag = false;
                    break;
                }
            }

            if(j == m){
                cout << "Pattern found at index " << i << endl;
            }
        }

        if(i < n - m){
            t = (d * (t - txt[i]*h) + txt[i + m]) % q;

            if(t < 0)
                t = (t + q);
        }
    }
}

int main(void){

    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    int q = 101;

    RobinKarp(pat, txt, q);

    return 0;
}
