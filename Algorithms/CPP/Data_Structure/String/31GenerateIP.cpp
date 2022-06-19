#include<iostream>
#include<vector>

using namespace std;

bool isValid(string s){
    
    int n = s.length();
    
    string temp = "";
    vector<string> v;

    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            v.push_back(temp);
            temp = "";
        }else{
            temp += s[i];
        }
    }

    v.push_back(temp);

    for(int i = 0; i < v.size(); i++){
        
        if(v[i].length() > 3 or stoi(v[i]) > 255 or stoi(v[i]) < 0)
            return false;

        if(v[i].length() > 1 and stoi(v[i]) == 0)
            return false;

        if(v[i].length() > 1 and stoi(v[i]) != 0 and v[i][0] == '0')
            return false;
    }

    return true;
}

vector<string> IPAddresses(string s){
    
    int n = s.length();

    vector<string> result;

    if(n > 12 or n < 4)
        return result;
    
    string check = s;

    for(int i = 1; i < n - 2; i++){
        for(int j = i + 1; j < n -1; j++){
            for(int k = j + 1; k < n; k++){
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);

                if(isValid(check)){
                    cout << check << endl;
                    result.push_back(check);
                }

                check = s;
            }
        }
    }

    return result;
}


int main(void){

    string s = "25525511135";
    IPAddresses(s);
    return 0;
}
