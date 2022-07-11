#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Graph{
    public:
        unordered_map<int, vector<int>> adj;
        int n;

        Graph(int n){
            this->n = n;
        }

        void addEdge(int u, int v){

            adj[u].push_back(v);

        }
};

vector<int> completeJob(unordered_map<int, vector<int>> &adj, int n){

    vector<int> inDegree(n, 0);
    vector<int> jobTime(n);

    for(int i = 0; i < n; i++){

        for(auto j: adj[i]){

            inDegree[j]++;

        }

    }

    queue<int> q;

    for(int i = 0; i < n; i++){

        if(inDegree[i] == 0){
            
            q.push(i);
            jobTime[i] = 1;

        }

    }

    while(not q.empty()){

        int front = q.front();
        q.pop();

        for(auto x: adj[front]){
            
            inDegree[x]--;

            if(inDegree[x] == 0){
                jobTime[x] = jobTime[front] + 1;
                q.push(x);
            }

        }

    }

    return jobTime;


}

int main(void){

    int n = 10;

    Graph g(n);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 9);

    vector<int> jobTime = completeJob(g.adj, n);

    for(auto x: jobTime)
        cout << x << " ";
    cout << endl;

    return 0;
}