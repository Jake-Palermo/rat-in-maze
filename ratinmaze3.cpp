//Jake Palermo

#include <iostream>
#include <vector>

const int N = 10;

void printSolution(std::vector<std::vector<int>> result)
{
    for(std::vector<int> i:result){
        for(int j:i){
            std::cout<<" "<<j<<" ";
        }
        std::cout<<std::endl;
    }
}

void solveMazeUtil(std::vector<std::vector<int>> & maze, int x, int y,
                   std::vector<std::vector<int>> & result, std::vector<std::vector<std::vector<int>>> & solutions)
{
    if (x == 9 && y == 0 && maze[x][y] == 1) {
        result[x][y] = 1;
        solutions.push_back(result);
        result[x][y] = 0;
        return;
    }

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        if (result[x][y] == 1)
            return;

        result[x][y] = 1;
        solveMazeUtil(maze, x + 1, y, result, solutions);
        solveMazeUtil(maze, x - 1, y, result, solutions);
        solveMazeUtil(maze, x, y + 1, result, solutions);
        solveMazeUtil(maze, x, y - 1, result, solutions);

        result[x][y] = 0;
    }
}

void solveMaze(std::vector<std::vector<int>> maze)
{
    int default_value = 0;
    std::vector<std::vector<int>> result(N, std::vector<int>(N, default_value));
    std::vector<std::vector<std::vector<int>>> solutions;
    solveMazeUtil(maze, 0, 9, result, solutions);

    if (solutions.empty()) {
        std::cout<<"Solution doesn't exist";
        return;
    }

    for (int i = 0; i < solutions.size(); i++) {
        std::cout << "Solution " << i+1 << ":" << std::endl;
        printSolution(solutions[i]);
        std::cout << std::endl;
    }
}

int main()
{
    int default_value = 0;
    std::vector<std::vector<int>> maze =
    { { 1,0,0,0,0,0,1,1,1,1 },
      { 1,1,1,1,1,0,1,0,1,1 },
      { 1,1,1,0,1,0,1,1,1,1 },
      { 1,0,1,0,1,0,1,0,0,1 },
      { 1,0,1,0,1,0,1,0,1,1 },
      { 1,0,0,0,1,0,1,0,1,0 },
      { 1,0,1,1,1,0,1,0,1,0 },
      { 1,0,1,0,0,0,1,0,1,1 },
      { 0,1,1,1,1,1,1,0,1,1 },
      { 1,1,1,1,0,0,0,0,1,1 }
    };
    solveMaze(maze);
    return 0;
}
