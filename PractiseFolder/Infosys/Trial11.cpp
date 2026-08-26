#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using vpii=vector<pii>;
using vint=vector<int>;
using vvint=vector<vint>;
using vvvint=vector<vvint>;
using vvvvint=vector<vvvint>;
using vll=vector<long long>;
using vvll=vector<vll>;
using vstr=vector<string>;

int mod=1e9+7;
long long inf=1e15;

/*

    You are given a list of **N** stock prices `p[0], p[1], ..., p[N-1]` over **N** days. 
    You may buy and sell the stock any number of times, but you can hold at most **1** share at a time.

    Each day you hold a stock position, you pay a **per-day holding fee F**. This means if you buy a stock on day **k** and 
    sell it on day **j** (where **j >= k**), you incur a total holding fee of **(j - k) * F**. Additionally, each time you 
    sell a stock, you incur a **fixed sell cost C**.

    You may buy and sell on the same day (**j = k**), which counts as a transaction, incurs the sell cost **C**, and has a 
    holding fee of **(k - k) * F = 0**.

    Find the **maximum total profit** you can achieve by optimally selecting a sequence of buy and sell operations.

    **Input Format**  
        - The first line contains an integer, **N**, denoting the number of days for which stock prices are given.  
        - The second line contains an integer, **F**, denoting the per-day holding fee incurred for each day a stock is held.  
        - The third line contains an integer, **C**, denoting the fixed sell cost incurred each time you sell a stock.  
        - The fourth line contains **N** space-separated integers representing the stock prices `p[0], p[1], ..., p[N-1]`.

    **Output Format**  
        - Print a single integer representing the maximum total profit achievable.
*/

/*
    You are given a string **S** (lowercase letters) and a dictionary of **W** words. Partition **S** into the 
    **maximum number of non-overlapping substrings**, each of which is a word in the dictionary. Words may be **reused**.

    If **S** cannot be fully partitioned using dictionary words, consider the **maximum prefix** of **S** that can be fully partitioned.

    **Total score = max_parts × 1000 + max_prefix_len**, where:  
    - **max_parts** is the maximum number of substrings.  
    - **max_prefix_len** is the length of the longest prefix that can be fully partitioned.

    Find the **maximum total score** achievable.

    **Input Format**  
        - The first line contains a string, **S**, denoting the input string.  
        - The second line contains an integer, **W**, denoting the number of words.  
        - The next **W** lines each contain a string representing a word in the dictionary.

    **Output Format**  
        - Print a single integer representing the maximum total score achievable.

    Constraints: 
        1 <= |s| <= 500
        1 <= w <= 200
        1 <= words[i] <= 20

    Case 1
        Input
            aaba
            3
            a a b
        Output  4004
        Explanation
        The string, "aaba" (length 4) can be fully partitioned using dictionary words. We can partition it into 
        "a", "a", "b", "a" (4 parts) or "aa", "b", "a" (3 parts). The maximum number of parts is 4. The length of the valid prefix is 4. 
        The output integer is 4 * 1000 + 4 = 4004.
*/

/*
    You are given daily prices p[1...n] of a single painting.
    You can buy and resell **at most twice**, but the second buy must be in a **different month** than the first sell 
    (months given as m[i] for each day).

    Find the **maximum total profit**.

    **Input Format**
        The first line contains an integer, n, denoting the number of days.
        The second line contains N space-separated integers, where the i-th integer denotes p[i], the price on day i.
        The third line contains N space-separated integers, where the i-th integer denotes m[i], the month corresponding to day i.

    **Constraints**
        1 <= n <= 10^5
        10^{-9} <= p[i] <= 10^9
        1 <= m[i] <= 12

    **Sample Test Cases**
        Case 1
    **Input:**
        ```
        5
        10 20 15 30 40
        1 1 2 2 2
        ```

    **Output:**
    ```
    35
    ```
    **Explanation:**
        Buy at 10 (day 1, month 1), sell at 20 (day 2, month 1). Profit = 10.
        Buy at 15 (day 3, month 2), sell at 40 (day 5, month 2). Profit = 25.
        First sell month is 1, second buy month is 2, which are different. Total profit = 10 + 25 = 35.
*/

