#include<bits/stdc++.h>

using namespace std;

void rotate(int arr[], int n){
    int a = arr[n-1];
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = a;
}

void rotate1(int arr[], int n){
    int i = 0, j = n-1;
    while(i != j){
        swap(arr[i], arr[j]);
        i++;
    }
}

int main(void){
    int arr[] = {2, 3, 1, 5, 7, 3, 8, 6};
    int len = sizeof(arr)/sizeof(int);

    rotate1(arr, len);

    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
