#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>

using namespace std;

string SecondMostRepeatedString(string arr[], int n){
    
    unordered_map<string, int> mp;

    int max_size = INT_MIN;

    for(int i = 0; i < n; i++){

        mp[arr[i]]++;

        if(mp[arr[i]] > max_size)
            max_size = mp[arr[i]];
    }

    int max_two = INT_MIN;

    string result = "";

    for(auto x: mp){
        if(x.second < max_size and x.second > max_two){
            max_two = x.second;
            result = x.first;
        }
    }

    return result;

}

int main(void){

    string arr[] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << SecondMostRepeatedString(arr, n) << endl;
    return 0;
}