/*
    You are given a tree $T$ of size $N$ where some nodes have an "on" light and some have an "off" light.

    Find the **maximum number of nodes** we can visit in a tree, given you can pass through a node only if it has an "on" 
    light and that you can turn **on** at most $k$ lights in it.

    **Note:**
    * If node $i$ light is off it has to be turned on so we can pass.

    **Input Format**
        The first line contains a integer, $n$, denoting the size of the array.
        The second line contains an integer, the number of edges in the tree.
        The third line contains a integer, $k$, denoting the maximum number of light you can switch on.
        Each line of the $n$ sub-sequent lines (where $0 \le i < n$) contains a integer, $light[i]$.
        Each of the $m$ lines contains 2 space-separated integers, representing size of edges.

**Constraints**
        $1 \le n \le 500$
        $0 \le m \le n - 1$
        $1 \le k \le 500$
        $0 \le light[i] \le 1$

    Case-1
    Input:
        2
        1
        1
        0
        1
        1 2
    Output: 2
    Explanation: First we turn the light at node 1 so we can stand on it then we go to node 2

    Case-2
    Input:
        2
        1
        1
        0
        0
        1 2
    Output: 1
    Explanation: We turn the light at node 1 but we can't turn it at node 2 cause no more k so the answer is 1
*/

/*
    You are given an array A of N integers, an integer K, and an integer X.
    You can perform an operation at most K times.

    In one operation:
        choose an index i
        replace A[i] with A[i] XOR X
        Your task is to maximize the total sum of the array.

    Find the maximum total sum achievable.

    Input Format
        First line: integer N
        Second line: integer K
        Third line: integer X
        Fourth line: N space-separated integers

    Constraints
        1 <= N <= 10^5
        0 <= K <= N
        0 <= X <= 10^5
        0 <= A[i] <= 10^9

        Test Case 1

        Input:

        3
        1
        3
        1 2 3
        Output: 7
        Explanation:

        1 XOR 3 = 2
        New array = [2, 2, 3]
        Sum = 7

        Test Case 2

        Input:

        3
        5
        5
        10 20 30
        Output: 65

        Test Case 3

        Input:

        3
        2
        1
        5 6 7
        Output: 19
*/

/*
    You roll a k-sided die exactly n times.
    Find the number of sequences such that:

    Sum of all rolls is exactly t
    Absolute difference between adjacent rolls is exactly 1
    Return answer modulo 10^9 + 7.

    Input Format

    First line: integer n
    Second line: integer k
    Third line: integer t

        Constraints

        1 <= n <= 100
        1 <= k <= 50
        1 <= t <= 5000

    Test Case 1

    Input:
    3
    3
    6
    Output:
    2

    Explanation: Valid sequences:

    1 2 3
    3 2 1

    Test Case 2

    Input:
    2
    5
    10
    Output:

    0

    Test Case 3

    Input:
    4
    4
    10
    Output:

    4
    Valid sequences:

    1 2 3 4
    4 3 2 1
    2 3 2 3
    3 2 3 2
*/

/*
    You are given strings S (length N) and T (length M), compute the minimum cost to transform S into T using 
    three operations:
        Insert character c: cost ins[c]
        Delete character c: cost del[c]
        Replace character c with c': cost rep[c][c'] (rep[c][c] = 0)
    All costs are non-negative.
    Find the minimum cost to transform S into T.
    Note: Characters are lowercase English letters (a-z)
    Input Format
        The first line contains a string, s, denoting the source string.
        The second line contains a string, t, denoting the target string.
        Each line i of the 26 subsequent lines (where 0 <= i < 26) contains an integer, ins[i].
        Each line i of the 26 subsequent lines (where 0 <= i < 26) contains an integer, del[i].
        The last of the 26 lines contains 26 space-separated integers, representing row i of rep.
*/

