#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= coins.size(); ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + (j - coins[i - 1] < 0 ? 0 : dp[i][j - coins[i - 1]]);
            }
        }
        print(dp);
        return dp[coins.size()][amount];
    }

    int change1(int amount, vector<int> &coins)
    {
        int s = coins.size();
        if (amount == 0 && s == 0)
            return 1;
        if (amount > 0 && s == 0)
            return 0;
        vector<vector<int>> tab(s, vector<int>(amount + 1));
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0)
                {
                    tab[i][j] = 1;
                }
                else if (coins[i] > j)
                {
                    if (i == 0)
                        tab[i][j] = 0;
                    else
                        tab[i][j] = tab[i - 1][j];
                }
                else
                {
                    if (i == 0)
                        tab[i][j] = tab[i][j - coins[i]];
                    else
                        tab[i][j] = tab[i - 1][j] + tab[i][j - coins[i]];
                }
            }
        }
        print(tab);
        return tab[s - 1][amount];
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
    cout << "the Number of ways to obtain a change of Rs " << val << " is :- " << obj->change(val, coins) << endl;
    cout << "the Number of ways to obtain a change of Rs " << val << " is :- " << obj->change1(val, coins) << endl;
    return 0;
}