#include<iostream>
#include<algorithm>

using namespace std;

// Method 1: Naive Appraoch

void rightrotate(int arr[], int n, int outplace, int current){
    int tmp = arr[current];

    for(int i = current; i > outplace; i--){
        arr[i] = arr[i - 1];
    }

    arr[outplace] = tmp;
}

void rearrange(int arr[], int n){
    
    int outplace = -1;

    for(int i = 0; i < n; i++){

        if(outplace >= 0){

            if(((arr[i] >= 0) and (arr[outplace] < 0)) || ((arr[i] < 0) and (arr[outplace] >= 0))){
                rightrotate(arr, n, outplace, i);

                if(i - outplace >= 2)
                    outplace = outplace + 2;
                else
                    outplace = -1;
            }
        }

        if(outplace == -1){

            if((arr[i] >= 0 and i % 2 == 0) || (arr[i] < 0 and i % 2 != 0)){
                outplace = i;
            }
        }
    }
}


// Method 2: Processing after finding the positive and negative numbers 

// function when the negative is less than equal to positive

void fill1(int arr[], int neg, int pos){

    if(neg % 2 == 1){
        
        for(int i = 1; i < neg; i += 2){
            int tmp = arr[i];
            arr[i] = arr[i + neg];
            arr[i + neg] = tmp;
        }
    }else{

        for(int i = 1; i <= neg; i += 2){
            int tmp = arr[i];
            arr[i] = arr[i + neg - 1];
            arr[i + neg - 1] = tmp;
        }
    }
}

// function when the negatives are greater than the positives

void fill2(int arr[], int neg, int pos){

    if(pos % 2 == 1){

        for(int i = 1; i < pos; i += 2){
            int tmp = arr[i];
            arr[i] = arr[i + pos];
            arr[i + pos] = tmp;
        }
    }else{

        for(int i = 1; i <= pos; i += 2){
            int tmp = arr[i];
            arr[i] = arr[i + pos - 1];
            arr[i + pos - 1] = tmp;
        }
    }
}

void reverseArray(int arr[], int n){

    for(int i = 0; i < n/2; i++){
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}


// Method 3: Doesn't maintain the original order of the matrix

void rearrange2(int arr[], int n){

    int i = 0, j = n - 1;

    // putting the negaives to the end and the positives at the start
    while(i < j){

        while(i <= n - 1 and arr[i] >= 0)
            i++;
        
        while(j >= 0 and arr[j] < 0)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }

    if(i == 0 or i == n)
        return;

    int k = 0;

    while(k < n and i < n){
        swap(arr[k], arr[i]);
        i++;
        k += 2;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(void){

    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    //rearrange(arr, n);
    
    rearrange2(arr, n);

    printArray(arr, n);
   
    /*
    int neg = 0, pos = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] < 0)
            neg++;
        else
            pos++;
    }

    sort(arr, arr + n);

    if(neg <= pos){
        fill1(arr, neg, pos);
    }else{
        reverseArray(arr, n);
        fill2(arr, neg, pos);
    }

    printArray(arr, n);
    */

    return 0;
}
