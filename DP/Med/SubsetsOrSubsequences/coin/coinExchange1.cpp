#include <iostream>
#include <vector>
#include<limits.h>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vvi dp(amount+1,vi(n,INT_MAX));
        for(int i=0;i<n;i++) dp[0][i]=0;

        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                int coin=coins[j];
                if(j>0) dp[i][j]=dp[i][j-1];
                if(i>=coin && dp[i-coin][j]!=INT_MAX)
                    dp[i][j]=min(dp[i][j],1+dp[i-coin][j]);
            }
        }
        return (dp[amount][n-1]==INT_MAX ? -1: dp[amount][n-1]);
    }
};

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
        int s = coins.size();
        vector<vector<long long>> tab(s, vector<long long>(amount+1, INT_MAX));
        
        for (int i = 0; i < s; i++) {
            tab[i][0] = 0;
            for (int j = 1; j <= amount; j++) {
                if (i > 0) tab[i][j] = tab[i-1][j];
                if (j >= coins[i] && tab[i][j-coins[i]] != INT_MAX) {
                    tab[i][j] = min(tab[i][j], 1 + tab[i][j-coins[i]]);
                }
            }
        }
        print(tab);
        return tab[s-1][amount] == INT_MAX ? -1 : static_cast<int>(tab[s-1][amount]);
    }

    void print(vector<vector<long long>> matrix)
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
    vector<int> coins;
    int s;
    cout << "Size:";
    cin >> s;
    int val;
    for (int i = 0; i < s; i++)
    {
        cin >> val;
        coins.push_back(val);
    }
    cout << "Amount:";
    cin >> val;
    Solution *obj = new Solution();
    cout << "The Minimum Number of coins required to obtain a change of Rs " << val << " is :- " << obj->coinChange(coins, val) << endl;
    return 0;
}