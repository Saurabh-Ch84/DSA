#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

// approach-1 using normalisation and sorting
class Solution1 {
    void dfs(vector<vector<int>> &grid, int row, int col, vector<pair<int,int>> &islandCells, int rows, int cols) {
        grid[row][col] = 0;
        islandCells.push_back({row, col});
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; dir++) {
            int newRow = row + dRow[dir], newCol = col + dCol[dir];
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] == 0) continue;
            dfs(grid, newRow, newCol, islandCells, rows, cols);
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        unordered_set<string> uniqueIslands;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) 
                {
                    vector<pair<int,int>> islandCells;
                    dfs(grid, i, j, islandCells, rows, cols);
                    sort(islandCells.begin(), islandCells.end());
                    int baseRow = islandCells[0].first, baseCol = islandCells[0].second;
                    string shapeSignature = "";
                    for (auto &cell : islandCells)
                        shapeSignature += to_string(cell.first - baseRow) + "," + to_string(cell.second - baseCol) + ";";
                    uniqueIslands.insert(shapeSignature);
                }
            }
        }
        return uniqueIslands.size();
    }
};

//more optimised approach without string and sorting directly using a set and not unordered_set
class Solution2 {
    void dfs(vector<vector<int>> &grid, int row, int col, vector<pair<int,int>> &islandCells,
            int baseRow, int baseCol, int rows, int cols) 
    {
        grid[row][col] = 0;
        islandCells.push_back({row - baseRow, col - baseCol});
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; dir++){
            int newRow = row + dRow[dir], newCol = col + dCol[dir];
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] == 0) continue;
            dfs(grid, newRow, newCol, islandCells, baseRow, baseCol, rows, cols);
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<vector<pair<int,int>>> uniqueIslands; //use set not unordered_set
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) 
                {
                    vector<pair<int,int>> islandCells;
                    dfs(grid, i, j, islandCells, i, j, rows, cols);
                    uniqueIslands.insert(islandCells);
                }
            }
        }
        return uniqueIslands.size();
    }
};

// most optimised approach just unordered_set and string no sorting no vector nothing
class Solution3 {
    void dfs(vector<vector<int>> &grid, int row, int col, string &path,int rows, int cols) 
    {
        grid[row][col] = 0;
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        vector<char> moves={'U','R','D','L'};
        for (int dir = 0; dir < 4; dir++) {
            int newRow = row + dRow[dir], newCol = col + dCol[dir];
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] == 0) continue;
            path+=moves[dir];
            dfs(grid, newRow, newCol,path, rows, cols);
            path+='B';
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        unordered_set<string> uniqueIslands;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) 
                {
                    string path="S";
                    dfs(grid,i,j,path,rows,cols);
                    uniqueIslands.insert(path);
                }
            }
        }
        return uniqueIslands.size();
    }
};


int main(){

return 0;
}