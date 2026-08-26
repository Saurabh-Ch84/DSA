#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vvvint=vector<vvint>;
using vll=vector<long long>;
using vvll=vector<vll>;
using vvvll=vector<vvll>;
using vvvvll=vector<vvvll>;

int mod=1e9+7, negInf=-1e9, posInf=1e9;
/*
8
    You are given an array a[1..N], integers K and B.
    You need to partition a into exactly K contiguous groups. 
    Each group a[l..r] has a span cost of max(a[l..r]) - min(a[l..r]).
    The sum of all span costs must be at most B (the budget).
    Among all valid partitions, maximize the sum of group lengths squared, i.e., maximize Σ lenᵢ².
    Find the maximum sum of squared group lengths; -1 if no valid partition exists.
*/

/*
9
    You are given an array a[1..N] of positive integers, partition it into exactly K contiguous blocks. 
    The cost of a block a[l..r] depends on its length len = r - l + 1
        - If len is odd: cost = len * max(a[l..r])
        - If len is even: cost = len * min(a[l..r])
    Find the minimum total cost across all K blocks.

    Input Format
        The first line contains an integer, n, denoting the size of the array.
        The second line contains an integer, k, denoting the exact number of contiguous blocks.
*/

/*
11
    You are given an N × N grid with values g[i] [j]. Two collectors start at (1,1) simultaneously and both must reach (N,N). 
    Each collector moves only right or down at each step. When both collectors visit the same cell, its value is collected only once. 
    Find the maximum total collected value.

    Input Format
        The first line contains an integer, n, denoting the size of the grid.
        Each of the n lines contains n space-separated integers, representing row i of g.

    Constraints
        1 <= n <= 10^5
        -10^9 <= g[i] [j] <= 10^9

Sample Test Case
    Case 1

    Input:
        3
        1 2 3
        4 5 6
        7 8 9
    Output: 42
    Explanation:
        Collector 1 path:
        (0,0) → (1,0) → (2,0) → (2,1) → (2,2) — collects 1+4+7+8+9 = 29
        Collector 2 path:
        (0,0) → (0,1) → (1,1) → (1,2) → (2,2) — collects 1+2+5+6+9 = 23
        Shared cells: (0,0)=1 and (2,2)=9 → counted only once
        Total = union of both paths = 1+4+7+8+9+2+5+6 = 42
    
    Sample Test Case 2

    Input:
        2
        10 -5
        -5 10
    Output: 15
    Explanation:
    Both collectors take the same path:
    (0,0) → (0,1) → (1,1) — 10 + (-5) + 10 = 15
    Taking different paths would force one collector through (0,1)=-5 and the other through (1,0)=-5, 
    collecting union = 10 - 5 - 5 + 10 = 10, which is worse.
    Best strategy: both share one path, avoiding the -5 on the other route.
*/

/*
13
    You are given an array a of N integers and two integer bounds, lo and hi, where 1 ≤ lo ≤ hi.
    Your task is to count the number of contiguous subarrays within a where every element x in the subarray satisfies the condition lo ≤ x ≤ hi.
    Find the total count of such subarrays, modulo 10^9 + 7.

    Input Format
        The first line contains a integer, N, denoting the number of elements in array a.
        The second line contains a integer, lo, denoting the lower bound for elements in a valid subarray.
        The third line contains a integer, hi, denoting the upper bound for elements in a valid subarray.
*/

/*
13
    You are given n intervals [l[i], r[i]] each with value v[i].
    Two intervals are overlapping if they share at least one point: l[i] ≤ r[j] and l[j] ≤ r[i].
    Overlapping intervals must be merged into one group transitively.
    The value of a group is the sum of its member values.
    Find the maximum group value across all merged groups.

Input Format
    The first line contains a integer, n, denoting the number of the intervals.
    Each line i of the n subsequent lines (where 0 ≤ i < n) contains a integer, l[i].
    Each line i of the n subsequent lines (where 0 ≤ i < n) contains a integer, r[i].
    Each line i of the n subsequent lines (where 0 ≤ i < n) contains a integer, v[i].
*/

