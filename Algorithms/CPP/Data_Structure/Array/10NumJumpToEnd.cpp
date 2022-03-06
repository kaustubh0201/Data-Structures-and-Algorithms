#include<iostream>
#include<climits>

using namespace std;


// the time complexity of this O(n^n) 
// we are calculating the same thing again
int minimum_jumps_recursion(int arr[], int n)
{
    // base case
    if(n == 1)
        return 0;

    // putting the result as INT_MAX for comparing
    int res = INT_MAX;

    // we are starting checking from the second last number, because we need to reach the last number
    for(int i = n - 2; i >= 0; i--)
    {
        // we are checking if we can reach the last number or not from that particular position
        if(i + arr[i] >= n-1)
        {
            // we are then going backwards checking each step if we can reach the next step or not 
            int sub_res = minimum_jumps_recursion(arr, i + 1);
            
            if(sub_res != INT_MAX)
            {
                // sub_res mostly returns adding the number of steps that's why +1 is done here
                res = min(res, sub_res + 1);
            }
        }
    }
    // we return the INT_MAX only when there is no option of reaching from that step to the next step
    return res;
}

// the time complexity is O(n^2)
int minimum_jumps_dp(int arr[], int n)
{
    // making an array to store the number of jumps from arr[0] to arr[i]
    int* jumps = new int[n];
    
    // if the array is empty or the first element is 0 then not possbile to reach the end 
    if(n == 0 || arr[0] == 0)
        return INT_MAX;

    // putting the first number as 0 because it is starting at that place
    jumps[0] = 0;

    // starting from the 2nd element and finding its minimum path from arr[0]
    for(int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;

        // iterating from 0 to i-1 to check for the minimum jumps
        for(int j = 0; j < i; j++)
        {
            // only if i reachable from j and j should be reachable from previous iterations
            if(i <= j + arr[j] and arr[j] != INT_MAX)
            {
                // updating the jump value of i so that it can also be used for later iteration
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    // return the number of steps needed to reach the last element
    return jumps[n-1];
}

int minimum_jumps_dp2(int arr[], int n)
{
    int *jumps = new int[n];

    jumps[n-1] = 0;

    for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i] == 0)
        {
            jumps[i] = INT_MAX;
        }

        else if(arr[i] + i >= n - 1)
        {
            jumps[i] = 1;
        }

        else
        {
            int min = INT_MAX;

            for(int j = i + 1; j < n and j <= arr[i] + i; j++)
            {
                if(min > jumps[j])
                    min = jumps[j];
            }

            if(min != INT_MAX)
                jumps[i] = min + 1;
            else
                jumps[i] = min;
        }
    }

    return jumps[0];
}

int main(void)
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minimum_jumps_dp2(arr, n) << endl;

    return 0;
}
