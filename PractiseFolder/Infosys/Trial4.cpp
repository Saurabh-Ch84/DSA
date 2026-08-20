#include <bits/stdc++.h>
using namespace std;

using vint = vector<int>;
using vvint = vector<vint>;

class Solution
{
public:
    int minRefuelStops1(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        vector<long long> dp(n + 1, -1);
        dp[0] = startFuel; // 0 stops used, max distance = startFuel

        for (int i = 0; i < n; i++)
        {
            int pos = stations[i][0], fuel = stations[i][1];
            // iterate j backwards so we don't reuse this station twice in the same pass
            for (int j = i; j >= 0; j--)
            {
                if (dp[j] != -1 && dp[j] >= pos)
                {
                    dp[j + 1] = max(dp[j + 1], dp[j] + fuel);
                }
            }
        }

        for (int j = 0; j <= n; j++)
        {
            if (dp[j] >= target)
                return j;
        }
        return -1;
    }
    /*
        3. Dynamic Programming / Greedy – Minimum Refueling Stops (Modified)

        A modified version of the classic Minimum Number of Refueling Stops problem.

        Given target, startFuel, and gas stations, find the minimum number of refueling stops needed
        to reach the destination.

        Additional Constraint:

        If you refuel at station i, you cannot refuel at station i-1 or i+1.
        Return the minimum number of stops required, or -1 if it is impossible to reach the target.
    */
    int minRefuelStops2(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        const long long NEG = -1;

        // dp0[j] = max distance with j stops, last station considered was NOT taken
        // dp1[j] = max distance with j stops, last station considered WAS taken
        vector<long long> dp0(n + 1, NEG), dp1(n + 1, NEG);
        dp0[0] = startFuel;

        for (int i = 0; i < n; i++)
        {
            int pos = stations[i][0], fuel = stations[i][1];
            vector<long long> new_dp0(n + 1, NEG), new_dp1(n + 1, NEG);

            for (int j = 0; j <= n; j++)
            {
                // Option A: skip station i -> "last taken" becomes 0
                long long best = max(dp0[j], dp1[j]);
                new_dp0[j] = best;

                // Option B: take station i -> only legal if previous station wasn't taken
                if (j >= 1 && dp0[j - 1] != NEG && dp0[j - 1] >= pos)
                {
                    new_dp1[j] = dp0[j - 1] + fuel;
                }
            }

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        for (int j = 0; j <= n; j++)
        {
            if ((dp0[j] != NEG && dp0[j] >= target) ||
                (dp1[j] != NEG && dp1[j] >= target))
                return j;
        }
        return -1;
    }

    /*
        1. Dynamic Programming – Longest Subsequence with Target Sum + Cooldown

        Given an array nums of positive integers and an integer target, return the maximum length of a subsequence whose
        sum is exactly target.

        Additional Constraint:

        If you choose nums[i], you cannot choose any of the next nums[i] % 4 elements.
        Return -1 if no valid subsequence exists.
    */
    int negInf = -1e7;
    int recursion(int i, int n, int target, vector<int> &arr, vvint &dp)
    {
        if (i >= n)
            return (target ? negInf : 0);
        if (dp[i][target] != -1)
            return dp[i][target];
        int skip = recursion(i + 1, n, target, arr, dp), take = negInf;
        if (target >= arr[i])
            take = 1 + recursion(i + 1 + arr[i] % 4, n, target - arr[i], arr, dp);
        return dp[i][target] = max(skip, take);
    }
    int longestSubSequenceWithTargetSum(vector<int> arr, int target)
    {
        int n = arr.size();
        vvint dp(n + 1, vint(target + 1, -1));
        int val = recursion(0, n, target, arr, dp);
        return (val < 0 ? -1 : val);
    }

    /*
        2. Dynamic Programming / Strings – Minimum Cost to Balance Brackets

        Given: A bracket string containing [ and ] and A mask string containing:
        P → Permanent characters (cannot be moved or modified)
        p → Pencil characters

        Allowed operations on pencil characters:

        Swap any two pencil characters → Cost = 1
        Change [ to ] or vice versa → Cost = 2

        Return the minimum total cost to make the bracket sequence balanced, or -1 if impossible.

        [] is balanced where as ][ is not.
    */
};

class Solution1
{   
    // better than brute
    int posInf = 1e7;
    bool isBalanced(string &brackets, int n)
    {
        stack<int> st;
        int i = 0;
        while (i < n)
        {
            char b = brackets[i++];
            if (b == '[')
                st.push(b);
            else
            {
                if (st.empty())
                    return 0;
                st.pop();
            }
        }
        return st.empty();
    }
    int recursion(int i, int balance, int open, int close, int n, string &brackets, string &mask)
    {
        if (i >= n)
            return (balance ? posInf : 0);
        if (balance > 0)
            return posInf;

        int value = (brackets[i] == ']' ? 1 : -1);
        bool isPencil = (mask[i] == 'p');
        bool isOpenChar = (brackets[i] == '[');

        // self always leaves the pool once this position is decided, in EVERY branch
        int openAfterSelf = open - ((isPencil && isOpenChar) ? 1 : 0);
        int closeAfterSelf = close - ((isPencil && !isOpenChar) ? 1 : 0);

        int skip = recursion(i + 1, balance + value, openAfterSelf, closeAfterSelf, n, brackets, mask);
        int take = posInf;

        if (isPencil)
        {
            if (isOpenChar)
            {
                // flip '[' -> ']'
                if (closeAfterSelf > 0) // swap: additionally consumes one 'close' partner
                    take = min(take, 1 + recursion(i + 1, balance - value, openAfterSelf, closeAfterSelf - 1, n, brackets, mask));
                take = min(take, 2 + recursion(i + 1, balance - value, openAfterSelf, closeAfterSelf, n, brackets, mask)); // lone flip
            }
            else
            {
                // flip ']' -> '['
                if (openAfterSelf > 0)
                    take = min(take, 1 + recursion(i + 1, balance - value, openAfterSelf - 1, closeAfterSelf, n, brackets, mask));
                take = min(take, 2 + recursion(i + 1, balance - value, openAfterSelf, closeAfterSelf, n, brackets, mask));
            }
        }

        return min(skip, take);
    }

public:
    int findMinCostToBalanceString(string brackets, string mask)
    {
        // exponential complexity.
        int n = mask.size();
        if (n % 2 == 1)
            return -1;
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask[i] == 'P')
                continue;
            if (brackets[i] == '[')
                open++;
            else
                close++;
        }
        int ans = recursion(0, 0, open, close, n, brackets, mask);
        return (ans >= posInf ? -1 : ans);
    }
};

