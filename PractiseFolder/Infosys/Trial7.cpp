#include <bits/stdc++.h>
using namespace std;

using vint = vector<int>;
using vll = vector<long long>;
using vvint = vector<vint>;

/*
    Given an array a of size n and an integer k, you must perform the following operation exactly k times:

    Choose two indices i and j, and swap a[i] with a[j].
    Goal: Find the maximum possible MSS (Maximum Subarray Sum) after performing exactly k swaps.

    Note: Swapping the same pair again is allowed but useless since a double swap cancels out.
    Therefore, performing exactly k swaps is equivalent to performing at most k useful swaps.

    Input Format
    The first line contains an integer n, denoting the size of the array.
    The next line contains an integer k, denoting the number of swaps.
    Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing a[i].

    Constraints
    2 ≤ n ≤ 500
    0 ≤ k ≤ n
    -1000 ≤ a[i] ≤ 1000

    Example
    Input: 3 0 5 -1 5
    Output: 9
*/

/*
    You are given an undirected graph with N nodes and M edges. Each node u has a layer L[u] (integer from 1 to K) and
    a value V[u]. You must choose a simple path (no repeated nodes) such that:
    *   **Layer Constraint** Along the chosen path, the sequence of layers must be non-decreasing: L[u1] ≤ L[u2] ≤ ... ≤ L[ut]
    *   **Penalty for Layer Jumps** whenever the path moves from a node with layer x to layer y where y > x, you pay a
    *   cost: `penalty = (y - x)^2`.

    Find the maximum value of `(sum of V[u] over the path) - (sum of penalties)`.

    **Input Format**
        *   The first line contains an integer, N, denoting the number of rows in layers.
        *   The next line contains an integer, M, denoting the number of rows in edges.
        *   The next line contains an integer, K, denoting the max layer.
        *   Each line i of the N subsequent lines (where 0 ≤ i < N) contains 2 space separated integers each describing the row layers[i].
        *   Each line i of the M subsequent lines (where 0 ≤ i < M) contains 2 space separated integers each describing the row edges[i].
        *   Each row in edges[i] contains 2 space separated integers u and v denoting an edge between node u and node v.

    **Constraints**
        *   1 <= N <= 10^5
        *   1 <= M <= 10^5
        *   1 <= K <= 10^5
        *   -10^9 <= layers[i][j] <= 10^9
        *   0 <= edges[i][j] <= N-1

**Example 1:**
**Input:**
2
1
10
1 10
3 100
0 1

**Output:** 106
*/

/*
    Here is the text from the image:

    You want to buy food from a store. You have a scoring system that uses a unit called taste points.
    Each time you buy a type of food, you can measure its tastiness by the number of taste points you get from that food.
    You have N types of food. You can buy any type any number of times, as long as the total number of meals does not exceed M.

    However, you don't want to grow tired of a food if you buy it too often.
    Therefore, you will get v[i] – d[i] × (ti – 1) taste points when you buy the i-th type of food for the ti-th time.

    Find the maximum number of taste points you can achieve.

        **Input Format**

        *   The first line contains an integer, n, denoting the number of types of food you can buy.
        *   The next line contains an integer, m, denoting the maximum number of meals you can buy.
        *   Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing v[i].
        *   Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing d[i].

        **Constraints**

        *   1 <= n <= 10^5
        *   1 <= m <= 10^9
        *   1 <= v[i] <= 10^9
        *   1 <= d[i] <= 10^9
*/

/*
    A water station has bottles of different capacities. There is an unlimited supply of each bottle size.
    You need to store exactly X liters of water.

    Find the number of different ways to choose bottles such that the total capacity is exactly X liters.

    Two selections are considered the same if they use the same bottle sizes, regardless of the order in which
    they are chosen.

    Return the answer modulo $10^9 + 7$.
*/

