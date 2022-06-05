#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool checkValidShuffle(string s, string t, string r){
    if((s.length() + t.length()) != r.length()){
        return false;
    }

    string temp = s + t;

    sort(temp.begin(), temp.end());

    sort(r.begin(), r.end());

    if(temp == r){
        return true;
    }

    return false;
}

int main(void)
{
    string s1 = "XY", s2 = "12", s3 = "1XY2";

    cout << checkValidShuffle(s1, s2, s3) << endl;

    return 0;
}