class Solution2{
    // optimal
    /*
        2. Dynamic Programming / Strings – Minimum Cost to Balance Brackets

        Given: A bracket string containing [ and ] and A mask string containing:
        P → Permanent characters (cannot be moved or modified)
        p → Pencil characters

        Allowed operations on pencil characters:

        Swap any two pencil characters → Cost = 1
        Change [ to ] or vice versa → Cost = 2

        Return the minimum total cost to make the bracket sequence balanced, or -1 if impossible.

        [] is balanced where as ][ is not.
    */
    int posInf = 1e7;

    bool isBalanced(string &brackets, int n)
    {
        stack<int> st;
        int i = 0;
        while (i < n)
        {
            char b = brackets[i++];
            if (b == '[')
                st.push(b);
            else
            {
                if (st.empty())
                    return 0;
                st.pop();
            }
        }
        return st.empty();
    }

    vector<vector<vector<int>>> dp; // dp[i][balance+n][diff+n]

    int recursion(int i, int balance, int diff, int n, string &brackets, string &mask)
    {
        if (i >= n)
            return (balance ? posInf : 0);
        if (balance > 0)
            return posInf;

        int &memo = dp[i][balance + n][diff + n];
        if (memo != -1)
            return memo;

        int value = (brackets[i] == ']' ? 1 : -1);

        // option 1: leave brackets[i] as is
        int skip = recursion(i + 1, balance + value, diff, n, brackets, mask);

        // option 2: flip it (only if pencil)
        int take = posInf;
        if (mask[i] == 'p')
        {
            int marginal, newDiff;
            if (brackets[i] == '[')
            {
                // this flip turns a '[' into ']', so it increases x (count of flipped '[' pencils)
                marginal = (diff >= 0 ? 2 : -1);
                newDiff = diff + 1;
            }
            else
            {
                // this flip turns a ']' into '[', so it increases y (count of flipped ']' pencils)
                marginal = (diff <= 0 ? 2 : -1);
                newDiff = diff - 1;
            }
            take = marginal + recursion(i + 1, balance - value, newDiff, n, brackets, mask);
        }

        return memo = min(skip, take);
    }

public:
    int findMinCostToBalanceString(string brackets, string mask)
    {
        int n = mask.size();
        if (n % 2 == 1)
            return -1;

        // dims: i:[0,n], balance:[-n,n]->offset n, diff:[-n,n]->offset n
        dp.assign(n + 1, vector<vector<int>>(2 * n + 1, vector<int>(2 * n + 1, -1)));

        int ans = recursion(0, 0, 0, n, brackets, mask);
        return (ans >= posInf ? -1 : ans);
    }
};

