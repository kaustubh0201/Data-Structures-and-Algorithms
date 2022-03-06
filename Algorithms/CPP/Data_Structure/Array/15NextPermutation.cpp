#include<iostream>
#include<algorithm>

using namespace std;


// one approach is that we generate all the possible combinations and then find the one for which we are trying to find the next permuation
// after finding the number the next combination will be its next permuation
// this approach will take O(n! * n) because of n! orders and length of array is n

// one of the other algorithm is to traverse from the last and find the index whose a[i] < a[i + 1] so that will be index1
// the second step is to 

void permuation(string s)
{
    bool val = next_permutation(s.begin(), s.end());

    if(!val)
    {
        cout << "No next permuation possible" << endl;
    }
    else
    {
        cout << "The next permuation is: " << endl;
        cout << s << endl;
    }
}

int main(void)
{
    string s = "abedc";

    permuation(s);

    return 0;
}
