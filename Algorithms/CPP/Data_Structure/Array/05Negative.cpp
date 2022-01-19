#include<bits/stdc++.h>

using namespace std;

// approach 1
void moveNegativeNum(int arr[], int n){
   int index = n-1;

   for(int i = 0; i < n; i++){
       if(arr[i] < 0){
           while(arr[index] < 0)
               index--;

           if(i > index)
               break;

           swap(arr[i], arr[index]);
       }
   }
}

// approach 2
void moveNegativeNumRearrange(int arr[], int n){
    int j = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            if(i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

// approach 3
void moveNegativeNumTwoPointer(int arr[], int left, int right){
    
    while(left <= right){
        if(arr[left] < 0 and arr[right] >= 0){
            left++; right--;
        }
        
        else if(arr[left] >= 0 and arr[right] < 0){
            swap(arr[left], arr[right]);
            left++; right--;
        }

        else if(arr[left] >= 0 and arr[right] >= 0){
            right--;
        }

        else if(arr[left] < 0 and arr[right] < 0){
            left++;
        }        
    }
}

int main(void){

   int arr[] = {1, -8, -7, 2, 4, -6};
   int size = sizeof(arr) / sizeof(int);
    
   for(auto x: arr) cout << x << " ";
   cout << endl;

   moveNegativeNumRearrange(arr, size);
   moveNegativeNumTwoPointer(arr, 0, size-1);

   for(auto x: arr) cout << x << " ";
   cout << endl;

   return 0;
}
