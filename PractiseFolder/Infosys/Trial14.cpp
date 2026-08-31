#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vvvint=vector<vvint>;

using vll=vector<long long>;
using vvll=vector<vll>;
using vvvll=vector<vvll>;

int mod=1e9+7;
long long inf=1e12, negInf=-1e12;
int intInf=1e6, intNegInf=-1e6;

/*
    You are given a tree of n nodes, each node has a value a[i] written on it. The tree is rooted at node 1.
    A pair of nodes i, j (where 1 ≤ i < j ≤ n) is considered GOOD if a[i]×a[j] is a perfect square.
    We define beauty(u) as the number of good pairs of nodes in the subtree of u. Your task is to
    find the sum of beauty(i) for each 1 ≤ i ≤ n. Return the sum of these values modulo 1e9 + 7.

    Function Description
        Name : get_ans
        Parameters:
        - n (INTEGER): The size of the tree
        - par (INTEGER ARRAY): The parent array par[1] = 0
        - a (INTEGER ARRAY): The values written on the nodes
        Return : INTEGER
        - The sum of beauty of each node modulo 10^9 + 7

    Constraints
        • 1 ≤ n ≤ 1e5
        (Size of the tree)
        • 0 ≤ par[i] ≤ n (Valid parent indices)
        • par[1] = 0 (Root is node 1, which has no parent)
        • 1 ≤ a[i] ≤ 1e9
        (Node values)
        • All values must be considered for perfect square pairs
        • Result must be modulo 1e9 + 7

    Input Format
        Integer n
        - Size of the tree
        Next n lines: par[0], par[1], ..., par[n-1]
        - Parent array of the rooted tree
        - par[0] is typically 0 (root indicator)
        - par[i] is the parent of node i (1-indexed)
        Next n lines: a[0], a[1], ..., a[n-1]
        - Values written on each node
        - Each value is between 1 and 10^9

    Output Format
        Single Integer: The sum of beauty values for all nodes modulo 1e9 + 7

    Sample Test Case 1
    Input:
        5
        0
        1
        1
        2
        2
        2
        3
        6
        12
        27
    Output: 6

    Tree Structure:
          1(2)
         /  \
       2(3) 3(6)
      /   \
   4(12)  5(27)
    Node Values:
    • Node 1: 2
    • Node 2: 3
    • Node 3: 6
    • Node 4: 12
    • Node 5: 27

    Computing Beauty for Each Node:
    • beauty(5) = 0 (Only one node in subtree of 5; no pairs possible)
    • beauty(4) = 0 (Only one node in subtree of 4; no pairs possible)
    • beauty(3) = 0 (Only one node in subtree of 3; no pairs possible)
    • beauty(2) = 3 (Subtree of 2: {2, 4, 5} with values {3, 12, 27})
    – Pair (2, 4): 3 × 12 = 36 = 6^2 (Perfect square)
    – Pair (2, 5): 3 × 27 = 81 = 9^2 (Perfect square)
    – Pair (4, 5): 12 × 27 = 324 = 18^2 (Perfect square)

    • beauty(1) = 3 (Entire tree: {1, 2, 3, 4, 5} with values {2, 3, 6, 12, 27})
    – Good pairs are the same three from subtree of 2
    - Sum of beauty values:
            beauty(1) + beauty(2) + beauty(3) + beauty(4) + beauty(5) = 3 + 3 + 0 + 0 + 0 = 6
    Answer: 6
*/

