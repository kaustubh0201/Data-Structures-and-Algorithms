#include<iostream>

using namespace std;

class CircularQueue{
  int front, rear;

  int size;
  int *arr;

  public:
    
  CircularQueue(int size){
    this->size = size;
    front = rear = -1;
    arr = new int[size];
  }

  void enqueue(int x){
    if((front == 0 and rear == size - 1) or (rear == (front - 1)%(size - 1))){
      cout << "Full" << endl;
      return;
    }

    if(rear == size - 1 and front != 0){
      rear = 0;
      arr[rear] = x;
      return;
    }

    if(front == -1){
      front = ++rear;
      arr[rear] = x;
      return;
    }

    rear++;
    arr[rear] = x;
  }

  int dequeue(){
    if(front == -1){
      cout << "Empty" << endl;
      return -1;
    }

    int data = arr[front];
    arr[front] = -1;

    if(front == rear){
      front = rear = -1;
    }else if(front == size - 1){
      front = 0;
    }else{
      front++;
    }
    
    return data;
  }
  
  void displayQueue(){
    if(front == -1){
      cout << "Empty" << endl;
      return;
    }

    cout << "Elements in Circular Queue are: " << endl;
    if(rear >= front){
      for(int i = front; i <= rear; i++){
        cout << arr[i] << " ";
      }
    }else{
      for(int i = front; i < size; i++){
        cout << arr[i] << " ";
      }
      
      for(int i = 0; i <= rear; i++){
        cout << arr[i] << " ";
      }
    }

    cout << endl;
  }

};

int main(void){

    CircularQueue q(5);
 
    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d \n", q.dequeue());
    printf("\nDeleted value = %d \n", q.dequeue());
 
    q.displayQueue();
 
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
 
    q.displayQueue();
 
    q.enqueue(20);

  return 0;
}