/*
    You are given an array A of length N consisting of positive integers.

    In one move, you are allowed to choose any index i (1 <= i <= N) from this array and set A[i] = A[i]-1.

    You can perform any number of moves, and it doesn't matter if A[i] becomes zero or a negative number at some point.

    After your moves, you want to build K houses on this array. You can build a house at index i (where 6 <= i <= N-5) 
    if and only if A[i] is strictly greater than the five elements after it and at the five elements before it.

    Find the minimum number of moves required to build exactly K houses.

    Notes:
        It is guaranteed that there is at least one valid way to build the house.
        It is given that all arrays follow 1-based indexing.
    
        N = 12
        K = 1
        A = [5, 5, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5]
        We need to build 1 house (K = 1) by modifying the array.
        The best option is to place a house at A[7] = 5 (1-based index), as it can be made the highest.
        To do so, we decrease the surrounding numbers accordingly.
        The final modified array is:
        [5, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4]
        Total moves required: 9
*/

/*
    You are given N voters, each with a vote (0 or 1) and a weight w[i].
    You may flip up to K votes (change 0 → 1 or 1 → 0).
    After flipping, candidate 1 wins if the total weight of votes for 1 is strictly greater than the total weight of votes for 0.

    Determine whether candidate 1 can win, and if so, return the minimum number of flips needed.
    If candidate 1 cannot win even with K flips, return -1.

    Input Format
        The first line contains an integer, N, denoting the number of votes.
        The second line contains an integer, K, denoting the maximum number of vote flips allowed.
        Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer, v[i].
        Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer, w[i].
*/

/*
    You are given a permutation P of the integers from 1 to N.
    A fixed point of a permutation is an index i (1-based) such that P[i] == i.

    You are required to perform exactly one swap of two elements at different indices i and j (1 ≤ i, j ≤ N, i ≠ j).
    Your goal is to choose the indices i and j such that the number of fixed points in the resulting permutation is maximized.

    Find the maximum number of fixed points possible after performing atmost one such swap.

    Input Format
        The first line contains an integer, N, denoting the size of the permutation.
        Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer, P[i].

    Constraints
        1 ≤ N ≤ 10^5
        1 ≤ P[i] ≤ N
    
    Output Format
        A single integer representing the maximum number of fixed points achievable.

    Sample Test Cases
        Case 1
        Input:
        3
        1
        2
        3
        Output: 3
        Explanation:
            The initial permutation is [1, 2, 3]. It already has 3 fixed points (P[1]=1, P[2]=2, P[3]=3).

        Case 2
        Input:
        3
        3
        1
        2
        Output: 1
        Explanation:
            The initial permutation is [3, 1, 2]. It has 0 fixed points.
            Performing any swap (e.g., swapping P[1] and P[2] to get [1, 3, 2]) creates at most one fixed point (P[1]=1).
            The maximum possible is 1.
*/

/*
    A strip of N cells must each be painted one of 3 colors (R, G, B).
    Painting cell i with color j costs cost[i][j].
    A streak of length L is a maximal run of L consecutive cells all painted the same color.
    A streak of length L earns a streak bonus of L × Q (Q is a given constant).

    Minimize: total painting cost – total streak bonuses

    Input Format
        The first line contains an integer, n, denoting the number of cells.
        The second line contains a integer, q, denoting the bonus per cell in any same-color streak.
        Each of the n subsequent lines contains 3 space-separated integers, representing row i of cost.

    Constraints
        1 ≤ n ≤ 10^5
        1 ≤ q ≤ 10^5
        0 ≤ cost[i][j] ≤ 10^4

    Sample Test Cases
    Case 1
        Input:
        3
        10
        5 20 30
        50 5 40
        100 100 5

        Output: 
        -15

        Explanation:
        n=3, q=10. Cheapest per cell: R(5), G(5), B(5) -> paint cost = 15. Bonus = 3 x 10 = 30. Net = 15 - 30 = -15.


    Case 2
        Input:
        2
        0
        10 20 30
        30 20 10

        Output:
        20

        Explanation:
        n=2, q=0. Cheapest per cell: R(10), B(10) -> paint cost = 20. Bonus = 2 x 0 = 0. Net = 20 - 0 = 20.

*/

