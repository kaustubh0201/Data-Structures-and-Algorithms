#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

int getLargestArea(int hist[], int n){

  stack<int> s;
  s.push(-1);


  int i = 0;

  vector<int> right_smaller(n, n), left_smaller(n, -1);

  while(i < n){
    
    while(!s.empty() and s.top() != -1 and hist[s.top()] > hist[i]){
      
      right_smaller[s.top()] = i;
      s.pop();

    }

    if(i > 0 and hist[i] == hist[i - 1]){
      left_smaller[i] = left_smaller[i - 1];
    }else{
      left_smaller[i] = s.top();
    }

    s.push(i);
    i++;
  }

  int max_area = INT_MIN;

  for(int i = 0; i < n; i++){
    
    max_area = max(max_area, hist[i] * (right_smaller[i] - left_smaller[i] - 1));

  }

  return max_area;
}

int LargestHistogramArea(int hist[], int n){
  
  stack<int> s;

  int max_area = INT_MIN;

  int i = 0;
  while(i < n){
    
    if(s.empty() or hist[i] >= hist[s.top()]){
      s.push(i++);
    }

    else{
      
      int tp = s.top(); s.pop();

      int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);

      max_area = max(max_area, area);
    }

  }

  while(!s.empty()){
    int tp = s.top(); s.pop();
    
    int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);

    max_area = max(max_area, area);
  }

  return max_area;

}

int main(void){

  int hist[] = {6, 2, 5, 4, 5, 1, 6};
  int n = sizeof(hist)/sizeof(hist[0]);

  cout << LargestHistogramArea(hist, n) << endl;
  cout << getLargestArea(hist, n) << endl;

  return 0;
}