/*
    You are given an array ARR which has N integers. You want to construct a new array RES using ARR by following the below algorithm:

    1. Initially, RES is empty
    2. Start at any index of ARR
    3. Choose a direction (left or right) and iterate over the elements of ARR starting from the chosen index in the chosen direction
    4. Add each iteration element to the end of the RES

    Additionally, it is given that the array ARR is cyclic. This means that after the last element you will
    iterate to the first one and vice versa.
    The value of RES is the sum of the bitwise XOR value of all the prefixes of it. That means that the value
    of RES can be defined as follows:

    `value(RES) = RES[0] + (RES[0]^RES[1]) + (RES[0]^RES[1]^RES[2]) + ........... + (RES[0]^RES[1]^RES[2]......^RES[N-1])`

    Find the maximum possible value of RES.

    *Example:*

    I/P: N= 10, ARR = [7 8 5 5 9 2 2 0 1 6]

    O/P: 99

    considering RES = [5 8 7 6 1 0 2 2 9 5]

    value(RES) = 5 + (5^8) + (5^8^7)+........

    value(RES) = 5 + 13 + 10+ 12+ 13+ 13+ 15+ 13+4+1.
*/

/*
    You have a array you need to perform the given task:
    1. If the array length is greater than 1 then take any two numbers which are X != Y and remove X and Y
    2. Else take X and remove X

    Count the minimum number of step to remove all element from list.

    I/P : 1 2
    O/P: 1

    I/P : 2 2
    O/P: 2

    I/P: 2 2 3 3 1
    O/P: 3 (2,3)(2,3)(1)
*/

class Solution
{
    int mod = 1e9 + 7;
    long long DFS(int u, vvint &adjList, vvint &layerValue, vint &visited, vll &dp)
    {
        if (visited[u] == 2)
        {
            dp[u] = max(dp[u], 1LL * layerValue[u][1]);
            return dp[u];
        }
        long long currValue = layerValue[u][1];
        long long localMaxi = currValue;
        visited[u] = 1;
        for (int &v : adjList[u])
        {
            if (visited[v] == 1)
                continue;
            long long d = 1LL * layerValue[v][0] - layerValue[u][0];
            long long penalty = d * d;
            long long nextMaxi = currValue + DFS(v, adjList, layerValue, visited, dp) - penalty;
            localMaxi = max(localMaxi, nextMaxi);
        }
        visited[u] = 2;
        return dp[u] = localMaxi;
    }
    bool check(int mid, vint &v, vint &d, int n, int m)
    {
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < mid)
                continue;
            count = count + (v[i] - mid) / d[i] + 1;
            if (count >= m)
                return true;
        }
        return false;
    }
    long long helper(vint &prefixXOR, int n)
    {
        long long maxi = 0;
        int left = 0, right = 0;
        vint bitArr(31, 0);

        // Slide through the 2N - 1 elements
        while (right < prefixXOR.size() - 1)
        {
            // 1. Add incoming element to the window
            int incoming = prefixXOR[right];
            for (int i = 30; i >= 0; i--)
            {
                if (incoming & (1LL << i))
                    bitArr[i]++;
            }

            // 2. When the window reaches size N, calculate value and slide
            if (right - left + 1 == n)
            {
                int X = (left == 0 ? 0 : prefixXOR[left - 1]);
                long long value = 0;

                // Calculate XOR sum
                for (int i = 30; i >= 0; i--)
                {
                    if (X & (1LL << i))
                        value += (1LL * n - bitArr[i]) * (1LL << i);
                    else
                        value += (1LL * bitArr[i]) * (1LL << i);
                }
                maxi = max(maxi, value);

                // Remove the leftmost element from the window
                int removing = prefixXOR[left];
                for (int i = 30; i >= 0; i--)
                {
                    if (removing & (1LL << i))
                        bitArr[i]--;
                }
                left++;
            }
            right++;
        }
        return maxi;
    }
    int solveForDirection(vint &arr)
    {
        int n = arr.size();
        vint prefixArr = arr;
        prefixArr.insert(prefixArr.end(), arr.begin(), arr.end());
        for (int i = 1; i < 2 * n; i++)
            prefixArr[i] = prefixArr[i] ^ prefixArr[i - 1];
        return helper(prefixArr, n);
    }

