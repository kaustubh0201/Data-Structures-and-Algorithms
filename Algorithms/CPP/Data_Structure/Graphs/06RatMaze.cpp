#include<iostream>

#define N 4

using namespace std;

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[][]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << sol[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSafe(int maze[][], int x, int y){
  
  if(x >= 0 and x <= N - 1 and y >= 0 and y <= N - 1 and maze[x][y] == 1)
    return true;

  return false;

}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
  if(x == N - 1 and y == N - 1 and maze[x][y] == 1){
    solve[x][y] = 1;
    return true;
  }

  if(isSafe(maze, x, y) == true){
    
    if(sol[x][y] == 1)
      return false;

    sol[x][y] = 1;

    if(solveMazeUtil(maze, x + 1, y, sol) == true)
      return true;

    if(solveMazeUtil(maze, x, y + 1, sol) == true)
      return true;

    sol[x][y] = 0;
    return false;
  }

  return false;
}

bool solveMaze(int maze[N][N]){
  int sol[N][N] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };

  if(solveMazeUtil(maze, 0, 0, sol) == false){
    cout << "No solution exist." << endl;
    return false;
  }

  printSolution(sol);
  return true;

}

int main(void){

    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    solveMaze(maze);

  return 0;
}
