#include<iostream>
#include<climits>

using namespace std;

int SmallestWindow(string s){
    
    int n = s.length();

    int min_length = INT_MAX;
    bool visited[256] = { false };

    int dist_count = 0;

    for(int i = 0; i < n; i++){
        if(!visited[s[i]]){
            visited[s[i]] = true;
            dist_count++;
        }
    }

    int start = 0, start_index = -1;
    int count = 0;

    int curr_count[256] = { 0 };

    for(int i = 0; i < n; i++){
        
        curr_count[s[i]]++;

        if(curr_count[s[i]] == 1){
            count++;
        }

        if(count == dist_count){
            
            while(curr_count[s[start]] > 1){
                if(curr_count[s[start]] > 1)
                    curr_count[s[start]]--;
                start++;
            }

            int len = i - start + 1;

            if(min_length > len){
                min_length = len;
                start_index = start;
            }

        }

    }

    return min_length;
}

int main(void){

    string s = "aabcbcdbca";
    cout << SmallestWindow(s) << endl;
    return 0;
}
