#include<iostream>

using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string pat, int badchar[NO_OF_CHARS]){

    for(int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for(int i = 0; i < pat.length(); i++){
        badchar[(int)pat[i]] = i;
    }
}

void PatternSearching(string txt, string pat){

    int n = txt.length();
    int m = pat.length();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, badchar);

    int s = 0;

    while(s <= n - m){
        
        int j = m - 1;

        while(pat[j] == txt[s+j] and j >= 0){
            j--;
        }

        if(j < 0){
            cout << s << endl;

            s += (s+m < n) ? m - badchar[txt[s+m]] : 1;
        }else{

            s += max(1, j - badchar[txt[s+j]]);
        }

    }   

}

int main(void){

    string txt= "ABAAABCD";
    string pat = "ABC";
    PatternSearching(txt, pat);
    return 0;
}
