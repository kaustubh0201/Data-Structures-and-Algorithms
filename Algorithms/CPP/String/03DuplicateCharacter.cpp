#include<iostream>
#include<unordered_map>

using namespace std;

void duplicateCharacter(string s)
{
    unordered_map<char, int> char_count;

    for(auto x: s)
    {
        if(char_count.find(x) == char_count.end())
        {
            char_count[x] = 1;
        }
        else
        {
            char_count[x] += 1;
        }
    }

    for(auto x: char_count)
    {
        if(x.second > 1)
        {
            cout << x.first << " " << x.second << endl;
        }
    }


}

int main(void)
{
    string s = "kaustubh";

    duplicateCharacter(s);

    return 0;
}
