/*
    Question 3: Two-Dimensional Array Traversal 
You are given a matrix of integers field of size height × width representing a game field, and also a matrix of integers
figure of size 3 × 3 representing a figure. Both matrices contain only 0s and 1s, where 1 means that the cell is
occupied, and 0 means that the cell is free.

You choose a position at the top of the game field where you put the figure and then drop it down. The figure falls 
down until it either reaches the ground (bottom of the field) or lands on an occupied cell, which blocks it from 
falling further. After the figure has stopped falling, some of the rows in the field may become fully occupied.


Your task is to find the dropping position such that at least one full row is formed. As a dropping position, you should return the column index of the cell in the game field which matches the top left corner of the figure’s 3 × 3 matrix. If there are multiple dropping positions satisfying the condition, feel free to return any of them. If there are no such dropping positions, return -1.

Note: The figure must be dropped so that its entire 3 × 3 matrix fits inside the field, even if part of the matrix is empty. 

Example

For
field = [[0, 0, 0],
         [0, 0, 0],
         [0, 0, 0],
         [1, 0, 0],
         [1, 1, 0]]
and
figure = [[0, 0, 1],
         [0, 1, 1],
         [0, 0, 1]]

the output should be solution(field, figure) = 0.

Because the field is a 3 x 3 matrix, the figure can be dropped only from position 0. When the figure stops falling, two fully occupied rows are formed, so dropping position 0 satisfies the condition.

example 1

For
field =  [[0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0],
          [0, 0, 0, 0, 0],
          [1, 1, 0, 1, 0],
          [1, 0, 1, 0, 1]]

and
figure = [[1, 1, 1],
          [1, 0, 1],
          [1, 0, 1]]

the output should be solution(field, figure) = 2.

The figure can be dropped from three positions: 0, 1, and 2. As you can see below, a fully occupied row will be formed only when dropping from position 2:

example 2

For
field =  [[0, 0, 0, 0],
          [0, 0, 0, 0],
          [0, 0, 0, 0],
          [1, 0, 0, 1],
          [1, 1, 0, 1]]

and
figure = [[1, 1, 0],
          [1, 0, 0],
          [1, 0, 0]]

the output should be solution(field, figure) = -1.

The figure can be dropped from two positions, 0 and 1, and in both cases, a fully occupied row won’t be obtained:

example 3

Note that the figure could technically form a full row if it was dropped one position further to the right, but 
that is not a valid dropping position, because the 3 x 3 figure matrix wouldn’t be fully contained within the field.

*/

#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

/*
   CodeSignal Q3: Tetris Figure Drop
   - Simulate gravity to find the lowest valid row (bestRow) for each column.
   - Check if that placement creates at least one full row.
*/

class Solution {
    // Helper: Can the figure exist at (r, c) without collision?
    bool isValid(int r, int c, int n, int m, vvi& field, vvi& figure) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(figure[i][j] == 1) {
                    // Check bounds (bottom) and collision with existing 1s
                    if(r+i >= n || field[r+i][c+j] == 1) return false;
                }
            }
        }
        return true;
    }

    // Helper: Does placing the figure at (r, c) complete any row?
    bool isRowFull(int r, int c, int n, int m, vvi& field, vvi& figure) {
        for(int i=0; i<3; i++) {
            int currRow = r + i;
            if(currRow >= n) continue; 
            
            bool full = true;
            for(int j=0; j<m; j++) {
                bool fieldCell = field[currRow][j] == 1;
                // Check if this column 'j' is part of the figure's column range [c, c+2]
                bool figureCell = (j >= c && j < c+3) ? (figure[i][j-c] == 1) : false;
                
                if(!fieldCell && !figureCell) {
                    full = false;
                    break;
                }
            }
            if(full) return true;
        }
        return false;
    }

public:
    int tetrisDrop(vvi field, vvi figure) {
        int n = field.size(), m = field[0].size();

        // Try dropping from every possible column 'j'
        for(int j=0; j <= m-3; j++) {
            int bestRow = -1;

            // Gravity: Find the lowest row 'i' where figure fits
            for(int i=0; i <= n-3; i++) {
                if(isValid(i, j, n, m, field, figure)) {
                    bestRow = i;
                } else {
                    break; // Stopped by obstacle
                }
            }
            // If it fits somewhere, check if it clears a line
            if(bestRow != -1) {
                if(isRowFull(bestRow, j, n, m, field, figure)) return j;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vvi field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {1, 0, 0},
        {1, 1, 0}
    };
    vvi figure = {
        {0, 0, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    
    // Expected Output: 0
    cout << s.tetrisDrop(field, figure) << endl; 

    vvi field2 = {
          {0, 0, 0, 0},
          {0, 0, 0, 0},
          {0, 0, 0, 0},
          {1, 0, 0, 1},
          {1, 1, 0, 1}
    };
    vvi figure2 = {
          {1, 1, 0},
          {1, 0, 0},
          {1, 0, 0}
    };
    
    // Expected Output: -1
    cout << s.tetrisDrop(field2, figure2) << endl; 

    return 0;
}