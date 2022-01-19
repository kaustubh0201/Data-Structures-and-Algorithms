#include<iostream>

using namespace std;

//1) Sort all jobs in decreasing order of profit. 
//2) Iterate on jobs in decreasing order of profit.For each job , do the following : 
//a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in 
//this slot and mark this slot filled. 
//b)If no such i exists, then ignore the job.

struct Job
{
  int id;
  int deadline;
  int cost;
};

bool compareJob(Job a, Job b)
{
  return a.cost > b.cost;
}

void printJobScheduling(Job arr[], int n)
{
  int result[n];
  bool slot[n];
  
  for(int i = 0; i < n; i++)
    slot[i] = false;

  for(int i = 0; i < n; i++)
  {
    for(int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
    {
      if(!slot[j])
      {
        slot[j] = true;
        result[j] = i;
        break;
      }
    }
  }

  for(int i = 0; i < n; i++)
  {
    if(slot[i])
    {
      cout << arr[result[i]].id << " ";
    }
  }
  cout << endl;

}

int main(void)
{
    Job arr[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);

    printJobScheduling(arr, n);
}