/*
        2. Dynamic Programming / Strings – Minimum Cost to Balance Brackets

        Given: A bracket string containing [ and ] and A mask string containing:
        P → Permanent characters (cannot be moved or modified)
        p → Pencil characters

        Allowed operations on pencil characters:

        Swap any two pencil characters → Cost = 1
        Change [ to ] or vice versa → Cost = 2

        Return the minimum total cost to make the bracket sequence balanced, or -1 if impossible.

        [] is balanced where as ][ is not.
    */
class Solution3{
    // Brute-force-Backtracking
   int posInf=1e7;
    bool isBalanced(string &brackets,int n){  
        stack<int> st;
        int i=0;
        while(i<n){
            char b=brackets[i++];
            if(b=='[') st.push(b);
            else{
                if(st.empty()) return 0;
                st.pop();
            }
        }
        return st.empty();
    }
    int recursion(int i,int balance,int n,string &brackets,string &mask){
        if(i>=n) return (balance? posInf: 0);
        if(balance>0) return posInf;
        int count=posInf, value=(brackets[i]==']'? 1:-1);
        int skip=recursion(i+1,balance+value,n,brackets,mask), take=posInf;
        if(mask[i]=='p'){
            for(int j=i+1;j<n;j++){
                if(mask[j]=='P' || brackets[j]==brackets[i]) continue;
                swap(brackets[i],brackets[j]);
                int swapCost=1+recursion(i+1,balance-value,n,brackets,mask);
                take=min(take,swapCost);
                swap(brackets[i],brackets[j]);
            }
            brackets[i]=(brackets[i]=='['?']':'[');
            int flipCost=2+recursion(i+1,balance-value,n,brackets,mask);
            brackets[i]=(brackets[i]=='['?']':'[');
            take=min(take,flipCost);
        }
        return min(skip,take);
    }
        public:
    int findMinCostToBalanceString(string brackets,string mask){
        int n=mask.size();
        if(n%2==1) return -1;
        int ans=recursion(0,0,n,brackets,mask);
        return (ans>=posInf? -1: ans);
    }
};

int main()
{
    Solution2 s;
    cout << s.findMinCostToBalanceString("[]", "pp") << endl;
    cout << s.findMinCostToBalanceString("[[", "pp") << endl;
    cout << s.findMinCostToBalanceString("][", "pp") << endl;
    cout << s.findMinCostToBalanceString("[]", "Pp") << endl;
    cout << s.findMinCostToBalanceString("[[", "pP") << endl;
    cout << s.findMinCostToBalanceString("]]][[[[", "ppppppp") << endl;
    cout << s.findMinCostToBalanceString("]]][[[", "pppppp") << endl;
    return 0;
}