#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    void print(vector<vector<int>> matrix)
    {
        int rows = matrix.size();
        int cols=matrix[0].size();
        cout << "[ "<<endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j <cols; j++)
            {
                    cout << matrix[i][j] << " ";
            }
            cout << "] "<<endl;
        }
        cout << "]" << endl;
    }
public:
    int countSquares1(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans(matrix);
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                if((i==0||j==0) && ans[i][j]!=0)
                    count+=ans[i][j];

                else if(ans[i][j]==1)
                {
                    ans[i][j]=1+min({ans[i][j-1],ans[i-1][j],ans[i-1][j-1]});
                    count+=ans[i][j];
                }
            }
        }
        print(matrix);
        print(ans);
        return count;
    }
    int countSquares(vector<vector<int>> &matrix)
    {
        int count=0;
        print(matrix);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if((i==0||j==0) && matrix[i][j]!=0)
                    count+=matrix[i][j];

                else if(matrix[i][j]==1)
                {
                    matrix[i][j]=1+min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]});
                    count+=matrix[i][j];
                }
            }
        }
        print(matrix);
        return count;
    }
};

int main()
{
    vector<vector<int>> m={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    Solution *obj=new Solution();
    cout<<obj->countSquares(m);
    return 0;
}