#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkBipartiteUtil(int node, vector<int> &color, vector<vector<int>> &adj){

    queue<int> q;
    q.push(node);
    color[node] = 1;

    while(not q.empty()){

        int front = q.front(); q.pop();

        for(int neighbor: adj[front]){

            if(color[neighbor] == color[front]){
                return false;
            }else if(color[neighbor] == -1){
                color[neighbor] = (color[front] == 1) ? 0 : 1;
                q.push(neighbor);
            }

        }

    }    

    return true;  

}

bool checkBipartite(vector<vector<int>> &adj, int V){

    vector<int> color(V, -1);

    for(int i = 0; i < V; i++){

        if(color[i] == -1){
            int ans = checkBipartiteUtil(i, color, adj);
            if(!ans)
                return false;
        }

    }

    return true;

}

int main(void){

    vector<vector<int>> adj = {
        {1},
        {2},
        {3},
        {4},
        {5},
        {0}
    };

    cout << checkBipartite(adj, 6) << endl;

    return 0;
}