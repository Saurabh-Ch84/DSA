#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*
Given a size n in which initially all elements are 0. The task is to perform multiple queries of following two types. 
The queries can appear in any order. 
 
1. toggle(start, end) : Toggle (0 into 1 or 1 into 0) the values from range 'start' to 'end'.
2. count(start, end) : Count the number of 1's within given range from 'start' to 'end'.

Input : n = 5       // we have n = 5 blocks
        toggle 1 2  // change 1 into 0 or 0 into 1
        toggle 2 4
        Count  2 3  // count all 1's within the range
        toggle 2 4
        Count  1 4  // count all 1's within the range
Output : Total number of 1's in range 2 to 3 is = 1
         Total number of 1's in range 1 to 4 is = 2
*/


class SegmentTree{
	private:
	int n;
	vector<int> segTree;
	vector<bool> lazyTree;

	void propagate(int idx,int low,int high){
		if(lazyTree[idx]==false) return ;
		int count=high-low+1;
		segTree[idx]=count-segTree[idx];
		if(low!=high){
			lazyTree[2*idx+1]=!lazyTree[2*idx+1];
			lazyTree[2*idx+2]=!lazyTree[2*idx+2];
		}
		lazyTree[idx]=false;
	}

	void updateTree(int low,int high,int idx,int left,int right){
		propagate(idx,low,high);
		if(low>right || high<left) return ;
		if(low>=left && high<=right){
			lazyTree[idx]=!lazyTree[idx];
			propagate(idx,low,high);
			return ;
		}
		int mid=low+(high-low)/2;
		updateTree(low,mid,2*idx+1,left,right);
		updateTree(mid+1,high,2*idx+2,left,right);
		segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
	}

	int queryTree(int low,int high,int idx,int left,int right){
		propagate(idx,low,high);
		if(low>right || high<left) return 0;
		if(low>=left && high<=right){
			return segTree[idx];
		}
		int mid=low+(high-low)/2;
		int leftAns=queryTree(low,mid,2*idx+1,left,right);
		int rightAns=queryTree(mid+1,high,2*idx+2,left,right);
		return leftAns+rightAns;
	}
	public:
	SegmentTree(int n){
		this->n=n;
		segTree.resize(4*n,0);
		lazyTree.resize(4*n,false);
	}

	void update(int lb,int ub){
		updateTree(0,n-1,0,lb,ub);
	}

	int query(int lb,int ub){
		return queryTree(0,n-1,0,lb,ub);
	}
};  


int main(){
    int n;
    cin>>n;
    SegmentTree sgt(n);
    int queries;
    cin>>queries;
    while(queries--)
    {
        int queryType;
        cin>>queryType;
        if(queryType==0){
            int L,R;
            cin>>L>>R;
            sgt.update(L-1,R-1); //1-based input
        }
        else{
            int L,R;
            cin>>L>>R;
            cout<<"Count: "<<sgt.query(L-1,R-1)<<endl; //1-based input
        }
    }
return 0;
}