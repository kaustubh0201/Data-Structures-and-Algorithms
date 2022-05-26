#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

int tripletSumTwoPointer(int arr[], int n, int x){
    
    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        
        int l = i + 1;
        int r = n - 1;

        while(l < r){
            
            if(arr[i] + arr[l] + arr[r] == x){
                return 1;
            }else if(arr[i] + arr[l] + arr[r] > x){
                r--;
            }else{
                l++;
            }
        }
    }

    return 0;
}

int tripletSumHashSet(int arr[], int n, int x){

    for(int i = 0; i < n - 2; i++){

        unordered_set<int> s;
        
        int curr = x - arr[i];

        for(int j = i + 1; j < n; j++){

            if(s.find(curr - arr[j]) != s.end()){
                return 1;
            }
            s.insert(arr[j]);
        }
    }

    return 0;
}

int main(void){
    
    int arr[] = { 1, 4, 45, 6, 10, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << tripletSumHashSet(arr, n, 25) << endl;

    return 0;
}
