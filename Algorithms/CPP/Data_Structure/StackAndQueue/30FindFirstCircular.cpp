#include<iostream>
#include<queue>

using namespace std;

class petrolPump{
  public:
    int petrol;
    int distance;
};

int findStartIndexCircularQueue(petrolPump p[], int n){
  
  int start = 0;
  int end = 1;

  int curr = p[start].petrol - p[start].distance;

  while(start != end or curr < 0){
    
    while(start != end and curr < 0){
      
      curr -= (p[start].petrol - p[start].distance);

      start = (start + 1) % n;

      if(start == 0)
        return -1;
    }

    curr += (p[end].petrol - p[end].distance);
    end = (end + 1) % n;
  }

  return start;

}

int findStartIndexCircular(petrolPump p[], int n){
  
  int start = 0;
  int capacity = 0, deficit = 0;

  for(int i = 0 ; i < n; i++){
    capacity += p[i].petrol - p[i].distance;

    if(capacity < 0){
      
      start = i + 1;

      deficit += capacity;

      capacity = 0;
    }
  }

  return (capacity + deficit >= 0) ? start : -1; 

}

int main(void){
    petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << findStartIndexCircular(arr, n) << endl; 
    
  return 0;
}
