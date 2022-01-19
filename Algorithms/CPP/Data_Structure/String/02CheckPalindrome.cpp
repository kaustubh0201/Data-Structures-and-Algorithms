#include<iostream>

using namespace std;

int checkPalindrome(string s)
{
    int n = s.length();
    int flag = 1;

    for(int i = 0; i < n/2; i++)
    {
        if(s[i] != s[n-i-1])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main(void)
{
    string s = "abba";

    cout << checkPalindrome(s) << endl;
    return 0;
}
