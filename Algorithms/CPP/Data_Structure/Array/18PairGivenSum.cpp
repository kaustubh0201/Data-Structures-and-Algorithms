#include<iostream>
#include<unordered_map>

using namespace std;

// Method 1: Naive Approach

int getPairsCount(int arr[], int n, int sum){
    
    int count = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == sum)
                count++;
        }
    }

    return count;
}

// Method 2: Using Map

int getPairsCountMap(int arr[], int n, int sum){

    int count = 0;

    unordered_map<int, int> countArr;

    for(int i = 0; i < n; i++){
        countArr[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        count += countArr[sum - arr[i]];


        if(sum - arr[i] == arr[i])
            count--;
    }

    return count/2;

}

// Mehtod 3: Using Map and in one loop

int getPairsCountMapOne(int arr[], int n, int sum){

    int count = 0;

    unordered_map<int, int> countArr;

    for(int i = 0; i < n; i++){
        if(countArr.find(sum - arr[i]) != countArr.end()){
            count += countArr[sum - arr[i]];
        }
        countArr[arr[i]]++;
    }

    return count;
}

int main(void){
    
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 6;

    cout << getPairsCountMapOne(arr, n, sum) << endl;

    return 0;
}
