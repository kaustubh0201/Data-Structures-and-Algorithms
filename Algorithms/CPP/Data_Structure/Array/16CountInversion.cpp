#include <iostream>

using namespace std;


// Method 1: Direct Approach
// Time Complexity: O(n^2); Space Complexity : O(1)
int getInversionCount(int arr[], int n){
   int count = 0;
    
   for(int i = 0; i < n - 1; i++){
       for(int j = i + 1; j < n; j++){
           if(arr[i] > arr[j])
               count++;
       }
   }

   return count;
}

// Method 2: Count Inversion using Merge Sort

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int countInversionUsingMergeSort(int arr[], int n){
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right){
    
    int invCount = 0;

    if(right > left){

        int mid = (right - left) / 2 + left;

        invCount += _mergeSort(arr, temp, left, mid);
        invCount += _mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid + 1, right);
    }

    return invCount;
}

int merge(int arr[], int temp[], int left, int mid, int right){
    int i = left;
    int j = mid;
    int k = left;

    int invCount = 0;

    while((i <= mid - 1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];

            invCount += (mid - 1);
        }
    }


    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(int i = left; i <= right; i++){
        arr[i] = temp[i];
    }

    return invCount;
}

int main(void){
    
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    cout << mergeSort(arr, n) << endl;

    return 0;
}
