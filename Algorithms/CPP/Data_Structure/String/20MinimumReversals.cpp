#include<iostream>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

// Approach 1: Remove the brackets that are canceling each other out
// The rest remaining will be divided between "{" and "}"
// ceil(count({) / 2) + ceil(count(}) / 2)
int MinimumBracketReversals(string str){

    if(str.length() % 2 != 0){
        return -1;
    }
    
    stack<char> stk;

    for(int i = 0; i < str.length(); i++){
        
        if(str[i] == '{'){
            stk.push(str[i]);
            continue;
        }

        if(stk.empty() and str[i] == '}')
        {
            stk.push(str[i]);
            continue;
        }

        if(stk.top() == '{' and str[i] == '}'){
            stk.pop();
            continue;
        }
        
        if(stk.top() == '}')
        {
            stk.push(str[i]);
        }   
    }
    
    int count1 = 0;
    int count2 = 0;

    while(!stk.empty()){
        if(stk.top() == '}')
            count1++;
        else
            count2++;

        stk.pop();
    }

    return ceil((float)count1/2) + ceil((float)count2/2);
}

int MinimumBracketReversals_M2(string str){

    if(str.length() % 2 != 0)
        return -1;

    stack<char> stk;
    
    int count = 0;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == '{')
            stk.push(str[i]);

        else if(stk.empty() and str[i] == '}'){
            stk.push('{');
            count++;
        }
        else if(stk.top() == '{' and str[i] == '}'){
            stk.pop();
        }
    }

    return count + (stk.size() / 2);
}

int main(void){

    string str = "}{{}}{{{";
    
    cout << MinimumBracketReversals_M2(str) << endl;

    return 0;
}
