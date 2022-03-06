#include<iostream>

using namespace std;

// Method 1: Naive approach

int maxProfit(int price[], int start, int end){
    
    if(end <= start)
        return 0;

    int profit = 0;

    for(int i = start; i < end; i++){
        for(int j = i + 1; j <= end; j++){
            
            if(price[j] > price[i]){
                int current_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);

                profit = max(profit, current_profit);
            }
        }
    }

    return profit;
}

int main(void){
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(int);

    cout << maxProfit(price, 0, n - 1) << endl;    

    return 0;
}
