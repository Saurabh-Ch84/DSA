#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vll=vector<long long>;
using vvll=vector<vll>;

/*
    You are given an array A of N positive integers representing the energy gained by a system at each step. 
    The cumulative energy at step k is defined as the sum of all energy gained from step 1 to step k (inclusive).
    A "Resonance" occurs between step i and step j if, at the cumulative energy at step j is a perfect multiple of the 
    cumulative energy at step i.

    Find the total number of Resonances that occur.
    Return the count modulo 10^9 + 7.

    Constraints:
        1<=n<=1e5
        1<=A[i]<=10
*/

/*
    You are coordinating schedules for a conference center with exactly N available meeting rooms. 
    There are M meeting requests, where each meeting i is described by:

    A start time s_i, An end time t_i, A priority value p_i
    A room becomes free exactly at the ending time of its current meeting, meaning a meeting starting at time 
    t may use a room whose previous meeting ended at time t.

    The scheduling system processes meetings in increasing order of start time and maintains at most N active meetings simultaneously.

    Whenever a new meeting begins:
        All meetings that have already ended are removed from the active schedule
        If fewer than N meetings are currently active, the new meeting is accepted. 
        Otherwise, the new meeting replaces the currently active meeting with the smallest priority only if its priority is strictly larger
        Your task is to simulate this scheduling policy and determine the final total priority of all accepted meetings.
        Find the final total priority after applying the scheduling policy.

    Input Format
        The first line contains a single integer, N, denoting the number of available meeting rooms.
        The second line contains a single integer, M, denoting the number of incoming requests, or meetings.
        Each of the $M lines contains 3 space-separated integers, representing s_i, t_i, p_i, of meeting i.
*/

/*
    You are tasked with scheduling N meetings in a facility with multiple rooms. Each meeting (from 1 to N) is 
    defined by a **start_time**, an **end_time**, and a **protocol** (either 0 for Standard Protocol or 1 Specialized Protocol). 
    The rooms in the facility have specific **reuse rules** to prevent contamination:

    - A room can be **reused immediately** for a subsequent meeting if the new meeting requires the **same protocol** as the previous one.
      That is, if a Standard Protocol meeting finishes another Standard meeting can take place in the same room as soon as the previous one ends. 
      The same rule applies when switching from a Specialized Protocol meeting to another Specialized Protocol meeting.

    - If the next meeting requires a **different protocol**, a mandatory **K minute deep-cleaning buffer** is required. 
      This means if a Standard Protocol meeting finishes at time **t**, a Specialized Protocol meeting cannot start in that room until 
      time **t + K** or later. The same rule applies when switching from a Specialized Protocol meeting to a Standard Protocol meeting.

    **Find the minimum number of rooms required to accommodate all N meetings, respecting these sanitization rules.**
---

### Input Format:
- The first line contains an integer, **N**, denoting the number of available meetings.
- The second line contains an integer, **K**, denoting the deep-cleaning buffer duration required when switching protocols.
- Each of the N lines contains 3 space-separated integers, representing row i of meetings.

### Constraints:
- 1 ≤ N ≤ 10⁵  
- 0 ≤ K ≤ 10⁹  
- 0 ≤ meetings[i][j] ≤ 10⁹  

---

### Sample Test Cases:

#### Case 1:
**Input:**
```
4
3
0 5 0
1 3 1
4 6 0
7 9 1
```
**Output:**
```
3
```
**Explanation:**  
Meetings (0,5,0) and (1,3,1) overlap, requiring two rooms. Meeting (4,6,0) then requires a third room because its start time 
of 4 is before the first room finishes (at 5) and before the second room is sanitized (available at 3+3=5) for a protocol switch.

---

#### Case 2:
**Input:**
```
5
100
0 10 0
15 20 0
25 30 1
35 40 0
45 50 1
```
**Output:**
```
2
```

---

#### Case 3:
**Input:**
```
5
1
1 10 0
2 9 1
3 8 0
4 7 1
5 6 0
```
**Output:**
```
5
```
**Explanation:**  
All meetings overlap heavily. No reuse is possible. Each needs a separate room, Total = 5.
*/

