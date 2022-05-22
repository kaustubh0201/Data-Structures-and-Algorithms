#include<iostream>
#include<climits>

using namespace std;

// Method1 : Three Pointer Approach

void findCommon(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){

    int i = 0, j = 0, k = 0;

    while(i < n1 and j < n2 and k < n3){

        if(arr1[i] == arr2[j] and arr2[j] == arr3[k]){
            cout << arr1[i] << " ";

            i++; j++; k++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else if(arr2[j] < arr3[k]){
            j++;
        }else{
            k++;
        }
    }

    cout << endl;

}

// Method 2: This also uses the same method but also considers the fact that there can be duplicates in the array which
// may lead to printing of same value mutiple times

void findCommonDup(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){

    int i = 0, j = 0, k = 0;
    
    int prev1, prev2, prev3;

    prev1 = prev2 = prev3 = INT_MIN;

    while(i < n1 and j < n2 and k < n3){

        while(arr1[i] == prev1 and i < n1)
            i++;

        while(arr2[j] == prev2 and j < n2)
            j++;

        while(arr3[k] == prev3 and k < n3)
            k++;

        if(arr1[i] == arr2[j] and arr2[j] == arr3[k]){
            cout << arr1[i] << " ";
            prev1 = prev2 = prev3 = arr1[i];
            i++; j++; k++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else if(arr2[j] < arr3[k]){
            j++;
        }else{
            k++;
        }
    }

    cout << endl;
}

// Mehthod 3: 
// In this approach, we will first delete the duplicate from each array, and after this, we will find the frequency of each element and 
// the element whose frequency equals 3 will be printed. For finding the frequency we can use a map but in this, 
// we will use an array instead of a map. But the problem with using an array is, we cannot find the frequency of negative numbers 
// so in the code given below we will consider each and every element of array to be positive.

// Method 4: Using STL
// The idea is to use hash set. Here we use 2 of the sets to store elements of the 1st and 2nd arrays. 
// The elements of the 3rd array are then checked if they are present in the first 2 sets. 
// Then, we use a 3rd set to prevent any duplicates from getting added to the required array.

int main(void){
    
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    findCommonDup(arr1, arr2, arr3, n1, n2, n3);

    return 0;
}
