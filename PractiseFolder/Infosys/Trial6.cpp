#include<bits/stdc++.h>
using namespace std;
using vint=vector<int>;
using vvint=vector<vint>;

/*
    A staircase contains N steps numbered from 1 to N.
    You start from step 1 and want to reach step N.

    From any step, you may jump only to the next Fibonacci step ahead. That is, if you are currently on 
    step i, you may move to:

    • i + 1
    • i + 2
    • i + 3
    • i + 5
    • i + 8
    ...
    where the jump length must be a Fibonacci number and the destination must not exceed N.

    The cost of making a jump of length k is:
    Cost = A + B × k

    Find the minimum total cost required to reach step N.
    where:
    • A = fixed cost per jump
    • B = cost per step jumped
    • k = jump length (a Fibonacci number)

    Input Format N A B
*/

/*
    You are given an integer array a of size n and two integers D and M.
    Your task is to count the number of unordered pairs (i, j) such that:

    • 0 ≤ i < j < n
    • (a[i] + a[j]) % D == 0
    • |a[i] - a[j]| % M == 0

    Return the total number of pairs satisfying both conditions.

    Input Format
        • The first line contains three integers n, D, and M.
        • The second line contains n space-separated integers representing the array a.

    Output Format
        • Print a single integer representing the number of valid unordered pairs.

    Constraints:
    • 1 ≤ n ≤ 10^5
    • 1 ≤ D, M ≤ 10^9
    • -10^9 ≤ a[i] ≤ 10^9
*/

/*
    Problem Statement

    There are N posts located along a highway. The positions of the posts are given in a sorted integer array 
    posts[], where posts[i] represents the position of the i-th post.
    Your task is to install amplifiers such that every post is covered.

    There are two types of amplifiers available:
    1. Normal Amplifier

        • Can be installed at any position on the highway.
        • If placed at position x, it covers all posts in the interval:
            [x - r, x + r]
        • There is an unlimited supply of normal amplifiers.

    2. Super Amplifier

        • Can also be installed at any position on the highway.
        • If placed at position x, it covers all posts in the interval:
            [x - 2r, x + 2r]
        • Only K super amplifiers are available.

        An amplifier does not have to be placed at the position of a post. 
        It may be installed anywhere on the highway to maximize the number of posts covered.

        Determine the minimum total number of amplifiers (normal and super combined) required to cover all the posts.

    Function Signature
        int minimumAmplifiers(vector<int>& posts, int r, int k);

    Input Format
        • The first line contains an integer N, the number of posts.
        • The second line contains N sorted space-separated integers representing the positions of the posts.

    Output Format
        • Print a single integer representing the minimum total number of amplifiers required to cover all the posts.

    Constraints
    • 1 ≤ N ≤ 10^5
    • 1 ≤ posts[i] ≤ 10^9
    • posts[] is sorted in non-decreasing order
    • 1 ≤ r ≤ 10^9
    • 0 ≤ K ≤ N
*/

/*
    Given an integer array nums containing n integers, find the beauty of every subarray of size k.
    The beauty of a subarray is defined as:
        • The x-th smallest integer in the subarray if it is negative.
        • Otherwise, the beauty is 0 if there are fewer than x negative integers in the subarray.

    Return an integer array of size n - k + 1, where each element represents the beauty of the 
    corresponding subarray in the order they appear.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Input
    • An integer array nums
    • An integer k representing the size of each subarray
    • An integer x

    Output
    Return an integer array containing the beauty of each subarray of size k.

    Constraints
    1 <= n <= 1e5
    1 <= k <= n
    1 <= x <= k 
    -50 <= nums[i] <= 50 

    Example 1
        Input
        nums = [1, -1, -3, -2, 3]
        k = 3
        x = 2

        Explanation
        Subarrays of size 3:
        1. [1, -1, -3]
            • Sorted: [-3, -1, 1]
            • 2nd smallest = -1
            • Beauty = -1

        2. [-1, -3, -2]
            • Sorted: [-3, -2, -1]
            • 2nd smallest = -2
            • Beauty = -2

        3. [-3, -2, 3]
            • Sorted: [-3, -2, 3]
            • 2nd smallest = -2
            • Beauty = -2

        Output [-1, -2, -2]
*/

/*
    Problem Statement
        A company is organizing a conference in two cities, City A and City B. There are 2N employees, and 
        exactly N employees must be assigned to each city.
    For each employee i:
        • The cost of sending the employee directly to City A is A[i].
        • To travel to City B, the employee must first stop at a transit hub. 
            The total travel cost to City B is: min(A[i], B[i]) + B[i]
    where:
        • A[i] is the cost of traveling directly to City A.
        • B[i] is the cost of traveling from the transit hub to City B.

    Determine the minimum total travel cost while ensuring that exactly N employees are assigned to each city.

    Input Format
    • The first line contains an integer N.
    • The second line contains 2N space-separated integers representing array A.
    • The third line contains 2N space-separated integers representing array B.

    Output Format
    Print a single integer representing the minimum total travel cost.

    Constraints
    • 1 ≤ N ≤ 10^5
    • 1 ≤ A[i], B[i] ≤ 10^5
*/

/*
    You are given a string S.
    Split the string into the minimum number of contiguous substrings such that every substring is a palindrome.
    A palindrome is a string that reads the same forwards and backwards.
    Note:
    • Every character of the string must belong to exactly one substring.
    • Consider both odd-length and even-length palindromes while partitioning.
    Return the minimum number of palindromic substrings required to partition the entire string.
    
    Input Format
    • A string 
*/

