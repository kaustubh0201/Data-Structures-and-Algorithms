#include<iostream>
#include<climits>

using namespace std;

class kStack{
  private:
    int *arr;
    int *top;
    int *next;

    int n, k;
    int Free;

  public:
    kStack(int k, int n);

    bool isFull() { return (Free == -1); }

    void push(int data, int sn);

    int pop(int sn);

    bool isEmpty(int sn) { return top[sn] == -1; }
};

kStack :: kStack(int k, int n){
  this->k = k;
  this->n = n;
  arr = new int[n];
  top = new int[k];
  next = new int[n];

  for(int i = 0; i < k; i++)
    top[i] = -1;

  Free = 0;

  for(int i = 0; i < n - 1; i++)
    next[i] = i + 1;
  next[n - 1] = -1;
}

void kStack :: push(int data, int sn){

  if(isFull()){
    cout << "Stack Overflow" << endl;
    return;
  }

  int i = Free;

  Free = next[i];

  next[i] = top[sn];
  top[sn] = i;

  arr[i] = data;
}

int kStack :: pop(int sn){

  if(isEmpty(sn)){
    cout << "Stack Underflow" << endl;
    return INT_MAX;
  }

  int i = top[sn];

  top[sn] = next[i];

  next[i] = Free;

  Free = i;

  return arr[i];
}


int main(void){

    int k = 3, n = 10;
    kStack ks(k, n);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  return 0;
}
