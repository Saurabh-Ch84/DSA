#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // optimal
    class SegmentTree{
        int n, sizeOfTree;
        vector<int> sgt;
        void updateQuery(int idx,int low,int high,int i){
            if(low==high){
                sgt[idx]++;
                return ;
            }
            int mid=low+(high-low)/2;
            if(i<=mid) updateQuery(2*idx+1,low,mid,i);
            else updateQuery(2*idx+2,mid+1,high,i);
            sgt[idx]=sgt[2*idx+1]+sgt[2*idx+2];
        }
        int queryTree(int idx,int low,int high,int l,int r){
            if(low>r || high<l) return 0;
            if(low>=l && high<=r) return sgt[idx];
            int mid=low+(high-low)/2;
            int leftQuery=queryTree(2*idx+1,low,mid,l,r);
            int rightQuery=queryTree(2*idx+2,mid+1,high,l,r);
            return leftQuery+rightQuery;
        }
            public:
        SegmentTree(int n):n(n){
            sgt.resize(4*n+1,0);
            sizeOfTree=0;
        }
        void insert(int val){
            updateQuery(0,0,n-1,val);
            sizeOfTree++;
        }
        int greaterCount(int num){
            return queryTree(0,0,n-1,num+1,n);
        }
        int size(){
            return sizeOfTree;
        }
    };
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> hashMap;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int compressedValue=0;
        for(int i=0;i<n;i++){
            if(!hashMap.count(temp[i]))
                hashMap[temp[i]]=compressedValue++;
        }
        vector<int> arr1, arr2;
        SegmentTree sgt1(compressedValue+1), sgt2(compressedValue+1);
        arr1.push_back(nums[0]);
        sgt1.insert(hashMap[nums[0]]);
        arr2.push_back(nums[1]);
        sgt2.insert(hashMap[nums[1]]);

        for(int i=2;i<n;i++){
            int count1=sgt1.greaterCount(hashMap[nums[i]]);
            int count2=sgt2.greaterCount(hashMap[nums[i]]);
            int n1=sgt1.size(), n2=sgt2.size();
            if(count2>count1 || (count2==count1 && n2<n1)){
                arr2.push_back(nums[i]);
                sgt2.insert(hashMap[nums[i]]);
            }
            else{
                arr1.push_back(nums[i]);
                sgt1.insert(hashMap[nums[i]]);
            }
        }
        vector<int> resultArr;
        resultArr.insert(resultArr.end(),arr1.begin(),arr1.end());
        resultArr.insert(resultArr.end(),arr2.begin(),arr2.end());
        return resultArr;
    }
};

class Solution2{
    // brute-force.
    int greaterCount(multiset<int> &mSet,int x){
        return distance(mSet.upper_bound(x),mSet.end());
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1, arr2;
        multiset<int> mSet1, mSet2;
        arr1.push_back(nums[0]);
        mSet1.insert(nums[0]);
        arr2.push_back(nums[1]);
        mSet2.insert(nums[1]);

        for(int i=2;i<n;i++){
            int count1=greaterCount(mSet1,nums[i]);
            int count2=greaterCount(mSet2,nums[i]);
            int n1=mSet1.size(), n2=mSet2.size();
            if(count2>count1 || (count2==count1 && n2<n1)){
                arr2.push_back(nums[i]);
                mSet2.insert(nums[i]);
            }
            else{
                arr1.push_back(nums[i]);
                mSet1.insert(nums[i]);
            }
        }
        vector<int> resultArr;
        resultArr.insert(resultArr.end(),arr1.begin(),arr1.end());
        resultArr.insert(resultArr.end(),arr2.begin(),arr2.end());
        return resultArr;
    }
};



int main(){

return 0;
}