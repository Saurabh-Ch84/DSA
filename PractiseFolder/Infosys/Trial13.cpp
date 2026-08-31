#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vvvint=vector<vvint>;

using vchar=vector<char>;
using vvchar=vector<vchar>;

using vll=vector<long long>;
using vvll=vector<vll>;

/*
    Longest Strictly Increasing Path in Grid
    You are given an N × M grid of integers.
    You want to find the maximum possible length of a strictly increasing path. The length of a path is defined as the number of cells you visited.
    Normally, from any cell, you can move 1 step in any of the 4 cardinal directions (up, down, left, right) to a neighboring cell, provided that
    the value in the neighboring cell is strictly greater than the value in your current cell.
    However, to make things interesting, you are allowed to use a special "Dash" move at most once during your entire path. A Dash move allows you
    to jump over an immediate neighboring cell and land on the cell exactly two steps away in the same direction 
    (e.g., from (i, j) to (i+2, j)). To perform a Dash:

    The destination cell must be strictly greater than your current cell.
    The destination cell must be within the grid boundaries.
    The intermediate skipped cell is completely ignored (its value does not matter, 
    and it is not counted as a visited cell).
    Find the maximum number of cells you can visit on a valid path.
*/

/*
    **Split a String in Balanced Strings**

    You are given a string $s$ of even length $N$ consisting only of the characters 'L' and 'R'.  
    The string is **globally balanced**, meaning it contains an equal number of 'L' and 'R' characters.

    A substring is considered **balanced** if it contains an equal number of 'L' and 'R' characters.

    Your goal is to split the string into the **maximum possible number of contiguous balanced substrings**.

    Before making the splits, you may perform **at most one operation**:

    - **Swap one pair of adjacent characters** in the string.  
    You may also choose not to perform any swap.

    Determine the **maximum number of balanced substrings** into which the string can be partitioned.
*/

/*
    Question 1 ->
    You are given an array arr[1..N] and a limit L.
    You need to find the length of the longest contiguous subarray in which no two adjacent elements differ by more than L.
    That is, for every pair of consecutive elements in the chosen subarray, |a[i+1] - a[i]| ≤ L.
    Find the length of the longest contiguous subarray satisfying this condition.

    Constraints 
    1 <= N <= 10^5 -> length
    0 < L <= 10^9 -> limit
    0 <= a[i] <= 10^9 -> element
*/

/*
    Problem Statement:
    A research laboratory is represented as an N × M grid containing walls, empty cells, fire sources, and one human. 
    Each cell contains one of the following characters:

    '#' → Wall
    '.' → Empty cell
    'F' → Fire source
    'H' → Human
    Every minute:

    Fire spreads simultaneously to all adjacent cells (up, down, left, right).
    The human can also move one step in any of the four directions.

    The human cannot:
        Move through walls.
        Move into a cell already occupied by fire.
        Move into a cell where fire reaches at the same time.
    
    The human escapes successfully if they reach any boundary cell before the fire reaches that cell.
    Your task is to determine whether escape is possible. 
    Print YES if the human can escape, otherwise print NO.
*/

/*
    Weighted Coin Change — Problem Statement

    You are given:

    An array coins[] where coins[i] is the coin value.
    An array weights[] where weights[i] is the cost of using that coin.
    An integer target.
    You can use each coin an unlimited number of times.

    Your task is to make exactly target using these coins such that the total weight/cost is minimum.

    If it's not possible, return -1.
*/

/*
    In satellite signal processing, a stream of N data packets is received. Each packet is classified into a 
    category A[i] (ranging from 0 to C-1) and carries a specific signal weight W[i] representing its data density.

    A monitoring window [l, r] (the contiguous range of packets from index l to r) is considered frequency-balanced if there exists at 
    least one category that appears strictly more than half of the packets in that window.

    In other words, some category is a strict majority in the window.

    Your task is to find the maximum total weight among all possible frequency-balanced windows.

    The total weight of a window is: sum_{i=l}^{r} W[i]
*/

