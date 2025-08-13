#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dPMatrix(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
            dPMatrix[i][0]=i;

        for(int j=0;j<=n;j++)    
            dPMatrix[0][j]=j;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word2[i - 1] == word1[j - 1])
                {
                    dPMatrix[i][j] = dPMatrix[i - 1][j - 1];
                }
                else
                {
                    dPMatrix[i][j] = 1 + min({dPMatrix[i - 1][j - 1], dPMatrix[i - 1][j], dPMatrix[i][j - 1]});
                }
            }
        }
        return dPMatrix[m][n];
    }
};

int main(){

return 0;
}