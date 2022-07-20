#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int assemblyUtil(vector<vector<int>> &assembleTime, vector<vector<int>> &turningTime, vector<int> &entryTime, vector<int> &exitTime){

    int n = assembleTime[0].size();

    vector<int> T1(n), T2(n);

    T1[0] = entryTime[0] + assembleTime[0][0];
    T2[0] = entryTime[1] + assembleTime[1][0];

    for(int i = 1; i < n; i++){

        T1[i] = min(T1[i - 1] + assembleTime[0][i], T1[i - 1] + assembleTime[0][i] + turningTime[1][i]);
        T2[i] = min(T2[i - 1] + assembleTime[0][i], T2[i - 1] + assembleTime[1][i] + turningTime[0][i]);

    }

    return min(T1[n - 1] + exitTime[0], T2[n - 1] + exitTime[1]);
}

int assemblyLineScheduling(vector<vector<int>> &assembleTime, vector<vector<int>> &turningTime, vector<int> &entryTime, vector<int> &exitTime){
    
    return assemblyUtil(assembleTime, turningTime, entryTime, exitTime);

}

int main(void){

    vector<vector<int>> assembleTime = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    vector<vector<int>> turningTime = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    vector<int> entryTime = {10, 12};
    vector<int> exitTime = {18, 7};

    cout << assemblyLineScheduling(assembleTime, turningTime, entryTime, exitTime) << endl;

    return 0;
}