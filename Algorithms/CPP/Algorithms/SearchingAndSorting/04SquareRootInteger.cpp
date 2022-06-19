#include<iostream>
#include<cmath>

using namespace std;

int countSquares(int n){
  
  double root = sqrt(n);
  int ce = ceil(root);
  int fl = floor(root);

  if(ce == fl)
    return ce - 1;

  return fl;
}

int main(void){

  int num = 9;
  cout << countSquares(num) << endl;
  return 0;
}
