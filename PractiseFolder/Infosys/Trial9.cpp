#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;

using vll=vector<long long>;
using vvll=vector<vll>;
using vvvll=vector<vvll>;


/*
    Q-1) Find the number of pairs divisible by T. One element can be used only one time.
    You have been given an array of n integers and T.
*/

/*
    Q-2) You are given a row × col matrix of integers.
        You start at the top-left cell (0, 0) and need to reach the bottom-right cell (row - 1, col - 1).

        You are allowed to move only:
            Right (i, j + 1)
            Down (i + 1, j)

        Movement Constraint
            You can move Down at any time.
            You can move Right only if the value of the current cell is strictly less than the value of the cell to its right.

        Objective:
        Find the maximum possible sum of the values along a valid path from the start to the destination (including both the starting and ending cells).
        If no valid path exists, return -1.

*/

/*
    Q-3) You are operating an energy harvester moving along an array `a[1...n]` from left to right. 
    You begin at position 1 always in *Collect* mode.

    At each position `i`, you perform your current mode's action:
        - *Collect mode:* You gain `a[i]`, and your "Heat" counter increases by 1
        - *Skip mode:* You gain 0, and your "Heat" counter resets to 0

    Before moving to position `i+1`, you may choose to switch your mode (from Collect to Skip, or from Skip to Collect). 
    Every switch costs `s`.

    Your harvester can safely operate for a maximum heat of `k`. You can stay in Collect mode for at *most k* consecutive positions. 
    If your Heat reaches `k` at position `i`, you are *forced* to switch to Skip mode for position `i+1` (paying the switch cost `s`).

    Find the *maximum net profit* (total gain minus total switching cost) modulo `10^9+7`.

    *Input Format*

        The first line contains an integer, `n`, denoting the size of the array.
        The second line contains an integer, `k`, denoting the constant k.
        The third line contains an integer, `s`, denoting the cost to switch between modes.
        The fourth line contains N space-separated integers, where the ith integer represents `a[i]`

*Constraints*

`1 <= n <= 10^5`
`1 <= k <= 10^2`
*/

/*
    You are given an array a[1..N].
    You must Select a subsequence (maintaining order). Items are collected in order. 
    The K-th, 2K-th, 3K-th,... collected item is a 'trigger': the next item collected after a trigger earns double its value. 
    Maximise total earnings.

    Find the maximum total earnings.

    Input Format

        The first line contains an integer, N, denoting the number of items.
        The second line contains an integer, K, denoting the trigger period (every K-th collection triggers a double).
        The next line contains N space-separated integers representing the array a.

Constraints

1 <= N <= 10^4
1 <= K <= N
1 <= a[i] <= 10^2
*/

/*
    You have a string of brackets (each character '(' or ')') with associated costs. Inserting a '(' at any position costs a; inserting a ')' 
    at any position costs b. Find the minimum total insertion cost modulo 10^9+7 to make the string a valid bracket sequence.

        Input Format
            The first line contains a string, s, denoting the input bracket string.
            The second line contains an integer, a, denoting the cost to insert one '('.
            The third line contains an integer, b, denoting the cost to insert one ')'.

        Constraints
            1 <= |s| <= 10^5
            1 <= a <= 10^6
            1 <= b <= 10^6
*/

/*

    You are given an array a[1..n].
    A contiguous subarray is said to have a **majority element** if there exists an element that appears 
    **strictly more than half** of the subarray's length.

    Your task is to:
        1. Determine the **minimum possible length L** of any subarray that contains a majority element.
        2. Count how many contiguous subarrays of length L satisfy this condition.

    Find the **total count** of such subarrays. If no such subarray exists, return -1.

    **Input Format**

    The first line contains a integer, n, denoting the size of the array.
    The next line contains n space-separated integers a[i].

    Constraints
        1 <= n <= 10^5
        1 <= a[i] <= 10^9
*/

/*
    You are at an ice cream shop that has N different ice cream bars. Each ice cream bar i (from 1 to N) has a cost denoted by c[i]. 
    You have a total of C coins to spend.

    To ensure the ice cream bars you buy are of similar quality, the shop has a special rule: for any two ice cream bars you choose to 
    purchase, the absolute difference between their prices must not exceed D. That is, if you choose bar i and bar j, 
    the condition |c[i] - c[j]| <= D must be satisfied.

    Find the maximum number of ice cream bars you can buy such that the total cost does not exceed C and all chosen bars    
    satisfy the price difference constraint.

    Input Format

    The first line contains a integer, N, denoting the number of available ice cream bars.
*/

/*
        You are given an array A of N positive integers.
        Your task is to choose two distinct indices i and j (where i ≠ j) from the array such that the value of 
        A[i] * A[j] * (i - j) is maximized. Find the maximum possible value.

        Input Format
        The first line contains a integer, N, denoting the number of elements in the array.
        Each line i of the N subsequent lines (where 0 <= i < N) contains an integer, A[i].

Constraints
1 <= N <= 10^5
1 <= A[i] <= 1000

Sample Test Cases

Case 1
Input
3
10
1
100

Output
2000

Explanation:
*/

