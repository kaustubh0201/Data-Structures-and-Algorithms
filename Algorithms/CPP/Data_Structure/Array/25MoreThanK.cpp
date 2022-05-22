#include<iostream>
#include<unordered_map>

using namespace std;

// Method 1: Using Hashmap

void moreThanK(int arr[], int n, int k){

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    for(auto i : mp){
        
        if(i.second > n/k){
            cout << i.first << " ";
        }
    }

    cout << endl;
}

// Method 2: making array and struct O(nk)

struct EleCount{
    int element;
    int count;
};

void moreThanKStruct(int arr[], int n, int k){
    
    EleCount count[k-1];

    for(int i = 0; i < k - 1; i++){
        count[i].element = i;
        count[i].count = 0;
    }

    for(int i = 0; i < n; i++){

        int j;

        for(j = 0; j < k - 1; j++){
            if(count[j].element == arr[i]){
                count[j].count += 1;
                break;
            }
        }

        if(j == k - 1){
            int l;

            for(l = 0; l < n - 1; l++){
                if(count[j].count == 0){
                    count[j].element = arr[i];
                    count[j].count = 1;
                    break;
                }
            }

            if(l == k - 1){
                for(int c = 0; c < k - 1; c++){
                    count[c].count -= 1;
                }
            }
        }
        
    }

    for(int i = 0; i < k - 1; i++){
        if(count[i].count > n/k){
            cout << count[i].element << " ";
        }
    }

    cout << endl;
}


int main(void){

    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    moreThanKStruct(arr, n, k);

    return 0;
}