class Solution{
    long long inf=1e10;
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int DFS(int i,int j,int k,int n,int m,vint &di,vint &dj,vvint &grid,vvvint &dp){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int count=1;
        for(int d=0;d<4;d++){
            int i_=i+di[d], j_=j+dj[d];
            if(!isValid(i_,j_,n,m)) continue;
            int normalMove=0, dashMove=0;
            if(grid[i_][j_]>grid[i][j])
                normalMove=DFS(i_,j_,k,n,m,di,dj,grid,dp);
            if(!k){
                int i__=i+2*di[d], j__=j+2*dj[d];
                if(isValid(i__,j__,n,m) && grid[i__][j__]>grid[i][j])
                    dashMove=DFS(i__,j__,1,n,m,di,dj,grid,dp);
            }
            count=max({count,1+normalMove,1+dashMove});
        }
        return dp[i][j][k]=count;
    }
    bool isBoundary(int i,int j,int n,int m){
        return (i==n-1 || i==0 || j==m-1 || j==0);
    }
    void multiSourceBFS(queue<pair<int,int>> &q,vint &di,vint &dj,int inf,int n,int m,vvint &fireTime,vvchar &grid){
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int i=entry.first, j=entry.second;
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,n,m) || grid[i_][j_]=='#' || fireTime[i_][j_]!=inf)
                        continue;
                    fireTime[i_][j_]=1+fireTime[i][j];
                    q.push({i_,j_});
                }
            }
        }
    }        
    long long recursion(int i,int target,int n,vint &coins,vint &weights,vvll &dp){
        if(i==n) return (target? inf: 0);
        if(target==0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        long long skip=recursion(i+1,target,n,coins,weights,dp), take=inf;
        if(target>=coins[i] && coins[i]>0) take=weights[i]+recursion(i,target-coins[i],n,coins,weights,dp);
        return dp[i][target]=min(skip,take);
    }
        public:
    int maxCellsThatCanBeVisited(vvint grid){
        int n=grid.size(), m=grid[0].size(), maxi=0;
        vint di={-1,0,1,0}, dj={0,1,0,-1};
        vvvint dp(n+1,vvint(m+1,vint(2,-1)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                maxi=max(maxi,DFS(i,j,0,n,m,di,dj,grid,dp));
        }
        return maxi;
    }
    int maxNumberOfBalancedSubstrings(string s){
        int n=s.length();
        vint prefixArr(n,0);
        prefixArr[0]=(s[0]=='L'? -1:1);
        int balancedSubstrings=0;
        for(int i=1;i<n;i++){
            prefixArr[i]=prefixArr[i-1]+(s[i]=='L'? -1:1);
            if(prefixArr[i]==0) balancedSubstrings++;
        }
        int maxi=balancedSubstrings;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) continue;
            char newLeft=s[i+1], newRight=s[i];
            int prefixArrLeft=0;
            if(newLeft=='L') prefixArrLeft=prefixArr[i]-2;
            else prefixArrLeft=prefixArr[i]+2;
            if(!prefixArrLeft){
                maxi=balancedSubstrings+1;
                break;
            }
        }
        return maxi;
    }
    int findTheLengthOfLongestSubArray(vint arr,int L){
        int n=arr.size(), left=0, right=0, maxi=0, prev=arr[left];
        while(right<n){
            int curr=arr[right];
            if(abs(curr-prev)>L) left=right;
            maxi=max(maxi,right-left+1);
            right++;
            prev=curr;
        }
        return maxi;
    }
    string canEscape(vvchar grid){
        int n=grid.size(), m=grid[0].size(), inf=1e9;
        queue<pair<int,int>> qFire, qHuman;
        vint di={-1,0,1,0}, dj={0,1,0,-1};
        vvint fireTime(n,vint(m,inf));
        vvint visited(n,vint(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.' || grid[i][j]=='#')
                    continue;
                if(grid[i][j]=='F'){
                    qFire.push({i,j});
                    fireTime[i][j]=0;
                }
                else{
                    qHuman.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        if(qHuman.empty()) return "No Human";
        multiSourceBFS(qFire,di,dj,inf,n,m,fireTime,grid);
        int minutesPassed=1;
        while(!qHuman.empty()){
            int sz=qHuman.size();
            while(sz--){
                auto entry=qHuman.front(); qHuman.pop();
                int i=entry.first, j=entry.second;
                if(isBoundary(i,j,n,m)) return "YES";
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,n,m) || minutesPassed>=fireTime[i_][j_] || grid[i_][j_]=='#' || visited[i_][j_])
                        continue;
                    qHuman.push({i_,j_});
                    visited[i_][j_]=1;
                }
            }
            minutesPassed++;
        }
        return "NO";
    }
    long long makeTargetUsingMinCoins(vint coins,vint weights,int target){
        int n=coins.size();
        vvll dp(n+1,vll(target+1,inf));
        long long ans=recursion(0,target,n,coins,weights,dp);
        return (ans>=inf? -1:ans);
    }
    long long maxTotalWeightAmongAllFrequnecyBalancedWindows(vint A,vint W){
        int n=A.size();
        long long maxi=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> freqMap;
            int maxF=0;
            long long totalWeight=0;
            for(int j=i;j<n;j++){
                int len=j-i+1, majority=len/2+1;
                maxF=max(maxF,++freqMap[A[j]]);
                totalWeight+=W[j];
                if(maxF>=majority)
                    maxi=max(maxi,totalWeight);
            }
        }
        return maxi;
    }
};