class Solution{
    long long recursion(int i,int k,int b,int n,vint &arr,vvvll &dp){
        if(i==n && b>=0 && k==0) return 0;
        if(i==n || b<0 || k<=0) return negInf;
        if(dp[i][k][b]!=-1) return dp[i][k][b];
        long long ans=negInf;
        int maxi=negInf, mini=posInf;
        for(int j=i;j<=n-k;j++){
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
            long long spanCost=1LL*maxi-mini;
            if(spanCost<=b){
                long long nextAns=(j-i+1)*(j-i+1)+recursion(j+1,k-1,b-spanCost,n,arr,dp);
                ans=max(ans,nextAns);
            }
            else break;
        }
        return dp[i][k][b]=ans;
    }
    long long recursion(int i,int k,int n,vint &arr,vvll &dp){
        if(i==n && k==0) return 0;
        if(i==n || k<=0) return posInf;
        if(dp[i][k]!=-1) return dp[i][k];
        long long ans=posInf;
        int maxi=negInf, mini=posInf;
        for(int j=i;j<=n-k;j++){
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
            int len=j-i+1;
            long long blockCost=1LL*len*(len%2==0? mini: maxi);
            long long nextAns=blockCost+recursion(j+1,k-1,n,arr,dp);
            ans=min(ans,nextAns);
        }
        return dp[i][k]=ans;
    }    
    long long recursion(int i1,int j1,int i2,int j2,int n,vvint &grid,vvvvll &dp){
        if(i1>=n || i2>=n || j1>=n || j2>=n) return negInf;
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int cost=grid[i1][j1];
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1) return cost;
        if(i1!=i2 || j1!=j2) cost=cost+grid[i2][j2];
        long long bothRight=recursion(i1,j1+1,i2,j2+1,n,grid,dp);
        long long bothDown=recursion(i1+1,j1,i2+1,j2,n,grid,dp);
        long long rightDown=recursion(i1,j1+1,i2+1,j2,n,grid,dp);
        long long downRight=recursion(i1+1,j1,i2,j2+1,n,grid,dp);
        long long maxAns=max({bothRight,bothDown,rightDown,downRight})+cost;
        return dp[i1][j1][i2][j2]=maxAns;
    }
    bool areOverlapping(vll &prev,long long lJ,long long rJ){
        long long lI=prev[0], rI=prev[1];
        return (lI<=rJ && lJ<=rI);
    }        
    long long recursion_(int i,int p,int n,int k,vint &arr,vvvll &dp){
        if(i==n) return (k? posInf:0);
        if(!k) return 0;
        if(dp[i][p+1][k]!=-1) return dp[i][p+1][k];
        long long skip=recursion_(i+1,p,n,k,arr,dp), take=posInf;
        int iL=i-5, iR=i+5;
        if(iL>=0 && iR<n){
            long long minOperations=0;
            for(int j=iL;j<=iR;j++){
                if(j==i) continue;
                int currVal=arr[j], destVal=arr[i]-1;
                if(p!=-1 && j<=p+5) 
                    currVal=min(currVal,arr[p]-1);
                minOperations+=max(0,currVal-destVal);
            }
            take=minOperations+recursion_(iR+1,i,n,k-1,arr,dp);
        }
        return dp[i][p+1][k]=min(skip,take);
    }
        public:
    long long maxSumOfSquaredGroupLengths(vint arr,int k,int b){
        int n=arr.size();
        vvvll dp(n+1,vvll(k+1,vll(b+1,-1)));
        long long ans=recursion(0,k,b,n,arr,dp);
        return (ans<=0? -1: ans);
    }
    long long minTotalCostAcrossAllKBlocks(vint arr,int k){
        int n=arr.size();
        vvll dp(n+1,vll(k+1,-1));
        return recursion(0,k,n,arr,dp);
    }
    long long maxTotalCalculatedValue(vvint grid){
        int n=grid.size();
        vvvvll dp(n+1,vvvll(n+1,vvll(n+1,vll(n+1,-1))));
        return recursion(0,0,0,0,n,grid,dp);
    }
    int countSubArrays(vint nums,int lo,int hi){
        int n=nums.size(), left=0, right=0;
        long long count=0;
        while(right<n){
            int num=nums[right];
            if(num<lo || num>hi)
                left=right+1;
            else{
                int len=right-left+1;
                count=(count+len)%mod;
            }
            right++;
        }
        return count;
    }
    long long maxGroupValueAcrossAllMergedGroups(vint l,vint r,vint v){
        int n=v.size();
        vvint intervals;
        for(int i=0;i<n;i++)
            intervals.push_back({l[i],r[i],v[i]});
        sort(intervals.begin(),intervals.end());
        
        vvll newIntervals;
        for(int i=0;i<n;i++){
            long long lJ=intervals[i][0], rJ=intervals[i][1], vJ=intervals[i][2];
            if(newIntervals.empty() || !areOverlapping(newIntervals.back(),lJ,rJ)) 
                newIntervals.push_back({lJ,rJ,vJ});
            else{
                newIntervals.back()[1]=max(newIntervals.back()[1],rJ);
                newIntervals.back()[2]+=vJ;
            }
        }
        int m=newIntervals.size();
        long long maxi=negInf;
        for(int i=0;i<m;i++)
            maxi=max(maxi,newIntervals[i][2]);
        return maxi;
    }
    long long minNumberOfMovesToBuildKHouses(vint arr,int k){
        int n=arr.size();
        vvvll dp(n+1,vvll(n+2,vll(k+1,-1)));
        return recursion_(0,-1,n,k,arr,dp);
    }
    int minFlipsFor1ToWin(vint votes,vint weights,int k){
        int n=votes.size();
        long long difference=0;
        vint zero;
        for(int i=0;i<n;i++){
            difference=difference+(votes[i]? weights[i]:-weights[i]);
            if(votes[i]) continue;
            zero.push_back(weights[i]);
        }
        sort(zero.rbegin(),zero.rend());
        int count=0, i=0, m=zero.size();
        while(i<m && count<k && difference<=0){
            difference=difference+zero[i]*2;
            count++;
            i++;
        }
        return (difference>0? count: -1);
    }
    int maxFixedPointsAfter1Swaps(vint arr){
        int n=arr.size(), fixedPoints=0;
        vint indexArr(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i]-1==i)
                fixedPoints++;
            indexArr[i]=arr[i]-1;
        }
        int maxi=fixedPoints;
        for(int i=0;i<n;i++){
            if(indexArr[i]!=i){
                int j=indexArr[i];
                if(indexArr[j]==i){
                    maxi=max(maxi,fixedPoints+2);
                    break;
                }
                maxi=max(maxi,fixedPoints+1);
            }
        }
        return maxi;
    }
    int minimizeCost(int n,int q,vvint cost){
        int m=3;
        long long totalCost=0;
        for(int i=0;i<n;i++)
            totalCost=totalCost+min({cost[i][0],cost[i][1],cost[i][2]});
        long long totalBonus=1LL*n*q;
        return totalCost-totalBonus;
    }
};

