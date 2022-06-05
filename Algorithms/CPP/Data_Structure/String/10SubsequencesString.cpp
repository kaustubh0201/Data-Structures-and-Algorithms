#include<iostream>
#include<unordered_set>

using namespace std;

void PrintSubsequences(string input, string output){
    
    if(input.empty()){
        if(!output.empty())
            cout << output << endl;
        
        return;
    }

    PrintSubsequences(input.substr(1), output);
    PrintSubsequences(input.substr(1), output + input[0]);

}

void subsequence(string input){

    int n = input.length();

    unordered_set<string> us;

    for(int i = 0; i < n; i++){

        for(int j = n; j > i; j--){
            string s = input.substr(i, j);
            
            us.insert(s);

            for(int k = 1; k < s.length(); k++){
                string sb = s;

                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }

}

int main(void){

    string s = "abcd";
    subsequence(s);
    cout << endl;
    return 0;
}