/*
    You are given an array `a` of size `n` and a range `n * 2` matrix.
    In one operation you can make any element `a[i]` in the array equal to some element `x` such that `x` 
    is between `range[i][0]` and `range[i][1]`, the cost of such operation is `abs(a[i] - x) * GCD(a[i], x)` or 
    you can leave `a[i]` as it is with cost 0.

    Find the **minimum total cost** to make the array a non-decreasing.

    **Notes:**
        - `GCD(a[i], x)` is the Greatest Common Divisor of `a[i]` and `x`.
        - It's guaranteed that an answer exists and that `range[i][1] - range[i][0] + 1 <= 100` for any `i`.

    **Input Format**

        The first line contains an integer, `n`, denoting the number of elements in `a`.
        Each line `i` of the `n` subsequent lines (where `0 <= i < n`) contains an integer, `a[i]`. 
        The initial value of the `i-th` element in `a` is `a[i]`.

    **Sample Test Cases**

    **Case 1**

        **Input:**
        ```
        3
        1
        2
        3
        1 1
        1 1 
        1 1
        ```
        **Output:**
        ```
        0
        ```

        **Explanation:**
        No need to change any element, the array is already non-decreasing so the answer is 0.

    **Case 2**

        **Input:**
        ```
        3 
        1
        2
        1
        1 3
        1 3
        1 3
        ```
        **Output:**
        ```
        1
        ```
        **Explanation:**
        Change the 3rd element to 2, the cost of this change is `abs(2-1) * GCD(2, 1) = 1`.
*/

/*
    You are given two integers N and M, where N is even.
    Count the number of arrays A of length N consisting of positive integers that satisfy the following conditions:

    For every valid index i (where 0 ≤ i < N/2), the product of the adjacent pair satisfies 1 ≤ A[2i] × A[2i+1] ≤ M.
    Within each pair, the first element is at most the second: A[2i] ≤ A[2i+1].
    The first element of each pair differs from the first element of the next pair: A[2i] ≠ A[2i+2] for all valid i.

    Find the number of arrays A modulo 10⁹+7.

    Input Format
        The first line contains an integer, N, denoting the length of array A.
        The second line contains an integer, M, denoting the maximum number arrays A elements can reach.

    Constraints
        2 ≤ N ≤ 10⁵
*/

/*
    You are given two integers N and M, along with an array A of N integers and an array B of M integers.
    Count the number of ways to select a subsequence S from A and a subsequence D from B such that: S and D have the same length.
    When you concatenate S followed by D (in that order), the resulting sequence forms a palindrome.
    Find the number of palindromes modulo 10^9+7.
*/

