#include<iostream>
#include<climits>

using namespace std;

class Queue{
  private:
    int size, front, rear;
    int *container;
    int capacity;

  public:
    Queue(int capacity){
      this->capacity = capacity;
      container = new int[capacity];
      size = 0;
      front = 0;
      rear = capacity - 1;
    }

    bool isFull(){
      return (size == capacity);
    }

    bool isEmpty(){
      return (size == 0);
    }

    int pop(){
      if(isEmpty())
        return INT_MIN;

      int item = container[front];
      front = (front + 1) % capacity;
      size--;

      return item;
    }

    void push(int num){
      
      if(isFull())
        return;

      rear = (rear + 1) % (capacity);
      container[rear] = num;
      size++;

    }

    int getFront(){
      if(isEmpty())
        return INT_MIN;

      return container[front];
    }

    int getRear(){
      if(isEmpty())
        return INT_MIN;

      return container[rear];
    }

};

int main(void){

  Queue q(5);

  q.push(134);
  q.push(343);
  q.push(342);
  q.push(121);

  cout << q.pop() << endl;
  cout << q.getFront() << endl;
  cout << q.getRear() << endl;

  return 0;
}