/*
    You are given an array a of length n and an integer p.
    A non-empty subsequence of a is considered GOOD if the following conditions hold:
        1. The length of the subsequence is strictly less than n.
        2. The greatest common divisor of the elements of the subsequence is exactly p.
    You have to process q queries of the following form: i j : replace a[i] with j (where 1 ≤ i ≤ n and 1 ≤ j ≤ 1e5).

    After each query, you must check if there exists any good subsequence. If it exists, the answer to that query is YES.
    Find the number of queries that were answered YES.
    Function Description
        Name : get_ans
        Parameters:
        - n (INTEGER): The size of the array
        - a (INTEGER ARRAY): The elements of the array
        - p (INTEGER): The required gcd
        - q (INTEGER): The number of queries
        - queries (INTEGER 2D ARRAY): The queries, each with format [i, j]
        Return : INTEGER
        - The number of queries that were answered yes

    Constraints
        • 1 ≤ n ≤ 1e5
        • 1 ≤ a[i] ≤ 1e5
        • 1 ≤ p ≤ 1e5
        • 1 ≤ q ≤ 1e5
        • 2 ≤ columns of queries ≤ 2
        • 1 ≤ queries[i][j] ≤ 1e5

        Input Format
    Line 1: Integer n
    - Number of elements in the array
    Next n lines: a[0], a[1], ..., a[n-1]
    - Elements of the array
    Line n+2: Integer p
    - The required gcd
    Line n+3: Integer q
    - Number of queries
    Line n+4: Integer two
    - Number of columns in queries (always 2)
    Next q lines: queries[0], queries[1], ..., queries[q-1]
    - Each line contains two space-separated integers [i, j]
    - i: 1-indexed position in array
    - j: new value to replace a[i-1]

    Output Format Single Integer: The number of queries answered yes.

    Sample Test Case 1
    Input:
        4
        3
        9
        12
        15
        18
        3
        3
        1 9
        2 6
        4 12
    Output: 3
    Initial Setup
    n = 4, p = 3, a = [9, 12, 15, 18], q = 3
    All elements are divisible by 3. So initially, c = 4.

    Query 1: (1, 9)
    Replace a[1] = 9 → 9 (no change)
    Still divisible by 3.
    Array: [9, 12, 15, 18]
    gcd(9, 12, 15, 18) = 3
    Contributes to answer.

    Query 2: (2, 6)
    Replace a[2] = 12 → 6 (still divisible by 3).
    Array: [9, 6, 15, 18]
    gcd(9, 6, 15, 18) = 3
    Contributes to answer.

    Query 3: (4, 12)
    Replace a[4] = 18 → 12 (still divisible by 3).
    Array: [9, 6, 15, 12]
    gcd = 3
    Contributes to answer.

    Total YES answers = 3
*/

/*
    You are given an array A of length N and an integer M.
    A subsequence of A is considered GOOD if the following conditions hold:
        1. The elements of the subsequence are non-decreasing.
        2. The bitwise XOR of these elements is at least M.
    Find the length of the longest good subsequence. If it is not possible to choose any subsequence, then the answer is 0.
    
    Function Description
        Name : get_ans
        Parameters:
        - N (INTEGER): The size of the array
        - M (INTEGER): The minimum allowed xor
        - A (INTEGER ARRAY): The elements of the array
        Return : INTEGER - The length of the longest good subsequence

    Constraints
        • 1 ≤ N ≤ 1000
        • 1 ≤ M ≤ 500
        • 1 ≤ A[i] ≤ N

    Input Format
        Line 1: Integer N
        - Number of elements in array A
        Line 2: Integer M
        - The minimum allowed XOR value
        Next N lines: A[0], A[1], ..., A[N-1]
        - Elements of the array

    Output Format
        Single Integer: The length of the longest good subsequence
    Sample Test Case
        Input:
        2
        1
        1
        2
        Output:
        2
    Technical Interview Questions Coding Assessment
    Parameters: N = 2, M = 1, A = [1, 2]
    Non-decreasing subsequences:
    • [1]: XOR = 1 ≥ 1 Length = 1
    • [2]: XOR = 2 ≥ 1 Length = 1
    • [1, 2]: XOR = 1 ⊕ 2 = 3 ≥ 1 Length = 2
    Longest good subsequence: [1, 2] with length 2
    Answer: 2
*/

