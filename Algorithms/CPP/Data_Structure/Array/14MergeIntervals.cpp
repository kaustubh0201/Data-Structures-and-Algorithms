#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

struct Interval
{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void merge_intervals_const(Interval arr[], int n)
{
    if(n <= 0)
        return;

    sort(arr, arr + n, compareInterval);

    int index = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[index].end >= arr[i].start)
        { 
            arr[index].end = max(arr[index].end, arr[i].end);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    
    for(int i = 0; i <= index; i++)
    {
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}

void merge_intervals_stack(Interval arr[], int n)
{
    
    if(n <= 0)
        return;

    sort(arr, arr + n, compareInterval);

    stack<Interval> s;

    s.push(arr[0]);

    for(int i = 1; i < n; i++)
    {
        Interval top = s.top();

        if(top.end < arr[i].start)
        {
            s.push(arr[i]);
        }

        else if(top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    while(!s.empty())
    {
        Interval top = s.top();

        cout << top.start << " " << top.end << endl;

        s.pop();
    }
}

int main(void)
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_intervals_const(arr, n);
        
    return 0;
}
