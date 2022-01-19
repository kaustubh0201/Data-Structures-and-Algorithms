#include<iostream>
#include<vector>

using namespace std;

//The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
//1) Sort the activities according to their finishing time 
//2) Select the first activity from the sorted array and print it. 
//3) Do the following for the remaining activities in the sorted array. 
//…….a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and print it.

struct Activity
{
  int start;
  int finish;
};

bool compareActivities(Activity a1, Activity a2)
{
  return (a1.finish < a2.finish);
}

int countMaxActivities(int s[], int f[], int n)
{
  pair<int, int> p[n];

  for(int i = 0; i < n; i++)
  {
    p[i].first = f[i];
    p[i].second = i;
  }

  sort(p, p+n);

  int i = p[0].first;
  int count = 1;

  for(int j = 1; j < n; j++)
  {
    if(s[p[j].second] >= i)
    {
      i = p[j].first;
      count++;
    }
  }
}

void printMaxActivities(vector<int> s, vector<int> f)
{
  cout << 0 << " ";
  int i = 0;

  // sort(vec.begin(), vec.end(), compareActivities);
  for(int j = 1; j < s.size(); j++)
  {
    if(s[j] >= f[i])
    {
      i = j;
      cout << i << " ";
    }
  }

  cout << endl;
}

int main(void)
{
  vector<int> s = {1, 3, 0, 5, 8, 5};
  vector<int> f = {2, 4, 6, 7, 9, 9};

  printMaxActivities(s, f);
  
  return 0;
}