class Solution{
    int negInf=-1e9, mod=1e9+7;
    int slidingWindowHelper(int k,vint &arr,int n){
        int majority=k/2, count=0;
        unordered_map<int,int> freqMap;
        for(int i=0;i<n-k+1;i++){
            if(i>=k){
                freqMap[arr[i-k]]--;
                if(!freqMap[arr[i-k]])
                    freqMap.erase(arr[i-k]);
            }
            freqMap[arr[i]]++;
            if(i+1>=k){
                int maxF=0;
                for(auto &p: freqMap)
                    maxF=max(maxF,p.second);
                if(maxF>majority) count++;
            }
        }
        return count;
    }
        public:
    int findPairs(vint arr,int T){
        int n=arr.size(), count=0;
        unordered_map<int,int> freqMap;
        for(int i=0;i<n;i++){
            int x=((arr[i])%T+T)%T;
            int y=(T-x)%T;
            if(freqMap.count(y)){
                count++;
                freqMap[y]--;
                if(!freqMap[y])
                    freqMap.erase(y);
            }
            else freqMap[x]++;
        }
        return count;
    }
    int findMaxCost(vvint matrix){
        int n=matrix.size(), m=matrix[0].size();
        vvint dp(n,vint(m,negInf));
        dp[n-1][m-1]=matrix[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int goDown=negInf, goRight=negInf;
                if(i!=n-1) goDown=matrix[i][j]+dp[i+1][j];
                if(j!=m-1 && matrix[i][j]<matrix[i][j+1])
                    goRight=matrix[i][j]+dp[i][j+1];
                dp[i][j]=max(goDown,goRight);
            }
        }
        return (dp[0][0]<=negInf? -1: dp[0][0]);
    }
    long long findMaxProfit(vint arr,int k,int s){
        int n=arr.size();
        vvvll dp(n+1,vvll(k+1,vll(2,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                for(int m=0;m<2;m++){
                    if(i==n-1){
                        dp[i][j][m]=(m==1? arr[i]:0);
                        continue;
                    }
                    long long skip=negInf, take=negInf;
                    if(m){
                        long long takeAndKeep=negInf;
                        if(j+1!=k) takeAndKeep=arr[i]+dp[i+1][j+1][1];
                        long long takeAndSwitch=arr[i]-s+dp[i+1][0][0];
                        take=max(takeAndKeep,takeAndSwitch);
                    }
                    else{
                        long long skipAndKeep=dp[i+1][0][0];
                        long long skipAndSwitch=-s+dp[i+1][0][1];
                        skip=max(skipAndKeep,skipAndSwitch);
                    }
                    dp[i][j][m]=max(skip,take);
                }
            }
        }
        long long mod = 1e9 + 7;
        return (dp[0][0][1]%mod+mod)%mod;
    }
    long long findMaxEarnings(vint arr,int k){
        int n=arr.size();
        vll prev(k+1,0);
        for(int i=n-1;i>=0;i--){
            vll curr(k+1,0);
            for(int j=0;j<=k;j++){
                long long skip=prev[j];
                int m=(j && j%k==0? 2:1);
                long long take=1LL*m*arr[i]+prev[j%k+1];
                curr[j]=max(skip,take);
            }
            prev=curr;
        }
        return prev[0];
    }
    int findMinCost(string str,int a,int b){
        stack<char> st;
        for(const char &bracket: str){
            if(bracket==')' && !st.empty() && st.top()=='('){
                st.pop();
                continue;
            }
            st.push(bracket);
        }
        long long total=0;
        while(!st.empty()){
            int cost=0;
            if(st.top()=='(') cost=b;
            else cost=a;
            total=(total+cost)%mod;
            st.pop();
        }
        return total;
    }
    int findMinLengthSubarraysWithMajorityElement(vint arr){
        int n=arr.size();
        int majorityWindowsOfSize2=slidingWindowHelper(2,arr,n);
        if(majorityWindowsOfSize2) return majorityWindowsOfSize2;
        int majorityWindowsOfSize3=slidingWindowHelper(3,arr,n);
        if(majorityWindowsOfSize3) return majorityWindowsOfSize3;
        return -1;
    }
    int findMaxNumberOfIcecreams(vint arr,int D,int B){
        sort(arr.begin(),arr.end());
        int left=0, right=0, n=arr.size(), maxi=0, total=0;
        while(right<n){
            int newIcecreamPrice=arr[right];
            total+=newIcecreamPrice;
            while(left<=right && (newIcecreamPrice-arr[left]>D || total>B)){
                total-=arr[left];
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
    long long findMaxPossibleValue(vint arr){
        int maxi=*max_element(arr.begin(),arr.end()), n=arr.size();
        long long maxAns=0;
        vint firstPosArr(maxi+1,-1), lastPosArr(maxi+1,-1);
        for(int i=0;i<n;i++){
            int idx=arr[i];
            if(firstPosArr[idx]==-1)
                firstPosArr[idx]=i;
            lastPosArr[idx]=i;
        }
        for(int arrJ=1;arrJ<=maxi;arrJ++){
            if(firstPosArr[arrJ]==-1) continue;
            for(int arrI=1;arrI<=maxi;arrI++){
                if(lastPosArr[arrI]==-1) continue;
                int i=lastPosArr[arrI], j=firstPosArr[arrJ];
                if(i>j) maxAns=max(maxAns,1LL*arrI*arrJ*(i-j));
            }
        }
        return maxAns;
    }
};

int main(){
    Solution s;
    cout<<s.findPairs({2,4,6,8},2)<<endl;
    cout<<s.findMaxProfit({20,30,40,50},2,10)<<endl;
    cout<<s.findMaxProfit({10,10,10},1,5)<<endl;
    cout<<s.findMaxEarnings({10,20,30},1)<<endl;
    cout<<s.findMaxEarnings({1,10,100,10},2)<<endl;
    cout<<s.findMaxEarnings({10,1,10,100},2)<<endl;

    cout<<s.findMinCost(")(",2,3)<<endl;
    cout<<s.findMinCost("(((",10,5)<<endl;
    cout<<s.findMinLengthSubarraysWithMajorityElement({9,8,3,1,5,3,3,7,3,6})<<endl;
    cout<<s.findMaxPossibleValue({10,1,100})<<endl;
return 0;
}