class Solution{
    int recursion(int i,int canBuy,int n,int f,int c,vint &arr,vvint &dp){
        if(i==n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int ans=0;
        if(canBuy){
            int buyNow=-arr[i]+i*f+recursion(i+1,0,n,f,c,arr,dp);
            int buyLater=recursion(i+1,1,n,f,c,arr,dp);
            ans=max(buyNow,buyLater);
        }
        else{
            int sellLater=recursion(i+1,0,n,f,c,arr,dp);
            int sellNow=arr[i]-i*f-c+recursion(i+1,1,n,f,c,arr,dp);
            ans=max(sellNow,sellLater);
        }
        return dp[i][canBuy]=ans;
    }
    int recursion(int i,int j,int canBuy,int m,int n,int k,vint &profit,vint &month,vvvvint &dp){
        if(i==n) return 0;
        if(j==k) return 0;
        if(dp[i][j][canBuy][m+1]!=-1) return dp[i][j][canBuy][m+1];
        int ans=0;
        if(canBuy){
            int buyNow=0;
            if(month[i]!=m) buyNow=-profit[i]+recursion(i+1,j,0,month[i],n,k,profit,month,dp);
            int buyLater=recursion(i+1,j,1,m,n,k,profit,month,dp);
            ans=max(buyNow,buyLater);
        }
        else{
            int sellLater=recursion(i+1,j,0,m,n,k,profit,month,dp);
            int sellNow=profit[i]+recursion(i+1,j+1,1,month[i],n,k,profit,month,dp);
            ans=max(sellNow,sellLater);
        }
        return dp[i][j][canBuy][m+1]=ans;
    }
    int DFS(int u,int p,int k,vvint &adjlist,vint &light){
        k=k-(1-light[u]);
        if(k<0) return 0;
        int count=1;
        for(int &v: adjlist[u]){
            if(v==p) continue;
            int nextCount=1+DFS(v,u,k,adjlist,light);
            count=max(count,nextCount);
        }
        return count;
    }
    long long recursion(int i,int prevDie,int k,int n,int t,vvvint &dp){
        if(i==n) return (t? 0:1);
        if(t<=0) return 0;
        if(dp[i][prevDie][t]!=-1) return dp[i][prevDie][t];
        long long takeGreater=0, takeSmaller=0;
        if(prevDie>1) takeSmaller=recursion(i+1,prevDie-1,k,n,t-(prevDie-1),dp);
        if(prevDie<k) takeGreater=recursion(i+1,prevDie+1,k,n,t-(prevDie+1),dp);
        return dp[i][prevDie][t]=(takeSmaller+takeGreater)%mod;
    }
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    long long costFun(int a,int x){
        return 1LL*abs(a-x)*gcd(a,x);
    }
    long long recursion(int i,int p,int n,vint &nums,vvint &ranges,vector<unordered_map<int,long long>> &memo){
        if(i==n) return 0;
        if(memo[i].count(p)) return memo[i][p];
        long long skip=inf, take=inf;
        if(p<=nums[i]) skip=recursion(i+1,nums[i],n,nums,ranges,memo);
        for(int val=ranges[i][0];val<=ranges[i][1];val++){
            if(val<p) continue;
            long long next=recursion(i+1,val,n,nums,ranges,memo)+costFun(nums[i],val);
            take=min(take,next);
        }
        return memo[i][p]=min(take,skip);
    }
        public:
    int maxProfitAchievable(vint arr,int f,int c){
        int n=arr.size();
        vvint dp(n,vint(2,-1));
        return recursion(0,1,n,f,c,arr,dp);
    }
    int maxTotalScore(string s,vstr words){
        int n=s.length();
        unordered_set<string> hashSet;
        for(string &word: words)
            hashSet.insert(word);
        vint dp(n+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i;j>=max(0,i-20+1);j--){
                int l=i-j+1;
                if(hashSet.count(s.substr(j,l)) && dp[j]!=-1)
                    dp[i+1]=max(dp[i+1],dp[j]+1);
            }
        }
        int maxPrefixLen=0, count=0;
        for(int i=n;i>0;i--){
            if(dp[i]!=-1){
                maxPrefixLen=i;
                count=dp[i];
                break;
            }
        }
        return count*1000+maxPrefixLen;
    }
    int maxProfit(vint profit,vint month){
        int n=profit.size(), k=2, m=12;
        vvvvint dp(n+1,vvvint(k+1,vvint(2,vint(m+2,-1))));
        return recursion(0,0,1,-1,n,k,profit,month,dp);
    }
    int maxVisitedNodes(int n, int m, int k,vector<int>& light,vector<vector<int>>& edges) {
        vvint adjList(n);
        for(auto &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,DFS(i,-1,k,adjList,light));
        }
        return maxi; 
    }
    int maxTotalSum(vint nums,int k,int x){
        int n=nums.size();
        long long sum=0;
        vector<int> gains;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            int gain=(nums[i]^x)-nums[i];
            if(gain>0) gains.push_back(gain);
        }
        sort(gains.rbegin(),gains.rend());
        int i=0, m=gains.size();
        while(i<k && i<m){
            sum+=gains[i];
            i++;
        }
        return sum;
    }
    int numberOfSequences(int k,int n,int t){
        long long count=0;
        vvvint dp(n+1,vvint(k+1,vint(t+1,-1)));
        for(int die=1;die<=k;die++)
            count=(count+recursion(1,die,k,n,t-die,dp))%mod;
        return count;
    }
    int editDistanceAdvanced(string s,string t,vint ins,vint del,vvint rep){
        int n=s.size(), m=t.size();
        vvint dp(n+1,vint(m+1,0));
        for(int i=1;i<=n;i++){
            int letterIdx=s[i-1]-'a';
            dp[i][0]=dp[i-1][0]+del[letterIdx];
        }
        for(int j=1;j<=m;j++){
            int letterIdx=t[j-1]-'a';
            dp[0][j]=dp[0][j-1]+ins[letterIdx];
        }
        for(int i=1;i<=n;i++){
            char srcIdx=s[i-1]-'a';
            for(int j=1;j<=m;j++){
                char tarIdx=t[j-1]-'a';
                int deleteMe=del[srcIdx]+dp[i-1][j];
                int replaceMe=rep[srcIdx][tarIdx]+dp[i-1][j-1];
                int insertMe=ins[tarIdx]+dp[i][j-1];
                dp[i][j]=min({deleteMe,replaceMe,insertMe});
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<endl;
        return dp[n][m];
    }
    int minTotalCostToMakeArrayNonDecreasing(vint nums,vvint ranges){
        int n=nums.size(), maxi=0;
        vector<unordered_map<int,long long>> memo(n+1);
        return recursion(0,-1,n,nums,ranges,memo);
    }
    int countNumberOfArrays(int n,int m){
    
        long long totalSum=0;
        vint startCount(1,0);
        for(int j=1;j<=m;j++){
            int low=j, high=m/j;
            if(low>high) break;
            int len=high-low+1;
            totalSum=totalSum+len;
            startCount.push_back(len);
        }
        int k=startCount.size();
        vll dp(k,0);
        for(int i=1;i<k;i++){
            dp[i]=startCount[i];
        }
        for(int i=1;i<n/2;i++){
            long long newTotalSum=0;
            for(int j=1;j<k;j++){
                dp[j]=(1LL*startCount[j]*(totalSum-dp[j])%mod+mod)%mod;
                newTotalSum=(newTotalSum+dp[j])%mod;
            }
            totalSum=newTotalSum;
        }
        return totalSum%mod;
    }
    long long recursion(int i,int j,int n,int m,vint &a,vint &b,vvll &dp){
        if(i==n || j==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long skipA=recursion(i+1,j,n,m,a,b,dp), skipB=recursion(i,j-1,n,m,a,b,dp);
        long long skipBoth=recursion(i+1,j-1,n,m,a,b,dp);
        long long skip=((skipA+skipB-skipBoth)%mod+mod)%mod;
        long long take=0;
        if(a[i]==b[j]) take=(1+skipBoth)%mod;
        return dp[i][j]=(skip+take)%mod;
    }
    int findNumberOfPalindromes(vint a,vint b){
        int n=a.size(), m=b.size();
        vvll dp(n+1,vll(m+1,-1));
        return recursion(0,m-1,n,m,a,b,dp);
    }
};

int main(){
    Solution s;
    // cout<<s.maxTotalScore("leetcoderhere",{"leet","leetcoder","her","e"})<<endl;
    // cout<<s.maxTotalScore("aaba",{"a","a","b","r"})<<endl;
    // cout<<s.maxTotalScore("abcde",{"a","e","b","cde","abcd"})<<endl;
    // cout<<s.maxProfit({10 ,20 ,15 ,30 ,40},{1 ,1 ,2 ,2 ,2})<<endl;

    // // Test Case 1: The Alternating Line
    // // Expected Output: 3
    // vector<int> light1 = {1, 0, 1, 0, 1};
    // vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    // cout << "Test Case 1: " << s.maxVisitedNodes(5, 4, 1, light1, edges1) << " (Expected: 3)" << endl;

    // // Test Case 2: The Star Graph
    // // Expected Output: 3
    // vector<int> light2 = {0, 1, 1, 1, 1, 1};
    // vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    // cout << "Test Case 2: " << s.maxVisitedNodes(6, 5, 1, light2, edges2) << " (Expected: 3)" << endl;

    // // Test Case 3: Zero K Allowance
    // // Expected Output: 2
    // vector<int> light3 = {1, 1, 0, 1, 1};
    // vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    // cout << "Test Case 3: " << s.maxVisitedNodes(5, 4, 0, light3, edges3) << " (Expected: 2)" << endl;

    // // Test Case 4: Complete Darkness (Large K)
    // // Expected Output: 4
    // vector<int> light4 = {0, 0, 0, 0};
    // vector<vector<int>> edges4 = {{0, 1}, {1, 2}, {2, 3}};
    // cout << "Test Case 4: " << s.maxVisitedNodes(4, 3, 5, light4, edges4) << " (Expected: 4)" << endl;

    // // Test Case 5: The "Y" Shape
    // // Expected Output: 4
    // vector<int> light5 = {1, 0, 1, 0, 1};
    // vector<vector<int>> edges5 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}};
    // cout << "Test Case 5: " << s.maxVisitedNodes(5, 4, 1, light5, edges5) << " (Expected: 4)" << endl;

    // vector<int> light6 = { 0, 1};
    // vector<vector<int>> edges6 = {{0, 1}};
    // cout << "Test Case 5: " << s.maxVisitedNodes(2, 1, 1, light6, edges6) << " (Expected: 2)" << endl;

    // vector<int> light7 = { 0, 0};
    // vector<vector<int>> edges7 = {{0, 1}};
    // cout << "Test Case 5: " << s.maxVisitedNodes(2, 1, 1, light7, edges7) << " (Expected: 1)" << endl;

    // cout<<s.maxTotalSum({1,2,3},1,3)<<endl;
    // cout<<s.maxTotalSum({10,20,30},5,5)<<endl;
    // cout<<s.maxTotalSum({5,6,7},2,1)<<endl;
    // cout<<s.maxTotalSum({4,17},1,11)<<endl;

    // cout<<s.numberOfSequences(3,3,6)<<endl;
    // cout<<s.numberOfSequences(2,5,10)<<endl;
    // cout<<s.numberOfSequences(4,4,10)<<endl;

    // // 1. Set up the strings
    // string source = "cat";
    // string target = "cars";

    // // 2. Set up the Insertion costs (Default 100, 'r'=4, 's'=3)
    // vint ins(26, 100);
    // ins['r' - 'a'] = 4;
    // ins['s' - 'a'] = 3;

    // // 3. Set up the Deletion costs (Default 100, 't'=5)
    // vint del(26, 100);
    // del['t' - 'a'] = 5;

    // // 4. Set up the Replacement costs (Default 100, Diagonals 0, 't'->'r'=12)
    // vvint rep(26, vint(26, 100));
    // for(int i = 0; i < 26; i++) {
    //     rep[i][i] = 0; 
    // }
    // rep['t' - 'a']['r' - 'a'] = 12;

    // // 5. Call the function (passing by value as required by your signature)
    // cout << s.editDistanceAdvanced(source, target, ins, del, rep) << endl;


    // cout<<s.countNumberOfArrays(6,6)<<endl;
    // cout<<s.countNumberOfArrays(2,4)<<endl;
    // cout<<s.countNumberOfArrays(4,3)<<endl;
    // cout<<s.countNumberOfArrays(4,5)<<endl;
    
    // Test Case 1: Simple mirror sequence
    // A = [1, 2], B = [2, 1]
    // Common subsequences with Reverse(B) [1, 2] are {1}, {2}, and {1, 2}.
    cout << s.findNumberOfPalindromes({1, 2}, {2, 1}) << endl; 
    // Expected Output: 3

    // Test Case 2: Identical arrays where order matters
    // A = [1, 2], B = [1, 2]
    // Common subsequences with Reverse(B) [2, 1] are {1} and {2}.
    cout << s.findNumberOfPalindromes({1, 2}, {1, 2}) << endl; 
    // Expected Output: 2

    // Test Case 3: All identical elements (The Combinatorics Trap)
    // A = [1, 1], B = [1, 1]
    // Every possible pair of length 1 (4 pairs) and length 2 (1 pair) forms a palindrome.
    cout << s.findNumberOfPalindromes({1, 1}, {1, 1}) << endl; 
    // Expected Output: 5

    // Test Case 4: No matching elements
    // Impossible to form any valid palindrome.
    cout << s.findNumberOfPalindromes({1, 2, 3}, {4, 5, 6}) << endl; 
    // Expected Output: 0

    // Test Case 5: Longer interleaved sequence
    // A = [1, 2, 1, 3], B = [3, 2, 1, 1]
    cout << s.findNumberOfPalindromes({1, 2, 1, 3}, {3, 2, 1, 1}) << endl; 
    // Expected Output: 17
    return 0;
}