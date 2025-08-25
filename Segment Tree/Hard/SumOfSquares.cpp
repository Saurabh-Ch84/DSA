#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given an Array arr[] of positive integers of size n. We are required to perform following 3 queries on given array -

1) Given L and R, we have to find the sum of squares of all element lying in range [L,R]
2) Given L, R and X, we have to set all element lying in range [L,R] to X
3) Given L, R and X, we have to increment the value of all element lying in range [L,R] by X

Input Format : First line contains the number of test cases T
Next line contains two positive integers - N (Size of Array ) and Q (Number of queries to be asked).
The next line contains N integers of array

Each of the next Q lines contains the Q queries to be asked. Each line starts with a number, which indicates the  type of 
query followed by required input arguments.
Input format for all 3 queries will look like -

0 L R X : Set all numbers in Range [L, R] to "X"

1 L R X : ADD "X" to all numbers in Range [L, R]

2 L R :  Return the sum of the squares of the numbers in Range {L, R]

Output Format : For each test case, output "Case <TestCaseNo>:” in first line and then output the sum of squares for each 
queries of type 2 in separate lines.

*/

struct Node{
    long long sumSq;
    long long sum;
};

class SegmentTree{
        private:
    int n;
    vector<Node> segTree;
    vector<long long> lazyTreeAddBy;
    vector<long long> lazyTreeSetTo;
    vector<bool> toSet;

    void buildTree(int low,int high,int idx,const vector<int> &nums){
        if(low==high){
            segTree[idx].sumSq=nums[low]*nums[low];
            segTree[idx].sum=nums[low];
            return ;
        }
        int mid=low+(high-low)/2;
        buildTree(low,mid,2*idx+1,nums);
        buildTree(mid+1,high,2*idx+2,nums);
        segTree[idx].sumSq=segTree[2*idx+1].sumSq+segTree[2*idx+2].sumSq;
        segTree[idx].sum=segTree[2*idx+1].sum+segTree[2*idx+2].sum;
    }

    void applySet(int idx,int count,long long val){
        segTree[idx].sumSq=count*val*val;
        segTree[idx].sum=count*val;
        lazyTreeSetTo[idx]=val;
        toSet[idx]=true;
        lazyTreeAddBy[idx]=0;
    }

    void applyAdd(int idx,int count,long long val){
        segTree[idx].sumSq+=count*val*val+2*val*segTree[idx].sum;
        segTree[idx].sum+=val*count;
        if(toSet[idx]) lazyTreeSetTo[idx]+=val;
        else lazyTreeAddBy[idx]+=val;
    }

    void propagate(int low,int high,int idx){
        int count=high-low+1;
        if(toSet[idx]){
            if(low!=high){
                applySet(2*idx+1, (count+1)/2, lazyTreeSetTo[idx]);
                applySet(2*idx+2, count/2, lazyTreeSetTo[idx]);
            }
            toSet[idx]=false;
            lazyTreeSetTo[idx]=0;
        }
        if(lazyTreeAddBy[idx]!=0){
            if(low!=high){
                applyAdd(2*idx+1,(count+1)/2,lazyTreeAddBy[idx]);
                applyAdd(2*idx+2,count/2,lazyTreeAddBy[idx]);
            }
            lazyTreeAddBy[idx]=0;
        }
    }

    void updateSet(int low,int high,int idx,int val,int left,int right){
        propagate(low,high,idx);
        if(low>right || high<left) return ;
        if(low>=left && high<=right){
            applySet(idx,high-low+1,val);
            return ;
        }
        int mid=low+(high-low)/2;
        updateSet(low,mid,2*idx+1,val,left,right);
        updateSet(mid+1,high,2*idx+2,val,left,right);
        segTree[idx].sumSq=segTree[2*idx+1].sumSq+segTree[2*idx+2].sumSq;
        segTree[idx].sum=segTree[2*idx+1].sum+segTree[2*idx+2].sum;
    }

    void updateAdd(int low,int high,int idx,int val,int left,int right){
        propagate(low,high,idx);
        if(low>right || high<left) return ;
        if(low>=left && high<=right){
            applyAdd(idx,high-low+1,val);
            return ;
        }
        int mid=low+(high-low)/2;
        updateAdd(low,mid,2*idx+1,val,left,right);
        updateAdd(mid+1,high,2*idx+2,val,left,right);
        segTree[idx].sumSq=segTree[2*idx+1].sumSq+segTree[2*idx+2].sumSq;
        segTree[idx].sum=segTree[2*idx+1].sum+segTree[2*idx+2].sum;
    }

    long long queryTree(int low,int high,int idx,int left,int right){
        propagate(low,high,idx);
        if(low>right || high<left) return 0LL;
        if(low>=left && high<=right) return segTree[idx].sumSq;
        int mid=low+(high-low)/2;
        long long leftAns=queryTree(low,mid,2*idx+1,left,right);
        long long rightAns=queryTree(mid+1,high,2*idx+2,left,right);
        return leftAns+rightAns;
    }
        public:
    SegmentTree(vector<int> &nums){
        int n=nums.size();
        segTree.resize(4*n,{0,0});
        lazyTreeAddBy.resize(4*n,0);
        lazyTreeSetTo.resize(4*n,0);
        toSet.resize(4*n,false);
        buildTree(0,n-1,0,nums);
    }

    int query(int lb,int ub){
        return queryTree(0,n-1,0,lb,ub);
    }

    void updateAddUtil(int lb,int ub,int x){ //add 'x' type
        updateAdd(0,n-1,0,x,lb,ub);
    }

    void updateSetUtil(int lb,int ub,int x){ //set 'x' type
        updateSet(0,n-1,0,x,lb,ub);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    for(int tc=1; tc <= testCases; tc++){
        int n, queries;
        cin >> n >> queries;
        vector<int> nums(n);
        for(int i=0; i<n; i++) 
            cin >> nums[i];

        SegmentTree sgt(nums);
        cout << "Case " << tc << ":\n";

        for(int i=0; i<queries; i++){
            int queryType;
            cin >> queryType;
            if(queryType == 0){
                int L, R, X;
                cin >> L >> R >> X;
                sgt.updateSetUtil(L, R, X);
            }
            else if(queryType == 1){
                int L, R, X;
                cin >> L >> R >> X;
                sgt.updateAddUtil(L, R, X);
            }
            else{
                int L, R;
                cin >> L >> R;
                cout << sgt.query(L, R) << "\n";
            }   
        }
    }
    return 0;
}
