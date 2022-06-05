#include<iostream>
#include<vector>

using namespace std;

int MinimumSwaps(string s){

    vector<int> pos;
    int n = s.length();

    for(int i = 0; i < n; i++){
        if(s[i] == '[')
            pos.push_back(i);
    }

    int count = 0;
    int p = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        
        if(s[i] == '['){
            count++;
            p++;
        }else{
            count--;
        }

        if(count < 0){
            
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            p++;

            count = 1;
        }
    }

    return sum;
}

int main(void){

    string s = "[]][][";
    cout << MinimumSwaps(s) << endl;
    return 0;
}
