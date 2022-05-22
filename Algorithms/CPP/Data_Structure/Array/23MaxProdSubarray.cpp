#include<iostream>
#include<algorithm>

using namespace std;

int max_prod_subarray(int arr[], int n){

    int max_end_here = arr[0];
    int min_end_here = arr[0];

    int max_so_far = arr[0];

    for(int i = 1; i < n; i++){

        int tmp = max({max_end_here * arr[i], min_end_here * arr[i], arr[i]});
        min_end_here = min({max_end_here * arr[i], min_end_here * arr[i], arr[i]});
        max_end_here = tmp;

        max_so_far = max(max_end_here, max_so_far);
    }

    return max_so_far;
}

int main(void){
    
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);


    cout << max_prod_subarray(arr, n) << endl;

    return 0;
}
