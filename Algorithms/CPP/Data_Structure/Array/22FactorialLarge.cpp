#include<iostream>

#define max 500

using namespace std;

int multiply(int x, int res[], int res_size);

void findLargeFactorial(int number){

    int res[max];
    int res_length = 1;

    res[0] = 1;

    for(int i = 2; i <= number; i++){
        res_length = multiply(i, res, res_length);
    }

    for(int i = res_length - 1; i >= 0; i--){
        cout << res[i];
    }
    cout << endl;
}

int multiply(int x, int res[], int res_size){

    int carry = 0;

    for(int i = 0; i < res_size; i++){

        int prod = res[i] * x + carry;

        res[i] = prod % 10;

        carry = prod / 10;
    }

    while(carry){
        res[res_size] = carry % 10;
        carry = carry / 10;

        res_size++;
    }

    return res_size;
}

int main(void){

    int n;
    cin >> n;

    findLargeFactorial(n);

    return 0;
}
