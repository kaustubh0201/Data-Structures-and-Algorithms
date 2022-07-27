#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

bool isInside(int x, int y, int n, int m){

    if(x >= 0 and y >= 0 and x < n and x < m)
        return true;

    return false;

}

vector<vector<int>> distNearestCell(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> result = grid;

    queue<pair<int, int>> q;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(result[i][j] == 0){
                result[i][j] = INT_MAX;
            }else{
                result[i][j] = 0;
                q.push({i, j});
            }

        }

    }

    while(not q.empty()){

        auto front = q.front();
        q.pop();

        int x = front.first;
        int y = front.second;
        int val = result[x][y];

        for(int i = 0; i < 4; i++){
            
            if(isInside(x + dx[i], y + dy[i], n, m)){
                if(val + 1 < result[x + dx[i]][y + dy[i]]){
                    result[x + dx[i]][y + dy[i]] = val + 1;
                    q.push({x + dx[i], y + dy[i]});
                }
            }

        }

    }

    return result;
}

int main(void){

    vector<vector<int>> grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};

    vector<vector<int>> v = distNearestCell(grid);
    int n = 3,m = 4;

    for(int i = 0; i < n; i++){

        for(int j = 0;j < m; j++){

            cout << v[i][j] << " ";

        }

        cout << endl;

    }

    return 0;
}