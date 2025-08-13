#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<int>> matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();

        int ans=0;
        if(row==0 || col==0)
            return ans;
    
        if(row==1 && col==1)
            return matrix[0][0];

        if(row==1 && col>1)
        {
            for(int j=0;j<col;j++)
            {
                ans=max(ans,matrix[0][j]);
                if(ans==1)
                    break;
            }
            return ans;
        }

        if(row>1 && col==1)
        {
            for(int i=0;i<row;i++)
            {
                ans=max(ans,matrix[i][0]);
                if(ans==1)
                    break;
            }
            return ans;
        }

        vector<vector<int>> tab(matrix);
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
            {
                if(tab[i-1][j-1]>=1 && tab[i][j]>=1)
                {
                    ans=max(ans,tab[i-1][j-1]);
                    int flag=1;
                    for(int k=i-tab[i-1][j-1];k<i;k++)
                    {
                        if(tab[k][j]==0)
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1)
                        for(int l=j-tab[i-1][j-1];l<j;l++)
                        {
                            if(tab[i][l]==0)
                            {
                                flag=0;
                                break;
                            }
                        }
                    if(flag==1)
                    {
                        tab[i][j]=tab[i-1][j-1]+1;
                        ans=tab[i][j];
                    }
                }
            }
        print(matrix);
        print(tab);

        return ans*ans;
    }

    void print(vector<vector<int>> matrix)
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
};

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int m;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    Solution *obj = new Solution();
    cout<<"The area of the maixmal square is :"<<obj->maximalSquare(matrix)<<endl;
    return 0;
}