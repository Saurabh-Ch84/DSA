#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int lowerBound(vector<vector<int>>& arr,int target,int n){
        int low=0,high=n-1,idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid][0]>=target){
                idx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return idx;
    }

    int upperBound(vector<vector<int>>& arr,int target,int n){
        int low=0,high=n-1,idx=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid][0]>target){
                idx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return idx;
    }

    int cal(vector<vector<int>>& fruits,int leftPos,int rightPos,int n,vector<int> &prefix){
        int left=lowerBound(fruits,leftPos,n);
        int right=upperBound(fruits,rightPos,n)-1;
        int total=0;
        if(left<=right)
            total=prefix[right]-(left>0 ? prefix[left-1]:0);
        return total;
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++)
            prefix[i]=(i>0 ? prefix[i-1]:0 )+fruits[i][1];
        
        int maxi=0;
        for(int d=0;d<=k/2;d++){
            {
                //Go Left, then go right
                int leftPos=startPos-d,rem=k-d+(-d);
                int rightPos=startPos+rem;
                int total=cal(fruits,leftPos,rightPos,n,prefix);
                maxi=max(maxi,total);
            }
            {
                //Go Right, then go left
                int rightPos=startPos+d,rem=k-d+(-d);
                int leftPos=startPos-rem;
                int total=cal(fruits,leftPos,rightPos,n,prefix);
                maxi=max(maxi,total);
            }
        }
        return maxi;
    }
};

int main(){
    Solution s;

    vector<vector<int>> fruits={{1,7},{3,5},{6,3},{7,3},{9,5}};
    int startPos=5,k=3;
    cout<<s.maxTotalFruits(fruits,startPos,k);
return 0;
}