int main(){
    Solution s;
    // // Test Case 1: Simple 1D path with a beneficial Dash over a larger blocking cell
    // // Path: (0,0)[1] -> (Dash over (0,1)[5] to) (0,2)[3] -> (0,3)[4]
    // cout << s.maxCellsThatCanBeVisited({{1, 5, 3, 4}}) << endl; // Expected: 3

    // // Test Case 2: Standard longest increasing path (No Dash required)
    // // Path: (0,0)[1] -> (0,1)[2] -> (0,2)[3] -> (1,2)[4] -> (1,1)[5] -> (1,0)[6]
    // cout << s.maxCellsThatCanBeVisited({{1, 2, 3}, {6, 5, 4}}) << endl; // Expected: 6

    // // Test Case 3: Dash unlocks a path across regions (Starting at 0 for maximum length)
    // // Path: (1,0)[0] -> (0,0)[1] -> (0,1)[2] -> (Dash over (0,2)[10] to) (0,3)[4] -> (1,3)[5] -> (2,3)[6] -> (3,3)[7]
    // cout << s.maxCellsThatCanBeVisited({
    //     {1,  2, 10, 4},
    //     {0,  0,  0, 5},
    //     {0,  0,  0, 6},
    //     {0,  0,  0, 7}
    // }) << endl; // Expected: 7

    // // Test Case 4: Single cell grid (Boundary Case)
    // cout << s.maxCellsThatCanBeVisited({{42}}) << endl; // Expected: 1

    // // Test Case 5: All identical elements (No strictly increasing moves allowed)
    // cout << s.maxCellsThatCanBeVisited({{5, 5}, {5, 5}}) << endl; // Expected: 1

    // // Test Case 6: Vertical Dash move through rows
    // // Path: (0,1)[0] -> (0,0)[1] -> (1,0)[2] -> (Dash over (2,0)[99] to) (3,0)[4] -> (3,1)[5]
    // cout << s.maxCellsThatCanBeVisited({
    //     {1, 0},
    //     {2, 0},
    //     {99, 0},
    //     {4, 5}
    // }) << endl; // Expected: 5

    // // Test Case 7: Pure 1D row where Dash enables skipping a large barrier
    // // Path: (0,0)[1] -> (0,1)[2] -> (Dash over (0,2)[10] to) (0,3)[3] -> (0,4)[4] -> (0,5)[5]
    // cout << s.maxCellsThatCanBeVisited({
    //     {1, 2, 10, 3, 4, 5}
    // }) << endl; // Expected: 5

    // cout<<s.maxNumberOfBalancedSubstrings("RLRL")<<endl;
    // cout<<s.maxNumberOfBalancedSubstrings("LLRR")<<endl;
    // cout<<s.maxNumberOfBalancedSubstrings("RLLRLLRR")<<endl;
    // cout<<s.maxNumberOfBalancedSubstrings("RRLRLL")<<endl;
    // cout<<s.maxNumberOfBalancedSubstrings("LR")<<endl;
    // cout<<s.maxNumberOfBalancedSubstrings("LLRRLLRR")<<endl<<endl;

    // // Test Case 1: Basic case with valid subarray
    // cout << s.findTheLengthOfLongestSubArray({1, 2, 3, 4, 5}, 1) << endl; 
    // // Expected: 5 (entire array, differences are all 1)

    // // Test Case 2: Limit too small for any adjacent pair
    // cout << s.findTheLengthOfLongestSubArray({1, 3, 5, 7}, 1) << endl; 
    // // Expected: 1 (no adjacent elements differ by <= 1)

    // // Test Case 3: Mixed differences, some within limit
    // cout << s.findTheLengthOfLongestSubArray({1, 2, 4, 5, 6}, 1) << endl; 
    // // Expected: 3 (subarray {4, 5, 6})

    // // Test Case 4: Single element array
    // cout << s.findTheLengthOfLongestSubArray({10}, 5) << endl; 
    // // Expected: 1

    // // Test Case 5: All elements same
    // cout << s.findTheLengthOfLongestSubArray({5, 5, 5, 5}, 0) << endl; 
    // // Expected: 4 (difference is 0 for all pairs)

    // // Test Case 6: Large limit allowing entire array
    // cout << s.findTheLengthOfLongestSubArray({1, 100, 200, 300}, 500) << endl; 
    // // Expected: 4 (entire array, limit is very large)

    // // Test Case 7: Alternating within and outside limit
    // cout << s.findTheLengthOfLongestSubArray({1, 2, 10, 11, 12}, 1) << endl; 
    // // Expected: 3 (subarray {10, 11, 12})

    // // Test Case 8: Negative differences (absolute value matters)
    // cout << s.findTheLengthOfLongestSubArray({5, 4, 3, 2, 1}, 1) << endl; 
    // // Expected: 5 (entire array, differences are -1, abs is 1)

    // // Test Case 9: Large gap in middle
    // cout << s.findTheLengthOfLongestSubArray({1, 2, 3, 100, 101, 102}, 1) << endl; 
    // // Expected: 3 (either {1, 2, 3} or {100, 101, 102})

    // // Test Case 10: Limit exactly matches difference
    // cout << s.findTheLengthOfLongestSubArray({1, 3, 5}, 2) << endl; 
    // // Expected: 3 (entire array, differences are exactly 2)

    // // Test Case 1: Simple valid escape path
    // cout << s.canEscape({
    //     {'#', '#', '#', '#', '#'},
    //     {'#', 'H', '.', '.', '.'},
    //     {'#', 'F', '#', '#', '#'},
    //     {'#', '#', '#', '#', '#'}
    // }) << endl; // Expected: "YES"

    // // Test Case 2: Fire blocks the only exit at the exact same minute
    // cout << s.canEscape({
    //     {'#', '#', '#', '#', '#'},
    //     {'#', '#', 'H', '.', 'F'},
    //     {'#', '#', '#', '#', '#'}
    // }) << endl; // Expected: "NO"

    // // Test Case 3: Surrounded on all sides by expanding fire
    // cout << s.canEscape({
    //     {'#', '#', '#', '#', '#'},
    //     {'#', 'F', '.', 'F', '#'},
    //     {'#', '.', 'H', '.', '#'},
    //     {'#', 'F', '.', 'F', '#'},
    //     {'#', '#', '#', '#', '#'}
    // }) << endl; // Expected: "NO"

    // // Test Case 4: Human starts directly on a boundary cell
    // cout << s.canEscape({
    //     {'H', '.', '.'},
    //     {'.', 'F', '.'},
    //     {'.', '.', '.'}
    // }) << endl; // Expected: "YES"

    // // Test Case 5: No fire on grid, clear exit
    // cout << s.canEscape({
    //     {'#', '#', '#', '#'},
    //     {'#', 'H', '.', '#'},
    //     {'#', '#', '.', '#'},
    //     {'#', '#', '.', '.'}
    // }) << endl; // Expected: "YES"

    // // Test Case 6: Multiple fire sources, human outruns them to the right boundary
    // cout << s.canEscape({
    //     {'F', '.', '.', '.', '.'},
    //     {'#', '#', '#', '#', '.'},
    //     {'H', '.', '.', '.', '.'},
    //     {'#', '#', '#', '#', 'F'}
    // }) << endl; // Expected: "YES"


    // // Test Case 1: Standard DP choice (Choosing 4+1+1 over 3+3)
    // 3 + 3 (cost: 4 + 4 = 8) vs 4 + 1 + 1 (cost: 5 + 1 + 1 = 7)
    // cout << s.makeTargetUsingMinCoins({1, 3, 4}, {1, 4, 5}, 6) << endl; // Expected: 7

    // Test Case 2: Target cannot be formed
    // Target 7 cannot be made using only even coins {2, 4}
    // cout << s.makeTargetUsingMinCoins({2, 4}, {1, 5}, 7) << endl; // Expected: -1

    // Test Case 3: Zero target boundary case
    // cout << s.makeTargetUsingMinCoins({1, 2, 3}, {10, 20, 30}, 0) << endl; // Expected: 0

    // Test Case 4: Preferring a smaller coin value due to drastically lower weight
    // 5x coin '2' (cost: 5 * 1 = 5) vs 2x coin '5' (cost: 2 * 100 = 200)
    // cout << s.makeTargetUsingMinCoins({2, 5}, {1, 100}, 10) << endl; // Expected: 5

    // Test Case 5: Single coin exact multiple
    // 3x coin '3' (cost: 3 * 7 = 21)
    // cout << s.makeTargetUsingMinCoins({3}, {7}, 9) << endl; // Expected: 21

    // Test Case 1: Simple window with positive weights
    // Subarray [0, 2] ({0, 1, 0}): Category '0' appears 2/3 times (> 1.5).
    // Total Weight = 10 + 20 + 30 = 60
    cout << s.maxTotalWeightAmongAllFrequnecyBalancedWindows({0, 1, 0}, {10, 20, 30}) << endl; 
    // Expected: 60

    // Test Case 2: Shorter window preferred over larger window due to negative weights
    // Subarray [0, 1] ({0, 0}): Category '0' appears 2/2 times (> 1.0). Total Weight = 100 + 100 = 200
    // Subarray [0, 3] ({0, 0, 1, 1}): No majority (2/4 is not > 2.0)
    cout << s.maxTotalWeightAmongAllFrequnecyBalancedWindows({0, 0, 1, 1}, {100, 100, -50, -50}) << endl; 
    // Expected: 200

    // Test Case 3: Long window accumulating higher total weight despite diluted majority
    // Subarray [0, 4] ({1, 2, 1, 3, 1}): Category '1' appears 3/5 times (> 2.5).
    // Total Weight = 10 + 50 + 10 + 50 + 10 = 130
    cout << s.maxTotalWeightAmongAllFrequnecyBalancedWindows({1, 2, 1, 3, 1}, {10, 50, 10, 50, 10}) << endl; 
    // Expected: 130

    // Test Case 4: Negative weights compensated by high positive weight interior
    // Subarray [0, 4] ({2, 0, 2, 1, 2}): Category '2' appears 3/5 times (> 2.5).
    // Total Weight = -10 + 100 - 10 + 100 - 10 = 170 (beats single element weight 100)
    cout << s.maxTotalWeightAmongAllFrequnecyBalancedWindows({2, 0, 2, 1, 2}, {-10, 100, -10, 100, -10}) << endl; 
    // Expected: 170

    // Test Case 5: Single element window (Length 1 is always frequency-balanced: 1/1 > 0.5)
    // Subarray [1, 1] ({1}): Category '1' appears 1/1 times (> 0.5).
    // Total Weight = 50
    cout << s.maxTotalWeightAmongAllFrequnecyBalancedWindows({0, 1, 2}, {-100, 50, -200}) << endl; 
    // Expected: 50
return 0;
}