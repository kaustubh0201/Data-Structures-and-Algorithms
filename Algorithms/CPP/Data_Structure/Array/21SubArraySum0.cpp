#include<iostream>
#include<unordered_set>

#define ump unordered_set

using namespace std;

bool subarraySumZero(int arr[], int n){

    ump<int> s;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum == 0){
            return true;
        }

        if(s.find(sum) == s.end()){
            s.insert(sum);
        }else{
            return true;
        }
    }

    return false;
}

int main(void){

    int arr[] = {1, 4, -2, -2, 5, -4, 3};
    int arr1[] = {-3, 2, 3, 1, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << subarraySumZero(arr1, n) << endl;

    return 0;
}
