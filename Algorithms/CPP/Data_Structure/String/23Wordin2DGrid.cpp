#include<iostream>
#include<string>

using namespace std;

int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

#define ROW 3
#define COL 13

bool internalSearchGrid(string needle, int row, int col, int row_max, int col_max, char *hay){
    
    if(needle[0] != *(hay+row*col_max+col))
        return false;

    int n = needle.length();

    for(int dir = 0; dir < 8; dir++){
        
        int i, rd = row + x[dir], cd = col + y[dir];

        for(i = 1; i < n; i++){
            
            if(rd >= row_max || rd < 0 || cd >= col_max || cd < 0)
                break;

            if(*(hay+rd*col_max+cd) != needle[i])
                break;

            rd += x[dir];
            cd += y[dir];

        }

        if(i == n)
            return true;
    }

    return false;
}

void SearchInGrid(string needle, int row_max, int col_max, char* hay){
    
    for(int row = 0; row < row_max; row++){
        for(int col = 0; col < col_max; col++){
            if(internalSearchGrid(needle, row, col, row_max, col_max, hay)){
                cout << row << " " << col << endl;
            }
        }
    }
}

int main(void){

    int R = 3, C = 13;
    char grid[R][C] = { "GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };
 
    SearchInGrid("GEEKS", R, C, (char *)grid);
    cout << endl;

    SearchInGrid("EEE", R, C, (char *)grid);
    cout << endl;
    return 0;
}
