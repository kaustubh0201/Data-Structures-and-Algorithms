#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

int snakeLadder(vector<vector<int>> &board){

    int n = board.size();
    bool flag = true;

    int count = 0;
    unordered_map<int, int> m;

    for(int i = n - 1; i >= 0; i--){

        if(flag){
            flag = false;

            for(int j = 0; i < n; i++){

                count++;

                if(board[i][j] != -1)
                    m[count] = board[i][j];

            }
        }else{

            flag = true;

            for(int j = n - 1; j >= 0; j--){

                count++;

                if(board[i][j] != -1)
                    m[count] = board[i][j];
            }
        }

    }

    queue<int> q;
    unordered_set<int> visited;

    q.push(1);
    visited.insert(1);

    int moves = 0;
    flag = false;

    while(not q.empty()){

        int size = q.size();
        moves++;

        for(int i = 0; i < size; i++){

            int temp = q.front(); q.pop();

            if(temp == count){
                moves--;
                flag = true;
                break;
            }

            for(int j = temp + 1; j <= min(temp + 6, count); j++){

                if(m.find(j) != m.end()){

                    if(visited.find(m[j]) == visited.end()){

                        q.push(m[j]);
                        visited.insert(m[j]);

                    }
                }else if(visited.find(j) == visited.end()){

                    q.push(j);
                    visited.insert(j);

                }

            }

        }

        if(flag)
            break;
    }

    return (flag) ? moves : -1;
}

int main(void){

    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1}, 
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
        };

    cout << snakeLadder(board) << endl;

    return 0;
}