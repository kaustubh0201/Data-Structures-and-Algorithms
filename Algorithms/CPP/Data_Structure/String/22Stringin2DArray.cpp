#include<iostream>

using namespace std;

int internalSearch(string needle, int row, int col, int row_max, int col_max, string hay[], int index){
    
    int count = 0;

    if(row >= 0 and row <= row_max and col >= 0 and col <= col_max and needle[index] == hay[row][col]){
        
        char match = needle[index];
        index++;

        hay[row][col] = 0;

        if(needle[index] == 0)
        {
            count = 1;
        }else{
            count += internalSearch(needle, row + 1, col, row_max, col_max, hay, index);
            count += internalSearch(needle, row, col + 1, row_max, col_max, hay, index);
            count += internalSearch(needle, row - 1, col, row_max, col_max, hay, index);
            count += internalSearch(needle, row, col - 1, row_max, col_max, hay, index);
        }

        hay[row][col] = match;
    }

    return count;
}

int findString(string needle, int row, int col, int row_max, int col_max, string hay[]){
    
    int count = 0;

    for(int i = 0; i < row_max; i++){
        for(int j = 0; j < col_max; j++){
            
            count += internalSearch(needle, i, j, row_max - 1, col_max - 1, hay, 0);

        }
    }

    return count;

}

int main(void){
    
    string needle = "MAGIC";
    string hay[] = {   "BBABBM",
                       "CBMBBA",
                       "IBABBG",
                       "GOZBBI",
                       "ABBBBC",
                       "MCIGAM" };
    int row_max = sizeof(hay) / sizeof(hay[0]);
    int col_max = hay[0].length();

    cout << findString(needle, 0, 0, row_max, col_max, hay) << endl;

    return 0;
}
