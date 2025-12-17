#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits> 
#include <stack>

using namespace std;

/*
    PROBLEM: Maximum Valid Expression Value (Question 3)

    Given a 2D matrix 'puzzle' consisting of single digits ('0'-'9') and operators ('+', '-').
    Find the MAXIMUM value evaluated from any "valid expression" found in the grid.

    A "valid expression":
    1. Must start from a cell with a numeric value.
    2. Must go ONLY Left-to-Right OR ONLY Top-to-Bottom (no turning).
    3. Cannot contain consecutive operators (e.g., "3++2" is invalid).
    4. Cannot contain consecutive numbers (e.g., "3 4 + 2" is invalid).
    5. Must end with a number (standard math expression rules).

    CONSTRAINTS:
    - 1 <= puzzle.length, puzzle[i].length <= 50
    - The grid contains only digits and '+', '-' chars.
    - At least one numeric value exists.
*/

// Helper to evaluate string and find max valid prefix value
long long evaluateExpression(string expression){
    if (expression.empty()) return LLONG_MIN;

    stack<long long> s; // Use long long for safety
    char op = '#';      // '#' indicates no active operator
    long long currentMax = LLONG_MIN; 

    for(char ch: expression){
        if(isdigit(ch)){
            int num = ch - '0';
            
            if(s.empty()) {
                // First number in the expression
                s.push(num);
                currentMax = max(currentMax, (long long)num);
            }
            else if(op == '#') {
                // Case: Consecutive numbers (e.g., "3 4") -> INVALID.
                // Stop and return whatever max we found so far.
                return currentMax; 
            }
            else {
                // Perform the operation
                long long a = s.top(); s.pop();
                long long b = num;
                long long res = 0;
                
                if(op == '+') res = a + b;
                else res = a - b;
                
                s.push(res);
                currentMax = max(currentMax, res); // Update max after every valid step
                op = '#'; // Reset operator
            }
        }
        else { 
            // It is an operator (+ or -)
            if (op != '#') {
                // Case: Consecutive operators (e.g., "3++2") -> INVALID.
                // Stop and return max found so far.
                return currentMax;
            }
            op = ch;
        }
    }
    
    // Return the max value found during the process
    return currentMax;
}

int solution(vector<vector<char>> puzzle) {
    int n = puzzle.size();
    int m = puzzle[0].size();
    long long globalMax = LLONG_MIN; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch = puzzle[i][j];
            
            // Only start building if the cell is a number
            if(isdigit(ch)){
                
                // 1. Build and check Horizontal
                string horizontal;
                for(int k = j; k < m; k++)
                    horizontal.push_back(puzzle[i][k]);
                
                globalMax = max(globalMax, evaluateExpression(horizontal));

                // 2. Build and check Vertical
                string vertical;
                for(int k = i; k < n; k++)
                    vertical.push_back(puzzle[k][j]);
                
                globalMax = max(globalMax, evaluateExpression(vertical));
            }
        }
    }
    
    return (int)globalMax;
}

int main() {
    // --- Test Case 1 ---
    vector<vector<char>> t1 = {
        {'9', '+', '3', '-', '2'},
        {'+', '2', '+', '3', '+'},
        {'1', '-', '4', '-', '4'},
        {'-', '2', '-', '7', '+'},
        {'4', '+', '3', '+', '9'},
        {'+', '1', '+', '8', '-'}
    };
    cout << "Test Case 1: " << solution(t1) << " (Expected: 16)" << endl;

    // --- Test Case 2 ---
    vector<vector<char>> t2 = {
        {'5', '-', '2'},
        {'+', '0', '0'},
        {'3', '0', '0'}
    };
    cout << "Test Case 2: " << solution(t2) << " (Expected: 8)" << endl;

    // --- Test Case 3 ---
    vector<vector<char>> t3 = {
        {'7'}
    };
    cout << "Test Case 3: " << solution(t3) << " (Expected: 7)" << endl;

    return 0;
}