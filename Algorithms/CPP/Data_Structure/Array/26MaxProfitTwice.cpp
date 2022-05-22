#include<iostream>
#include<algorithm>

using namespace std;

int MaxProfit(int price[], int n){

    int *profit = new int[n];

    for(int i = 0; i < n; i++)
        profit[i] = 0;

    int max_profit = price[n - 1];

    for(int i = n - 2; i >= 0; i--){

        if(price[i] > max_profit){
            max_profit = price[i];
        }

        profit[i] = max(profit[i + 1], (max_profit - price[i]));
    }

    int min_profit = price[0];

    for(int i = 1; i < n; i++){

        if(price[i] < min_profit){
            min_profit = price[i];
        }

        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_profit));
    }

    int result = profit[n - 1];

    delete[] profit;

    return result;
}

int main(void){
    int arr[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);
    


    return 0;
}