public:
    int maxSubArraySumAfterKSwaps(vint arr, int k)
    {
        int n = arr.size(), maxi = -1e9;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                vint inside, outside;
                for (int idx = 0; idx < n; idx++)
                {
                    if (idx >= i && idx <= j)
                        inside.push_back(arr[idx]);
                    else
                        outside.push_back(arr[idx]);
                }
                sort(inside.begin(), inside.end());
                sort(outside.rbegin(), outside.rend());
                int swaps = k, l = 0, r = 0;
                int n1 = inside.size(), n2 = outside.size();
                while (swaps && l < n1 && r < n2 && outside[r] > inside[l])
                {
                    swap(inside[l], outside[r]);
                    l++, r++, swaps--;
                }
                int subArraySum = 0;
                for (int idx = 0; idx < n1; idx++)
                    subArraySum = subArraySum + inside[idx];
                maxi = max(maxi, subArraySum);
            }
        }
        return maxi;
    }
    long long choosePathWithMaxValue(int n, int m, int k, vvint layerValue, vvint edges)
    {
        vvint adjList(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (layerValue[u][0] == layerValue[v][0])
            {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            else if (layerValue[u][0] < layerValue[v][0])
                adjList[u].push_back(v);
            else
                adjList[v].push_back(u);
        }
        long long globalMaxi = -1e10;
        vll dp(n + 1, 0);
        vint visited(n, 0);
        for (int i = 0; i < n; i++)
            globalMaxi = max(globalMaxi, DFS(i, adjList, layerValue, visited, dp));
        return globalMaxi;
    }
    long long maxTastePointsBrute(int n, int m, vint v, vint d)
    {
        // TLE for large 'm'.
        priority_queue<vint> pq;
        for (int i = 0; i < n; i++)
            pq.push({v[i], i});
        long long tastePoints = 0;
        while (!pq.empty() && m)
        {
            auto entry = pq.top();
            pq.pop();
            int points = entry[0], idx = entry[1];
            tastePoints += entry[0];
            entry[0] -= d[idx];
            pq.push(entry);
            m--;
        }
        return tastePoints;
    }
    long long maxTastePointsOptimal(int n, int m, vint v, vint d)
    {
        // maximise the lowest taste Point Value.
        int low = 0, high = *max_element(v.begin(), v.end()), ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, v, d, n, m))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        long long totalPoints = 0;
        int meals = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > ans)
            {
                long long t = (v[i] - (ans + 1)) / d[i] + 1;
                long long firstTerm = v[i], lastTerm = v[i] - (t - 1) * d[i];
                totalPoints += t * (firstTerm + lastTerm) / 2;
                meals += t;
            }
        }
        long long remainingMeals = m - meals;
        if (ans > 0 && remainingMeals > 0)
            totalPoints += remainingMeals * ans;

        return totalPoints;
    }
    int numberOfWays(int x)
    {
        vint dp(x + 1, 0);
        dp[0] = 1;
        for (int b = 1; b <= x; b++)
        {
            for (int i = b; i <= x; i++)
            {
                dp[i] = (1LL * dp[i] + dp[i - b]) % mod;
            }
        }
        return dp[x];
    }
    string removeDigit(string number, char digit)
    {
        int n = number.size(), deletionIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (number[i] == digit)
            {
                deletionIdx = i;
                if (i != n - 1 && number[i] < number[i + 1])
                    break;
            }
        }
        number.erase(deletionIdx, 1);
        return number;
    }
    int getMaximumGenerated(int n)
    {
        if (!n)
            return 0;
        vector<int> sternArr(n + 1, -1);
        sternArr[0] = 0, sternArr[1] = 1;
        int maxi = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                sternArr[i] = sternArr[i / 2];
            else
                sternArr[i] = sternArr[i / 2] + sternArr[i - i / 2];
            maxi = max(maxi, sternArr[i]);
        }
        return maxi;
    }
    int getMaxPossibleValueOfRes(vint arr)
    {
        int maxi = solveForDirection(arr); // right
        reverse(arr.begin(), arr.end());
        maxi = max(maxi, solveForDirection(arr)); // left
        return maxi;
    }
    int minOperationsToEmptyList(vint arr){
        unordered_map<int,int> freqMap;
        int maxF=0, n=arr.size();
        for(int i=0;i<n;i++)
            maxF=max(maxF,++freqMap[arr[i]]);
        return max((n+1)/2,maxF);
    }
};