/*
    You are tasked with assembling a scientific sample weighing exactly *W* grams by using a set of *N* unique metallic coin types.

    Unlike the standard change-making problem where you have an unlimited supply, you must operate within the strict physical limits of your
    inventory. Each coin type *k* is defined by its individual weight *d[k]* and its scarcity, represented by a **maximum available count** *cnt[k]*.

    Your goal is to reach the target weight of exactly *W* grams using the **minimum total number of coins** possible. 
    If it is impossible to form the weight *W* using the available coins and their respective quantities, you must return **-1**.

    Find the **minimum number of coins** or **-1** if impossible.

    **Input Format**
        The first line contains an integer, *N*, denoting the number of coin denominations.
        The second line contains an integer *T*, denoting the target weight amount to be achieved.
        Each of the *N* lines contains 2 space-separated integers, representing row *i* of coins.

    Constraints
        1<=N<=10^5
        1<=T<=10^5
        -10^9<=coins[i][j]<=10^9
*/

class Solution {
    int mod = 1e9 + 7;
    long long inf=1e10;
    long long recursion(int i,int n,int t,vvint &coins,vvll &dp){
        if(i==n) return (t? inf: 0);
        if(t==0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        long long skip=recursion(i+1,n,t,coins,dp), take=inf;
        int count=coins[i][1], f=1;
        while(f<=count && t>=coins[i][0]*f){
            long long takef=f+recursion(i+1,n,t-coins[i][0]*f,coins,dp);
            take=min(take,takef);
            f++;
        }
        return dp[i][t]=min(skip,take);
    }
public:
    int findNumberOfResonances(vint arr) {
        int n = arr.size();
        vector<int> prefixArr(n, 0);
        prefixArr[0] = arr[0];
        for(int i = 1; i < n; i++)
            prefixArr[i] = prefixArr[i - 1] + arr[i];
        int maxi = prefixArr[n - 1];
        // 1. Use boolean array for extreme memory efficiency
        vector<bool> valueArray(maxi + 1, false);
        for(int i = 0; i < n; i++){
            valueArray[prefixArr[i]] = true;
        }
        long long count = 0;
        // 2. Loop strictly over the values that exist
        for(int i = 0; i < n; i++) {
            int current_sum = prefixArr[i];
            // 3. Use addition instead of multiplication for speed
            for (int val = current_sum * 2; val <= maxi; val += current_sum) {
                if (valueArray[val]) {
                    count = (count + 1) % mod;
                }
            }
        }
        return count % mod;
    }
    long long scheduleMeetings(int n, vvint meetings) {
        if(!n) return 0;
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
    
        set<pair<int,int>> s1, s2; 
        long long prioritySum = 0;
    
        for(int i = 0; i < m; i++) {
            int sI = meetings[i][0], eI = meetings[i][1], pI = meetings[i][2];
        
            // 1. ALWAYS clear ended meetings first
            while(!s1.empty() && s1.begin()->first <= sI) {
                int eJ = s1.begin()->first, j = s1.begin()->second;
                int pJ = meetings[j][2];
                prioritySum += pJ;
                s1.erase({eJ, j});
                s2.erase({pJ, j});
            }
        
            // 2. Accept if we have room
            if(s1.size() < n) {
                s1.insert({eI, i});
                s2.insert({pI, i});
            }
            // 3. Otherwise, check for preemption
            else {
                int pJMin = s2.begin()->first;
                if(pI > pJMin) {
                    int j = s2.begin()->second;
                    int eJ = meetings[j][1];
                    s1.erase({eJ, j});
                    s2.erase({pJMin, j});
                    
                    s1.insert({eI, i});
                    s2.insert({pI, i});
                }
            }
        }
    
        // Add whatever is left in the active rooms
        for (set<pair<int, int>>::const_iterator it = s2.begin(); it != s2.end(); ++it) {
            prioritySum += it->first;
        }
        return prioritySum;
    }
    int minRoomsToScheduleMeetings(int k,vvint meetings){
        int n=meetings.size(), minRooms=0;
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vint,greater<int>> pq0, pq1;
        for(int i=0;i<n;i++){
            int sT=meetings[i][0], eT=meetings[i][1], p=meetings[i][2];
            auto &matchingPQ=(p? pq1: pq0); 
            auto &nonMatchingPQ=(p? pq0: pq1); 
            if(!matchingPQ.empty() && matchingPQ.top()<=sT)
                matchingPQ.pop();
            else if(!nonMatchingPQ.empty() && nonMatchingPQ.top()+k<=sT)
                nonMatchingPQ.pop();
            matchingPQ.push(eT);
            minRooms=max(minRooms,(int)pq0.size()+(int)pq1.size());
        }
        return minRooms;
    }
    int minCoinsToWeigh(vvint coins,int T){
        int n=coins.size();
        vvint coins_;
        int minCoinDenomination=1e9;
        for(int i=0;i<n;i++){
            int denomination=coins[i][0], count=coins[i][1];
            if(count<=0 || denomination<=0) continue;
            coins_.push_back({denomination,count});
            minCoinDenomination=min(minCoinDenomination,denomination);
        }
        if(T<minCoinDenomination) return -1;
        if(T==minCoinDenomination) return 1;
        n=coins_.size();
        vvll dp(n+1,vll(T+1,-1));
        long long minCoins=recursion(0,n,T,coins_,dp);
        return (minCoins>=inf? -1: minCoins);
    }
};

int main(){
    Solution s;
    cout<<s.findNumberOfResonances({1,2,3,4,10,40,17})<<endl;

    // Test Case 1
    cout << s.scheduleMeetings(2, {{1, 3, 10}, {2, 4, 20}, {5, 6, 15}}) << endl;
    // Expected Output: 45

    // Test Case 2
    cout << s.scheduleMeetings(1, {{1, 5, 10}, {2, 6, 20}, {7, 8, 5}}) << endl;
    // Expected Output: 25

    // Test Case 3
    cout << s.scheduleMeetings(3, {{1, 2, 10}, {3, 4, 20}, {5, 6, 30}}) << endl;
    // Expected Output: 60

    // Test Case 4
    cout << s.scheduleMeetings(2, {{1, 10, 5}, {2, 11, 10}, {3, 12, 15}, {4, 13, 20}}) << endl;
    // Expected Output: 35

    // Test Case 5
    cout << s.scheduleMeetings(2, {{1, 5, 10}, {1, 6, 20}, {1, 7, 15}}) << endl;
    // Expected Output: 35

    // Test Case 6 (Edge case: No rooms)
    cout << s.scheduleMeetings(0, {{1, 5, 10}, {2, 6, 20}, {3, 7, 30}}) << endl;
    // Expected Output: 0

    // Test Case 7 (Large input)
    cout << s.scheduleMeetings(3, {{1, 4, 10}, {2, 5, 20}, {3, 6, 30}, {4, 7, 40}, {5, 8, 50}, {6, 9, 60}}) << endl;
    // Expected Output: 210

    cout << s.minRoomsToScheduleMeetings(3, {{0,5,0}, {1,3,1}, {4,6,0}, {7,9,1}}) << endl;
    // Expected Output: 3

    cout << s.minRoomsToScheduleMeetings(3, {{0,5,0}, {1,3,1}, {4,6,0}, {7,11,1}, {8,12,1}, {16,19,0}}) << endl;
    // Expected Output: 3

    cout << s.minRoomsToScheduleMeetings(100, {{0,10,0}, {15,20,0}, {25,30,1}, {35,40,0}, {45,50,1}}) << endl;
    // Expected Output: 2

    cout << s.minRoomsToScheduleMeetings(1, {{1,10,0}, {2,9,1}, {3,8,0}, {4,7,1}, {5,6,0}}) << endl;
    // Expected Output: 5

    cout<<s.minCoinsToWeigh({{3,2},{4,1}},10)<<endl;
    // Expected Output: 3

    cout<<s.minCoinsToWeigh({{1,10},{5,2}},10)<<endl;
    // Expected Output: 2
return 0;
}