#include<iostream>

using namespace std;

int Roman_Int(char c){
    
    if(c == 'M')
        return 1000;
    else if(c == 'D')
        return 500;
    else if(c == 'C')
        return 100;
    else if(c == 'L')
        return 50;
    else if(c == 'X')
        return 10;
    else if(c == 'V')
        return 5;
    else if(c == 'I')
        return 1;

    return -1;
}

int ConvertRomanInteger(string s){
    
    int n = s.length();

    int result = 0;

    for(int i = 0; i < n; i++){
        int one = Roman_Int(s[i]);

        if(i + 1 < n){
            int two = Roman_Int(s[i+1]);

            if(one >= two){
                result += one;
            }else{
                result += (two - one);
                i++;
            }
        }else{
            result += (one);
        }
    }

    return result;
}

int main(void){

    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is "
         << ConvertRomanInteger(str) << endl;

    return 0;
}
