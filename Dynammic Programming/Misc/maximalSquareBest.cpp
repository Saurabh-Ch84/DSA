#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int ans = 0;
        if (row == 0 || col == 0)
            return ans;

        if (row == 1 && col == 1)
            return int(matrix[0][0]);

        int typecast;
        if (row == 1 && col > 1)
        {
            for (int j = 0; j < col; j++)
            {
                typecast= 1? matrix[0][j]=='1':0;
                ans = max(ans,typecast);
                if (ans == 1)
                    break;
            }
            return ans;
        }

        if (row > 1 && col == 1)
        {
            for (int i = 0; i < row; i++)
            {
                typecast= 1? matrix[i][0]=='1':0;
                ans = max(ans,typecast);
                if (ans == 1)
                    break;
            }
            return ans;
        }

        vector<int> sol(col, 0);
        int diag = matrix[0][0] == '0' ? 0 : 1;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int temp = sol[j];
                if (i == 0 || j == 0)
                {
                    if (matrix[i][j] == '1')
                    {
                        sol[j] = 1;
                        ans = max(ans, sol[j]);
                    }
                    else
                        sol[j] = 0;
                }
                else
                {
                    if (matrix[i][j] == '1')
                    {
                        sol[j] = 1 + min({sol[j], sol[j - 1], diag});
                        ans = max(ans, sol[j]);
                    }
                    else
                        sol[j]=0;
                }
                diag = (j == col - 1) ? sol[0] : temp;
            }
        }
        print(matrix);
        print(sol);

        return ans * ans;
    }

    void print(vector<vector<char>> matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        cout << "[" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j < cols; j++)
            {
                if (j == cols - 1)
                    cout << matrix[i][j];
                else
                    cout << matrix[i][j] << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
    void print(vector<int> matrix)
    {
        int rows = matrix.size();
        cout << "[" << endl;
        for (int i = 0; i < rows; i++)
        {
            {
                if (i == rows- 1)
                    cout << matrix[i];
                else
                    cout << matrix[i] << ",";
            }
        }
        cout << "]" << endl;
    }    
};

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int m;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    Solution *obj = new Solution();
    cout << "The area of the maixmal square is :" << obj->maximalSquare(matrix) << endl;
    return 0;
}