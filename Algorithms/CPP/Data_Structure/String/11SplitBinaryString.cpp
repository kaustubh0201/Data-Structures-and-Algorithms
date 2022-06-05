#include<iostream>

using namespace std;

int SplitString(string s){
    
    int count = 0;
    int count0 = 0;
    int count1 = 0;

    for(int i = 0; i < s.length(); i++){
        
        if(s[i] == '0')
            count0++;
        else
            count1++;

        if(count0 == count1)
            count++;
    }

    if(count0 != count1)
        return -1;

    return count;
}

int main(void){

    string s = "0110010101";
    cout << SplitString(s) << endl;

    return 0;
}