/*
    You are given a rooted tree with N nodes labeled 0 . . . N − 1 (root 0). Each node has a binary
    value Val[i] ∈ {0, 1}. The array Parent[i] defines the tree structure (Parent[0] = 0; for i > 0, Parent[i] is the parent of node i).

    You may flip a set of parent-child edges such that no two flipped edges share a node (the flipped
    edges form a matching). Flipping an edge toggles both endpoints’ binary values (0 ↔ 1) and costs M coins. 
    Each edge can be flipped at most once.
    For a binary string q, a root-to-leaf path is NATURAL if, after flips, its node values contain q as a contiguous substring.

    For each of Q queries (binary strings), you must:
    • Choose any valid flips to MAXIMIZE the number of natural root-to-leaf paths
    • Among all choices with maximum natural paths, pick the one with MINIMUM total cost (M× number of flipped edges)
    Find the SUM OF MINIMUM COSTS over all Q queries.

    Function Description
        Name: get_ans
        Parameters:
        - N (INTEGER): Number of nodes in the tree
        - M (INTEGER): Cost per flipped edge
        - Parent (INTEGER ARRAY): Parent array
        - Val (INTEGER ARRAY): Binary values at each node
        - Q (INTEGER): Number of queries
        - queries (STRING ARRAY): Binary string queries
        Return : INTEGER
        - Sum of minimum costs for all queries
    Constraints
        • 1 ≤ N ≤ 1e5
        • 1 ≤ M ≤ 1e5
        • 0 ≤ Parent[i] ≤ 1e5
        • 0 ≤ Val[i] ≤ 1
        • 1 ≤ Q ≤ 1e5
        • 1 ≤ len(queries[i]) ≤ 1e5
    Input Format
        • The first line contains an integer, N, denoting the number of nodes.
        • The next line contains an integer, M, denoting the cost per edge flip.
        • Each line i of the N subsequent lines (0 i < N) contains an integer describing Parent[i]
        • Each line i of the N subsequent lines (0 i < N) contains an integer describing Val[i].
        • The next line contains an integer, Q, denoting the number of queries.
        • Each line i of the Q subsequent lines (0 i < Q) contains a string describing queries[i].
    Output Format
        Single Integer: Sum of minimum costs for all queries
    Sample Test Case
    Input:
        6
        3
        0
        0
        0
        1
        1
        2
        1
        0
        1
        1
        2
        10
        011
    Output: 6
    Explanation:
    • Query 1 → “10”
    – Look at path 0 → 1 → 4: values 1, 0, 0 — it already contains 1, 0.
    – Therefore no flips are required for this query.
    – Cost for this query = 0 flips ×M = 0 × 3 = 0.

    • Query 2 → “011”
    – In the current labeling there is no path containing 0, 1, 1.
    – By flipping values in up to two subtrees, we can create a path that contains 0, 1, 1.
    – The DP determines the minimum number of flips to achieve that pattern is 2 flips for this query.
    – Cost for this query = 2 flips ×M = 2 × 3 = 6.
    
    Total Cost = (0 + 6) = 6

    Sample Test Case 2
    Input:
        4
        3
        0
        0
        1
        1
        0
        0
        0
        2
        10
        11
    Output:
    3
    Explanation:
    • Query 1 → “10”
    – Need a subsequence 1 → 0.
    – Current tree values are all 0, so the first 1 is missing.
    – By flipping 1 edge (e.g., the edge to node 1 or node 0 itself), we can create a 1 along
    a path that allows “10” to appear.
    – Cost for this query = 1 flip ×M = 1 × 3 = 3.
    • Query 2 → “11”
    15
    Technical Interview Questions Coding Assessment
    – Need a subsequence 1 → 1.
    – After previous flips, there may already be a 1 in the path.
    – Optimal strategy in the code finds that no additional flips are needed, because
    the previous configuration already allows “11” to appear.
    – Cost for this query = 0 × 3 = 0.
    Total Cost = 3 + 0 = 3
*/

struct Node {
    int count;   // Number of elements in range divisible by p
    int gcd_val; // GCD of elements in range divisible by p (0 if count == 0)
};

