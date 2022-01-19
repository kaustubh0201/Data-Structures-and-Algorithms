#include<iostream>

using namespace std;

void reverse_string(string& s)
{
    int n = s.length();

    for(int i = 0; i < n/2; i++)
    {
        swap(s[i], s[n-i-1]);
    }
}

int main(void)
{
    string s = "kaustubh";
    reverse_string(s);

    cout << s << endl;

    return 0;
}