/*
    A mobile phone uses the traditional keypad layout where multiple letters share the same numeric key. 
    Because of thumb fatigue, a user records only the sequence of key presses instead of the intended message.
    Given a string consisting of digits '2' to '9', determine the number of different messages that could 
    have produced the given sequence.

        Rules
    Keys 2, 3, 4, 5, 6, and 8 each represent 3 letters. Therefore, at most 3 consecutive presses of these keys 
    can correspond to a single character.

    Keys 7 and 9 each represent 4 letters. Therefore, at most 4 consecutive presses of these keys can 
    correspond to a single character.

    Consecutive identical digits may be grouped into valid key presses in different ways.
    Different groupings correspond to different possible messages.

    Return the total number of possible messages modulo 10^9 + 7.

    Constraints:
        1<=length(S)<=1e5
*/

class Solution{
    int inf=1e8, mod=1e9+7;
        public:
    int minimumCostToJump(int N,int A,int B){
        vint dp(N+1,inf);
        dp[N]=0;
        for(int i=N-1;i>0;i--){
            int a=1, b=2, j=i+a, mini=inf;
            while(j<=N){
                int cost=(A+B*a)+dp[j];
                mini=min(mini,cost);
                int c=a+b;
                a=b, b=c;
                j=i+a;
            }
            dp[i]=mini;
        }
        return dp[1];
    }
    long long countValidPairs(int n,int D,int M,vint arr){
        long long count=0;
        map<pair<int,int>,int> hashMap;
        for(int i=0;i<n;i++){
            int x=arr[i]%D, y=arr[i]%M;
            int x_=(D-x)%D, y_=(M+y)%M; 
            count+=hashMap[{x_,y_}];
            x=(D+x)%D, y=(M+y)%M;
            hashMap[{x,y}]++;
        }
        return count;
    }
    int minimumAmplifiers(vint posts,int r,int k){
        int n=posts.size(), count=0;
        long long coverage=0;
        for(int i=0;i<n;i++){
            if(coverage<posts[i]){
                if(k){
                    coverage=1LL*posts[i]+4*r;
                    k--;
                }
                else coverage=1LL*posts[i]+2*r;
                count++;
            }
        }
        return count;
    }
    vint beautyOfAllSubArrays(vint nums,int k,int x){
        int n=nums.size(), mini=*min_element(nums.begin(),nums.end());
        vint res(n-k+1,0);
        if(mini>=0) return res;
        int sz=-mini+1, negs=0;
        vint frequencyArr(sz,0);
        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]<0){
                int oldNum=nums[i-k]-mini;
                frequencyArr[oldNum]--;
                negs--;
            }
            if(nums[i]<0){
                int newNum=nums[i]-mini;
                frequencyArr[newNum]++;
                negs++;
            }
            if(i+1>=k && negs>=x){
                int xthSmallest=0, count=0;
                for(int j=0;j<sz;j++){
                    if(frequencyArr[j]){
                        count=count+min(x-count,frequencyArr[j]);
                        xthSmallest=mini+j;
                        if(count==x){
                            res[i+1-k]=xthSmallest;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
    long long minimumCostToAssignEmployees(vint A,vint B){
        int n=A.size()/2;
        vvint arr(2*n);
        for(int i=0;i<2*n;i++){
            int costOfCityA=A[i], costOfCityB=min(A[i],B[i])+B[i];
            int diff=costOfCityB-costOfCityA;
            arr[i]={diff,i};
        }
        long long cost=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<2*n;i++){
            int origIdx=arr[i][1];
            cost=cost+(i<n? min(A[origIdx],B[origIdx])+B[origIdx]:A[origIdx]);
        }
        return cost;
    }
    int minimumNumberOfPalindromicSubStrings(string s){
        int n=s.size();
        if(!n) return 0;
        vvint isPalindrome(n,vint(n,0));
        for(int i=0;i<n;i++)
            isPalindrome[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
            isPalindrome[i][i+1]=1;
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j] && isPalindrome[i+1][j-1])
                    isPalindrome[i][j]=1;
            }
        }
        vint dp(n+1,n+1);
        dp[n]=0, dp[n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(isPalindrome[i][j])
                    dp[i]=min(dp[i],1+dp[j+1]);
            }
        }
        return dp[0];
    }
    int numberOfPossibleMessages(string s){
        unordered_map<char,int> hashMap={{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'8',3},{'7',4},{'9',4}};
        int n=s.size();
        vint dp(n+1,-1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int segmentSize=hashMap[s[i]], k=0;
            long long ways=0;
            while(i+k<n && k<segmentSize && s[i+k]==s[i]){
                long long newWay=dp[i+k+1];
                ways=(ways+newWay)%mod;
                k++;
            }
            dp[i]=ways;
        }
        return dp[0];
    }
};

void print(vint arr){
    for(int &e: arr)
        cout<<e<<" ";
    cout<<"\n";
}

int main(){
    Solution s;
    cout<<s.minimumCostToJump(10,5,2)<<endl;
    cout<<s.countValidPairs(5,3,2,{1,2,5,4,7})<<endl;
    cout<<s.minimumAmplifiers({1,3,5,7,10},2,1)<<endl;
    cout<<s.minimumAmplifiers({1,2,8,10,15,18},2,0)<<endl;
    print(s.beautyOfAllSubArrays({1,-1,-3,-2,3},3,2));
    cout<<s.minimumCostToAssignEmployees({10,30,50,20},{20,10,40,30})<<endl;
    cout<<s.minimumNumberOfPalindromicSubStrings("nitin")<<endl;
    cout<<s.minimumNumberOfPalindromicSubStrings("geeks")<<endl;
    cout<<s.numberOfPossibleMessages("22233")<<endl;
return 0;
}