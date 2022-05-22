#include<iostream>
#include<algorithm>
#include<climits>
#include<unordered_set>

#define uSet unordered_set

using namespace std;

// Method 1: Sorting the array and then finding the longes consecutive subarray

int longestConsecutiveSequence(int arr[], int n){

    sort(arr, arr + n);

    int count = 0;
    int longest_subseq = INT_MIN;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            continue;
        }
        if(arr[i] == arr[i - 1] + 1){
            count++;
        }else{
            longest_subseq = max(count, longest_subseq);
            count = 0;
        }
    }

    longest_subseq = max(count, longest_subseq);

    return longest_subseq + 1;
}

// Method 2: use a hashset to store the elements and then check if the consecutive elements for it exist or not

int longestConsecutiveSequenceHashSet(int arr[], int n){

    uSet<int> elements;

    for(int i = 0; i < n; i++){
        elements.insert(arr[i]);
    }

    int max_so = INT_MIN;

    for(int i = 0; i < n; i++){

        if(elements.find(arr[i] - 1) == elements.end()){

            int count = arr[i];

            while(elements.find(count) != elements.end())
                count++;

            max_so = max(max_so, count - arr[i]);

        }
    }

    return max_so;
}

int main(void){
    
    int arr[] = {1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << longestConsecutiveSequenceHashSet(arr, n) << endl;

    return 0;

}
