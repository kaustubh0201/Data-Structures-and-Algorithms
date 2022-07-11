#include<iostream>
#include<vector>

using namespace std;

class Heap{

    vector<int> arr;

    void heapify(int i);

public:

    void insertInHeap(int num);
    int deleteFromHeap();

};

void Heap::heapify(int i){
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < arr.size() and arr[left] > arr[largest])
        largest = left;

    if(right < arr.size() and arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(largest);
    }
}

int Heap::deleteFromHeap(){

    int val = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();

    heapify(0);

    return val; 
}

void Heap::insertInHeap(int num){

    if(arr.size() == 0){
        arr.push_back(num);
        return;
    }

    arr.push_back(num);

    int i = arr.size() - 1;

    while(i >= 0){
        int parent = (i - 1) / 2;
        if(arr[parent] < arr[i]){
            swap(arr[parent], arr[i]);
            i = parent;
        }else{
            return;
        }            
    }    
}

int main(void){

    Heap p;

    p.insertInHeap(4);
    p.insertInHeap(3);
    p.insertInHeap(7);
    p.insertInHeap(9);
    p.insertInHeap(1);
    p.insertInHeap(2);

    cout << p.deleteFromHeap() << endl;
    cout << p.deleteFromHeap() << endl;
    cout << p.deleteFromHeap() << endl;
    cout << p.deleteFromHeap() << endl;
    cout << p.deleteFromHeap() << endl;
    cout << p.deleteFromHeap() << endl;


    return 0;
}