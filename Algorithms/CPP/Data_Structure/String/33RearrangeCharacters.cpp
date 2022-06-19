#include<iostream>
#include<queue>

using namespace std;

struct Node{
    char ch;
    int freq;

    bool operator<(const Node &n) const {
        return freq < n.freq;
    }
};

string RearrangeCharacters(string s){

    int n = s.length();

    int char_count[256] = { 0 };

    for(int i = 0; i < n; i++){
        char_count[s[i] - 'a']++;
    }

    priority_queue<Node> pq;

    for(char c = 'a'; c <= 'z'; c++){
        int val = c - 'a';
        if(char_count[val]){
            pq.push(Node{c, char_count[val]});
        }
    }

    Node prev{'#', -1};

    string result = "";

    while(!pq.empty()){
        
        Node top = pq.top();
        pq.pop();
        result += top.ch;

        if(prev.freq > 0)
            pq.push(prev);

        top.freq--;

        prev = top;
    }

    if(n != result.length())
        return "-1";

    return result;

}


int main(void){

    string s = "geeksforgeeks";
    cout << RearrangeCharacters(s) << endl;
    return 0;
}