int main()
{
    Solution s;

    cout << s.maxSubArraySumAfterKSwaps({5, -1, 5}, 0) << endl;
    cout << s.maxSubArraySumAfterKSwaps({-10, 3, -5, 7, 2}, 5) << endl;
    cout << s.maxSubArraySumAfterKSwaps({5, -1, 5, -1, 5}, 2) << endl;
    cout << s.maxSubArraySumAfterKSwaps({2, -1, 2, -1, 2}, 1) << endl;
    cout << s.maxSubArraySumAfterKSwaps({-11, -3, -1, -3}, 4) << endl;

    // 1. Original Example
    // Expected: 106 (Path 0 -> 1: 10 + 100 - (3-1)^2 = 106)
    cout << s.choosePathWithMaxValue(2, 1, 10, {{1, 10}, {3, 100}}, {{0, 1}}) << endl;

    // 2. The DP Memoization Bug (tests if 0 -> 2 is evaluated properly instead of just 0 -> 1 -> 2)
    // Expected: 36 (Path 0 -> 2 is optimal: 10 + 30 - (3-1)^2 = 36)
    cout << s.choosePathWithMaxValue(3, 3, 3, {{1, 10}, {2, -100}, {3, 30}}, {{0, 1}, {1, 2}, {0, 2}}) << endl;

    // 3. The Global Maximum Trap (tests if a path starting at a later node is considered)
    // Expected: 1000 (Path starting and ending at node 1 is optimal)
    cout << s.choosePathWithMaxValue(2, 1, 10, {{1, 10}, {10, 1000}}, {{0, 1}}) << endl;

    // 4. The Integer Overflow (tests penalty calculation exceeding 32-bit int)
    // Expected: 20 (Path starting and ending at node 1. If overflow happens, it might print > 10^9)
    cout << s.choosePathWithMaxValue(2, 1, 100000, {{1, 10}, {100000, 20}}, {{0, 1}}) << endl;

    // 5. The Cycle Trap (Same layer traversal without infinite loop)
    // Expected: 60 (Path 0 -> 1 -> 2. All same layer, 10 + 20 + 30 = 60)
    cout << s.choosePathWithMaxValue(3, 3, 10, {{1, 10}, {1, 20}, {1, 30}}, {{0, 1}, {1, 2}, {0, 2}}) << endl;

    // 6. Negative values everywhere (tests globalMaxi initialization)
    // Expected: -5 (Path starting and ending at node 0)
    cout << s.choosePathWithMaxValue(2, 1, 10, {{1, -5}, {2, -100}}, {{0, 1}}) << endl;

    cout << s.numberOfWays(3) << endl;
    cout << s.removeDigit("739197", '7') << endl; 
    cout<<s.getMaxPossibleValueOfRes({4,0,2,1})<<endl;
    cout<<s.minOperationsToEmptyList({2,3,2,3,1})<<endl;
    cout<<s.minOperationsToEmptyList({2,2,3,1,1,1})<<endl;
    return 0;
}