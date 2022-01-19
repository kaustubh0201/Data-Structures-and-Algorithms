#include<iostream>
#include<queue>

using namespace std;

//Another different approach O(n^2)

// 1.Find all the positions of first character of original string in the string to be checked.

// 2.For every position found, consider it to be the starting index of the string to be checked.

// 3.Beginning from the new starting index, compare both strings and check whether they are equal or not.

// (Suppose original string to be s1,string to be checked be s2,n is length of strings and j is the position of first character of s1 in s2,

     // then for i < (length of original string) ,check if s1[i]==s2[(j+1)%n). Return false if any character mismatch is found, else return true.

// 4.Repeat 3rd step for all positions found.


bool checkstrings_queue(string s, string t)
{
    if(s.length() != t.length())
        return false;

    queue<char> q1, q2;

    for(auto x: s)
        q1.push(x);

    for(auto x: t)
        q2.push(x);

    int n = s.size();

    while(n--)
    {
        char t = q1.front();
        q1.pop();
        q1.push(t);

        if(q1 == q2)
            return true;
    }

    return false;
}

bool checkstrings_doublestring(string s, string t)
{
    if(s.length() != t.length())
        return false;

    string temp = s + s;
    
    if(temp.find(t) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    string s = "kaustubh";
    string t = "tukabhus";
    string t1 = "tubhkaus";

    cout << checkstrings_queue(s, t1) << endl;

    return 0;
}