int main(){
    Solution s;
    // // Test Case 1: Simple valid partition
    // // K = 2, B = 2
    // // Valid partitions for 2 groups:
    // // [1, 2] and [5, 6] -> Cost: (2-1) + (6-5) = 2 <= 2. Squared lengths: 2^2 + 2^2 = 8.
    // // Other partitions like [1] and [2, 5, 6] cost 4, which exceeds B.
    // cout << s.maxSumOfSquaredGroupLengths({1, 2, 5, 6}, 2, 2) << endl;
    // // Expected Output: 8

    // // Test Case 2: Impossible partition
    // // K = 1, B = 5
    // // Only one group [1, 10], cost is 10 - 1 = 9. Since 9 > 5, no valid partition exists.
    // cout << s.maxSumOfSquaredGroupLengths({1, 10}, 1, 5) << endl;
    // // Expected Output: -1

    // // Test Case 3: Zero cost elements (Maximize variance in group sizes)
    // // K = 2, B = 0
    // // Any partition has 0 cost since all elements are the same.
    // // We want to maximize length squared: a group of 3 and 1 gives 3^2 + 1^2 = 10, which beats 2^2 + 2^2 = 8.
    // cout << s.maxSumOfSquaredGroupLengths({4, 4, 4, 4}, 2, 0) << endl;
    // // Expected Output: 10

    // // Test Case 4: Exact budget usage
    // // K = 3, B = 3
    // // The partition [1, 3, 4], [7], [8] gives lengths 3, 1, 1. 
    // // Cost: (4-1) + (7-7) + (8-8) = 3 + 0 + 0 = 3. Budget is met!
    // // Squared lengths: 3^2 + 1^2 + 1^2 = 11.
    // cout << s.maxSumOfSquaredGroupLengths({1, 3, 4, 7, 8}, 3, 3) << endl;
    // // Expected Output: 11

    // // Test Case 5: K = N (Every element is its own group)
    // // K = 5, B = 0
    // // Cost is 0. Squared lengths: 1^2 + 1^2 + 1^2 + 1^2 + 1^2 = 5.
    // cout << s.maxSumOfSquaredGroupLengths({1, 5, 2, 8, 3}, 5, 0) << endl;
    // // Expected Output: 5

    // // Test Case 1: Simple odd/even length differences
    // // K = 2
    // // Partition 1: [1] (len 1, odd -> 1 * 1 = 1) and [5, 2] (len 2, even -> 2 * 2 = 4). Cost = 5.
    // // Partition 2: [1, 5] (len 2, even -> 2 * 1 = 2) and [2] (len 1, odd -> 1 * 2 = 2). Cost = 4.
    // // Minimum cost is 4.
    // cout << s.minTotalCostAcrossAllKBlocks({1, 5, 2}, 2) << endl;
    // // Expected Output: 4

    // // Test Case 2: K = N (Every element is its own group)
    // // K = 3
    // // Every block has length 1 (odd). Cost is 1 * max(a[i]) for each.
    // // [4] -> 4, [3] -> 3, [2] -> 2. Total = 4 + 3 + 2 = 9.
    // cout << s.minTotalCostAcrossAllKBlocks({4, 3, 2}, 3) << endl;
    // // Expected Output: 9

    // // Test Case 3: K = 1 (A single contiguous block)
    // // K = 1
    // // Length is 4 (even). Cost is 4 * min(array) = 4 * 5 = 20.
    // cout << s.minTotalCostAcrossAllKBlocks({10, 20, 5, 30}, 1) << endl;
    // // Expected Output: 20

    // // Test Case 4: Strategic grouping to exploit the "even length" rule
    // // K = 2
    // // If we group [100, 1] and [100, 1], both lengths are 2 (even).
    // // Cost of [100, 1] = 2 * min(100, 1) = 2.
    // // Total cost = 2 + 2 = 4. (Way better than an odd partition like [100] + [1, 100, 1] which costs 300+).
    // cout << s.minTotalCostAcrossAllKBlocks({100, 1, 100, 1}, 2) << endl;
    // // Expected Output: 4

    // // Test Case 5: Forcing an expensive odd partition
    // // K = 2
    // // Array has 3 elements, so one block MUST be length 1 (odd) and one MUST be length 2 (even).
    // // [5] -> 1 * 5 = 5. [5, 5] -> 2 * 5 = 10. Total = 15.
    // cout << s.minTotalCostAcrossAllKBlocks({5, 5, 5}, 2) << endl;
    // // Expected Output: 15

    // // Test Case 1: Simple positive grid (Maximize unique coverage)
    // // Path 1 goes down then right, Path 2 goes right then down.
    // cout << s.maxTotalCalculatedValue({
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // }) << endl; 
    // // Expected Output: 42

    // // Test Case 2: Forcing shared paths
    // // Both collectors must stick together to avoid the -5 cells.
    // cout << s.maxTotalCalculatedValue({
    //     {10, -5},
    //     {-5, 10}
    // }) << endl; 
    // // Expected Output: 15

    // // Test Case 3: 1x1 Base Case
    // // Grid is just start/end node. Both collect it once.
    // cout << s.maxTotalCalculatedValue({
    //     {100}
    // }) << endl; 
    // // Expected Output: 100

    // // Test Case 4: Avoiding a massive central penalty
    // // Both collectors surround the center (-100) taking the outer positive rim.
    // cout << s.maxTotalCalculatedValue({
    //     {1, 1, 1},
    //     {1, -100, 1},
    //     {1, 1, 1}
    // }) << endl; 
    // // Expected Output: 8

    // // Test Case 5: Deep negative grid
    // // Everywhere hurts, so they should take the exact same path to only suffer the penalty once.
    // // Best shared path: -1 -> -2 -> -1 -> -2 -> -1 = -7
    // cout << s.maxTotalCalculatedValue({
    //     {-1, -2, -10},
    //     {-10, -1, -2},
    //     {-10, -10, -1}
    // }) << endl; 
    // // Expected Output: -7
        
    // cout<<s.minNumberOfMovesToBuildKHouses({5, 5, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5},1)<<endl;

    // // Test Case 1: Candidate 1 is already winning
    // // Votes for 1: 20, Votes for 0: 5. (20 > 5)
    // // No flips are needed.
    // cout << s.minFlipsFor1ToWin({1, 1, 0}, {10, 10, 5}, 1) << endl;
    // // Expected Output: 0

    // // Test Case 2: Tie condition (Strictly greater required)
    // // Votes for 1: 10, Votes for 0: 10. (10 is NOT strictly greater than 10)
    // // We must flip the 0 to a 1 to break the tie and win.
    // cout << s.minFlipsFor1ToWin({1, 0}, {10, 10}, 1) << endl;
    // // Expected Output: 1

    // // Test Case 3: Greedy flip choice
    // // Votes for 1: 2, Votes for 0: 15. 
    // // We are allowed up to 1 flip (K=1). If we flip the weight 5, Total 1 becomes 7 (still lose).
    // // If we flip the weight 10, Total 1 becomes 12, Total 0 becomes 5 (12 > 5). Win!
    // cout << s.minFlipsFor1ToWin({0, 0, 1}, {10, 5, 2}, 1) << endl;
    // // Expected Output: 1

    // // Test Case 4: Impossible to win
    // // Votes for 1: 0, Votes for 0: 300.
    // // We are allowed 1 flip (K=1). Flipping any single 100-weight vote gives us 100 vs 200. 
    // // Candidate 1 still loses, and we are out of allowed flips.
    // cout << s.minFlipsFor1ToWin({0, 0, 0}, {100, 100, 100}, 1) << endl;
    // // Expected Output: -1

    // // Test Case 5: Multiple flips required
    // // Votes for 1: 0, Votes for 0: 20. Target for candidate 1 to win is 11.
    // // We are allowed up to 3 flips (K=3). 
    // // Flipping the heaviest voters (8 and 9) gives Total 1 = 17. 
    // // Takes exactly 2 flips to secure the win.
    // cout << s.minFlipsFor1ToWin({0, 0, 0, 0}, {1, 2, 8, 9}, 3) << endl;
    // // Expected Output: 2

    // cout<<s.maxFixedPointsAfter1Swaps({1,2,3})<<endl;
    // cout<<s.maxFixedPointsAfter1Swaps({3,2,1})<<endl;
    // cout<<s.maxFixedPointsAfter1Swaps({3,1,2})<<endl;
    
    // Case 1
    cout << s.minimizeCost(3, 10, {
        {5, 20, 30},
        {50, 5, 40},
        {100, 100, 5}
    }) << "\n";
    // Expected Output: -15

    // Case 2
    cout << s.minimizeCost(2, 0, {
        {10, 20, 30},
        {30, 20, 10}
    }) << "\n";
    // Expected Output: 20
 
    return 0;
}