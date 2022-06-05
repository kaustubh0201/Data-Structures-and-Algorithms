#include<iostream>

using namespace std;

void PrintPermutation(string s, int l, int r){
    if(l == r){
        cout << s << " ";
        return;
    }

    for(int i = l; i <= r; i++){
        
        swap(s[l], s[i]);

        PrintPermutation(s, l + 1, r);

        swap(s[l], s[i]);
    }
}

void Permutation(string s, string ans){

    if(s.empty()){
        cout << ans << " ";
        return;
    }

    for(int i = 0; i < s.length(); i++){
        char t = s[i];
        string lsub = s.substr(0, i);
        string rsub = s.substr(i + 1);
        
        string r = lsub + rsub;

        Permutation(r, ans + t);
    }
}

int main(void){

    string s = "ABC";
    int n = s.length();
    PrintPermutation(s, 0, n - 1);
    cout << endl;
    Permutation(s, "");
    cout << endl;
    return 0;
}
