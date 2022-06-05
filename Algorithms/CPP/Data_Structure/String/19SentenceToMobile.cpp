#include<iostream>
#include<string>

using namespace std;

string SentenceMobileNumeric(string buttons[], string query){

    string result = "";
    
    for(int i = 0; i < query.length(); i++){
        
        result += buttons[query[i] - 'A'];

    }

    return result;

}

int main(void){
    
    string query = "KAUSTUBH";

    string buttons[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };

    cout << SentenceMobileNumeric(buttons, query) << endl;



    return 0;
}
