#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;

class SegmentTree{
    int n;
    vector<int> segTreeMax,segTreeMin;
    
    void buildTree(vector<int>& arr,int low,int high,int idx){
        if(low==high){
            segTreeMax[idx]=arr[low];
            segTreeMin[idx]=arr[low];
            return ;
        }
        int mid=low+(high-low)/2;
        buildTree(arr,low,mid,2*idx+1);
        buildTree(arr,mid+1,high,2*idx+2);
        segTreeMax[idx]=max(segTreeMax[2*idx+1],segTreeMax[2*idx+2]);
        segTreeMin[idx]=min(segTreeMin[2*idx+1],segTreeMin[2*idx+2]);
    }
    
    int queryTreeMax(int low,int high,int idx,int left,int right){
        if(left>high || right<low) return INT_MIN;
        if(left<=low && right>=high) return segTreeMax[idx];
        int mid=low+(high-low)/2;
        int leftAns=queryTreeMax(low,mid,2*idx+1,left,right);
        int rightAns=queryTreeMax(mid+1,high,2*idx+2,left,right);
        return max(leftAns,rightAns);
    }
    
    int queryTreeMin(int low,int high,int idx,int left,int right){
        if(left>high || right<low) return INT_MAX;
        if(left<=low && right>=high) return segTreeMin[idx];
        int mid=low+(high-low)/2;
        int leftAns=queryTreeMin(low,mid,2*idx+1,left,right);
        int rightAns=queryTreeMin(mid+1,high,2*idx+2,left,right);
        return min(leftAns,rightAns);
    }
    
        public:
    SegmentTree(vector<int>& arr){
        n=arr.size();
        segTreeMax.resize(4*n+1);
        segTreeMin.resize(4*n+1);
        buildTree(arr,0,n-1,0);
    }
    
    int query(int left,int right,bool max){
        return (max)? queryTreeMax(0,n-1,0,left,right) : queryTreeMin(0,n-1,0,left,right);
    }
};

class Solution1 {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int start=0,maxLen=1,mini=arr[0],maxi=arr[0];
        int n=arr.size(),left=0,right=1;
        SegmentTree sgt(arr);
        
        while(right<n){
            int num=arr[right];
            maxi=max(maxi,num);
            mini=min(mini,num);
            while((abs(maxi-num)>x || abs(num-mini)>x) && left<=right){
                left++;
                maxi=sgt.query(left,right,true);
                mini=sgt.query(left,right,false);
            }
            int currLen=right-left+1;
            if(currLen>maxLen){
                start=left;
                maxLen=currLen;
            }
            right++;
        }
        
        vector<int> result;
        for(int i=0;i<maxLen;i++){
            result.push_back(arr[start+i]);
        }
        return result;
    }
};

void print(vector<int> arr){
    for(int &e:arr){
        cout<<e<<" ";
    }
    cout<<endl;
}

class Solution2 {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        priority_queue<pii,vector<pii>> maxHeap;
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        maxHeap.push({arr[0],0});
        minHeap.push({arr[0],0});
        
        int maxLen=1,start=0,n=arr.size();
        int left=0,right=1;
        
        while(right<n){
            int num=arr[right];
            maxHeap.push({num,right});
            minHeap.push({num,right});
            
            while(maxHeap.top().first-minHeap.top().first>x){
                left=min(maxHeap.top().second,minHeap.top().second)+1;
                while(minHeap.top().second<left)
                    minHeap.pop();
                while(maxHeap.top().second<left)
                    maxHeap.pop();
            }
            
            if(right-left+1 > maxLen){
                start=left;
                maxLen=right-left+1;
            }
            
            right++;
        }
        
        vector<int> res;
        for(int i=0;i<maxLen;i++)
            res.push_back(arr[start+i]);
        
        return res;
    }
};

class Solution3 {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        multiset<int> hashSet;
        int left=0,right=1,n=arr.size();
        int start=0,maxLen=1;
        hashSet.insert(arr[left]);
        
        while(right<n){
            hashSet.insert(arr[right]);
            while(*hashSet.rbegin()-*hashSet.begin()>x){
                hashSet.erase(hashSet.find(arr[left]));
                left++;
            }
            if(right-left+1>maxLen){
                start=left;
                maxLen=right-left+1;
            }
            right++;
        }
        vector<int> res;
        for(int i=0;i<maxLen;i++)
            res.push_back(arr[i+start]);
        return res;
    }
};

int main(){
    Solution1 s;
    vector<int> arr={9,8,3,1,5,3,3,7,3,6};
    int x=5;
    print(s.longestSubarray(arr,x));
return 0;
}