#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void threeWayPartioning(vector<int>& arr, int a, int b){
    
    int n = arr.size();
    int start = 0, end = n - 1;

    for(int i = 0; i <= end;){
        
        if(arr[i] < a){

            if(i == start){
                start++;
                i++;
            }else{
                swap(arr[i++], arr[start++]);
            }
        }else if(arr[i] > b){

            swap(arr[i], arr[end--]);
        }
        else{
            i++;
        }
    }
}

void printVector(vector<int> v){
    
    for(auto x: v)
        cout << x << " ";

    cout << endl;
}

int main(void){

    vector<int> arr {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int a = 14, b = 20;

    threeWayPartioning(arr, a, b);

    printVector(arr);

    return 0;
}
