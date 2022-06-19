#include<iostream>
#include<algorithm>

using namespace std;

void SoldiersDefeated(int *SolStren, int n, int *BisStren, int q){
  
  sort(SolStren, SolStren + n);

  for(int i = 0; i < q; i++){
    
    int count = 0, sum = 0;
    for(int j = 0; j < n; j++){

      if(BisStren[i] >= SolStren[j]){
        count ++;
        sum += SolStren[j];
      }
    }

    cout << count << " " << sum << endl;
  }
}

int main(void){

  int SolStren[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(SolStren) / sizeof(SolStren[0]);
  
  int BisStren[] = {3, 10, 2};
  int q = sizeof(BisStren) / sizeof(BisStren[0]);

  SoldiersDefeated(SolStren, n, BisStren, q);

  return 0;
}
