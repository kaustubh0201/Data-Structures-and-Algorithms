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

// Method 2: Local Minima and Local Maxima

int maxProfitLocal(int price[], int n){

    if(n == 1)
        return 0;

    int i = 0;

    int profit = 0;

    while(i < n - 1){

        // first we will find the local Minima
        while((i < n - 1) and (price[i+1] < price[i]))
            i++;
        
        if(i == n - 1)
            return 0;

        int min = i++;

        // now we will find the local Maxima
        while((i < n) and (price[i] > price[i - 1]))
            i++;

        int max = --i;

        profit += price[max] - price[min];
    }

    return profit;
}

// Mehtod 3: Valley Peak Approach 
// In this approach, we just need to find the next greater element and subtract it from the current element 
// so that the difference keeps increasing until we reach a minimum. 
// If the sequence is a decreasing sequence so the maximum profit possible is 0.

int maxProfitPeak(int price[], int n){

    int profit = 0;

    for(int i = 1; i < n; i++){
        if(price[i] > price[i - 1]){
            profit += (price[i] - price[i - 1]);
        }
    }

    return profit;
}


int main(void){
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(int);

    cout << maxProfitPeak(price, n) << endl;    

    return 0;
}
