#include<iostream>

using namespace std;

int smallestSubarray(int arr[], int n, int x){

    int min_value = n + 1;
    int curr_sum = 0;

    int start = 0;
    int end = 0;

    while(end < n){
        
        while(curr_sum <= x and end < n)
            curr_sum += arr[end++];


        while(curr_sum > x and start < n){
            
            if(end - start< min_value)
                min_value = end - start;

            curr_sum -= arr[start++];
        }
    }

    return min_value;

}

int main(void){

    int arr1[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << smallestSubarray(arr1, n1, x) << endl;

    return 0;
}
