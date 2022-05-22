#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

string isSubsetOrNotMap(int arr1[], int n, int arr2[], int m){
    
    unordered_map<int, int> um;
    
    string ans = "Yes";

    for(int i = 0; i < n; i++){
        um[arr1[i]]++;
    }

    for(int i = 0; i < m; i++){
        if(um.find(arr2[i]) != um.end()){
            um[arr2[i]]--;

            if(um[arr2[i]] == -1){
                ans = "No";
                break;
            }
        }else{
            ans = "No";
            break;
        }
    }

    return ans;

}

string isSubsetOrNotSorting(int arr1[], int n, int arr2[], int m){

    int i = 0, j = 0;

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    if(n < m)
        return "No";

    while(i < n and j < m){

        if(arr1[i] < arr2[j]){
            i++;
        }else if(arr1[i] == arr2[j]){

            i++;
            j++;
        }
        else if(arr1[i] > arr2[j]){
            return "No";
        }
    }

    return (j < m) ? "No" : "Yes";
}

int main(void){

    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    cout << isSubsetOrNotSorting(arr1, n, arr2, m) << endl;


    return 0;
}