class SegmentTree {
    int n, p;
    vector<Node> tree;
    vector<int> arr;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.count = left.count + right.count;
        res.gcd_val = gcd(left.gcd_val, right.gcd_val);
        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            if (arr[start] % p == 0) {
                tree[node] = {1, arr[start]};
            } else {
                tree[node] = {0, 0};
            }
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[start] = val;
            if (val % p == 0) {
                tree[node] = {1, val};
            } else {
                tree[node] = {0, 0};
            }
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Checks if removing any single element leaves a remaining GCD equal to p
    bool can_remove_one(int node, int start, int end, int outside_gcd) {
        if (outside_gcd == p) return true;
        if (start == end) return outside_gcd == p;

        int mid = start + (end - start) / 2;
        
        // GCD of elements outside the left child
        int g_left = gcd(outside_gcd, tree[2 * node + 1].gcd_val);
        if (g_left == p) return true;

        // GCD of elements outside the right child
        int g_right = gcd(outside_gcd, tree[2 * node].gcd_val);
        if (g_right == p) return true;

        if (g_left % p == 0 && can_remove_one(2 * node, start, mid, g_left)) return true;
        if (g_right % p == 0 && can_remove_one(2 * node + 1, mid + 1, end, g_right)) return true;

        return false;
    }

public:
    SegmentTree(int n, int p, const vector<int>& a) : n(n), p(p), arr(a) {
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    bool is_good() {
        // Condition 1: Must have elements divisible by p, and their overall GCD must be p
        if (tree[1].count == 0 || tree[1].gcd_val != p) {
            return false;
        }
        // Condition 2: If strictly fewer than n elements are multiples of p, 
        // the subset of multiples is already a proper valid subsequence (length < n)
        if (tree[1].count < n) {
            return true;
        }
        // Condition 3: If all n elements are multiples of p, check if removing 
        // 1 element leaves a remaining GCD equal to p
        return can_remove_one(1, 0, n - 1, 0);
    }
};

class Solution{
    int recursion(int i,int prev,int x,int n,int m,vint &arr,vvvll &dp){
        if(i==n) return (x>=m? 0:intNegInf);
        if(dp[i][prev][x]!=-1) return dp[i][prev][x];
        int skip=recursion(i+1,prev,x,n,m,arr,dp), take=intNegInf;
        if(arr[i]>=prev)
            take=1+recursion(i+1,arr[i],x^arr[i],n,m,arr,dp);
        return dp[i][prev][x]=max(skip,take);
    }
    vint preprocess(int n, vint &arr) {
        vint cores(n, 1);
        for (int i = 0; i < n; i++) {
            int val = arr[i], core = 1;
            for (int j = 2; 1LL * j * j <= val; j++) {
                if (val % j == 0) {
                    int count = 0;
                    while (val % j == 0) {
                        count++;
                        val /= j;
                    }
                    // Keep prime factor only if exponent is odd
                    if (count % 2 != 0) core *= j;
                }
            }
            if (val > 1) core *= val; // Remaining prime factor
            cores[i] = core;
        }
        return cores;
    }
    pair<long long,unordered_map<int,int>> DFS(int u,vvint &adjList,vint &squareFreeCores){
        long long ans=0;
        unordered_map<int,int> parentCoreMap;
        for(int &v: adjList[u]){
            pair<long long,unordered_map<int,int>> childInfo=DFS(v,adjList,squareFreeCores);
            int existingPairs=childInfo.first;
            ans=(ans+existingPairs)%mod;
            unordered_map<int,int> childCoreMap=childInfo.second;
            for(auto &p: childCoreMap)
                parentCoreMap[p.first]+=p.second;
        }
        int currCore=squareFreeCores[u];
        parentCoreMap[currCore]++;
        for(auto &p: parentCoreMap){
            int freq=p.second;
            ans=(ans+1LL*freq*(freq-1)/2)%mod;
        }
        return {ans,parentCoreMap};
    }
        public:
    int get_ans1(vint parent,vint arr){
        int n=arr.size(), root=0, maxi=0;
        vvint adjList(n);
        for(int v=0;v<n;v++){
            int u=parent[v];
            if(!u) continue;
            adjList[u-1].push_back(v);
        }
        vint squareFreeCores=preprocess(n,arr);
        pair<long long,unordered_map<int,int>> treeInfo=DFS(root,adjList,squareFreeCores);
        return treeInfo.first;
    }
    int get_ans2(int n, vector<int> a, int p, int q, vector<vector<int>> queries) {
        SegmentTree st(n, p, a);
        int yes_count = 0;

        for (int k = 0; k < q; k++) {
            int idx = queries[k][0] - 1; // 1-based to 0-based
            int val = queries[k][1];

            st.update(idx, val);

            if (st.is_good()) {
                yes_count++;
            }
        }

        return yes_count;
    }
    int get_ans3(vint arr, int m) {
        int n = arr.size(), maxi = arr[0];
        for (int i = 1; i < n; i++)
            maxi = max(maxi, arr[i]);
        int l = 0;
        for (int i = 30; i >= 0; i--) {
            if (maxi & (1 << i)) {
                l = 1 << (i + 1);
                break;
            }
        }
        vvvll dp(n + 1, vvll(n + 1, vll(l, intNegInf)));
        long long ans=recursion(0,0,0,n,m,arr,dp);
        return (ans<=0? 0:ans);
    }
};

int main(){
    Solution s;
    cout<<s.get_ans3({1,2},1)<<endl; // 2
    cout<<s.get_ans3({1,1},1)<<endl; // 1

    // Sample Test Case 1
    cout << s.get_ans1({0, 1, 1, 2, 2}, {2, 3, 6, 12, 27}) << endl;
    // Expected Output: 6

    // Test Case 2: Single Node (Edge Case)
    cout << s.get_ans1({0}, {10}) << endl;
    // Expected Output: 0

    // Test Case 3: Line Tree with Identical Values (Chain 1 -> 2 -> 3)
    cout << s.get_ans1({0, 1, 2}, {4, 4, 4}) << endl;
    // Expected Output: 4

    // Test Case 4: Star Tree (Root 1 with children 2, 3, 4)
    cout << s.get_ans1({0, 1, 1, 1}, {2, 8, 18, 5}) << endl;
    // Expected Output: 3
return 0;
}