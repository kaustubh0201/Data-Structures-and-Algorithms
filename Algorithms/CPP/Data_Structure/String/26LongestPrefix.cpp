#include<iostream>
#include<climits>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string CommonPrefix(vector<string> strs){
    
    int n = strs.size();

    int min_size = INT_MAX;

    for(int i = 0; i < n; i++){

        if(strs[i].length() < min_size)
            min_size = strs[i].length();
    }

    string result = "";
    int index = 0;
    bool flag = false;

    while(index < min_size){
        
        for(int i = 1; i < n; i++){

            if(strs[i][index] != strs[i-1][index]){
                flag = true;
                break;
            }
        }

        if(flag)
            break;
        else{
            result += strs[0][index];
            index++;
        }

    }

    return result;
}

string LongestPrefix_sort(vector<string> strs){
    
    int n = strs.size();

    sort(strs.begin(), strs.end());

    int en = min(strs[0].size(), strs[n-1].size());

    int i = 0;

    string first = strs[0], end = strs[n-1];

    while(i < en and first[i] == end[i])
        i++;

    string result = first.substr(0, i);
    
    return result;

}

int main(void){
    vector<string> strs = {"flower","flow","flight"};
    cout << LongestPrefix_sort(strs) << endl;
    return 0;
}
