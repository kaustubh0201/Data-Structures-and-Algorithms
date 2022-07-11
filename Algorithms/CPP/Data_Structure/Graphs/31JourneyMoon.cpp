#include<iostream>
#include<vector>

using namespace std;

int findParent(vector<int> &parent, int node){
        
    if(node == parent[node])
        return node;
        
    return parent[node] = findParent(parent, parent[node]);
    
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        rank[u]++;
        parent[v] = u;
    }
    
}

int journeyToTheMoon(vector<vector<int>> &astronaut, int n){

    vector<int> parent(n, 0);
    vector<int> rank(n, 0);
    
    for(int i = 0; i < n; i++)
        parent[i] = i;
    
    for(int i = 0; i < astronaut.size(); i++){
        
        int u = findParent(parent, astronaut[i][0]);
        int v = findParent(parent, astronaut[i][1]);
        
        if(u != v){
            unionSet(u, v, parent, rank);
        }        
    }
    
    vector<int> countKeep(n, 0);
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        countKeep[findParent(parent, parent[i])]++;
    }
    
    for(int i = 0; i < n; i++){
        
        if(countKeep[i] != 0){
            
            for(int j = i + 1; j < n; j++){
                
                if(countKeep[j] != 0){
                    
                    ans += (countKeep[i] * countKeep[j]);
                    
                }
                
            }
        }
        
    }
    
    return ans;
}

int main(void){

    vector<vector<int>> astronaut = {
        {0, 2},
        {1, 8},
        {1, 4},
        {2, 8},
        {2, 6},
        {3, 5},
        {6, 9}
    };

    int n = 10;

    cout << journeyToTheMoon(astronaut, n) << endl;

    return 0;
}