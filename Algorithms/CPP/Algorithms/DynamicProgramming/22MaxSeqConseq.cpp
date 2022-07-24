#include<iostream>
#include<vector>

using namespace std;

int maxSeq(vector<int> arr){

    int n  = arr.size();

    vector<int> sum(n);

    if(n >= 1)
        sum[0] = arr[0];

    if(n >= 2)
        sum[1] = arr[0] + arr[1];

    if(n > 2)
        sum[2] = max(sum[1], max(arr[0] + arr[2], arr[1] + arr[2]));

    for(int i = 3; i < n; i++){

        sum[i] = max(sum[i - 1], max(sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i]));

    }

    return sum[n - 1];

}

int main(void){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << maxSeq(arr) << endl;

    return 0;
}