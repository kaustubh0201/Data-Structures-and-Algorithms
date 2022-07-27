#include<iostream>
#include<climits>

using namespace std;

int maxDiff(string s){

    int n  = s.length();

    int max_till_now = 0;
    int max_so_far = INT_MIN;

    for(int i = 0; i < n; i++){

        int val = 0;

        if(s[i] == '0')
            val = 1;
        else
            val = -1;

        if(max_till_now < 0)
            max_till_now = val;
        else
            max_till_now += val;

        max_so_far = max(max_so_far, max_till_now);
    }

    return max_so_far;
}

int main(void){

    string s = "11000010001";

    cout << maxDiff(s) << endl;

    return 0;
}