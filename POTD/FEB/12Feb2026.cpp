#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi=vector<int>;

class Solution {
    bool isBalanced(vi &arr,int maxF){
        for(int &f: arr)
            if(f && f!=maxF) return false;
        return true;
    }
public:
    int longestBalanced(string s) {
        int n=s.size(), maxi=1;
        for(int i=0;i<n;i++){
            vi arr(26,0);
            int maxF=0;
            for(int j=i;j<n;j++){
                arr[s[j]-'a']++;
                maxF=max(maxF,arr[s[j]-'a']);
                if(arr[s[j]-'a']==maxF && j-i+1>maxi && isBalanced(arr,maxF))
                    maxi=j-i+1;
            }
        }
        return maxi;
    }
};

using vi=vector<int>;
class Solution {
    bool check(int mid,int k,int w,int n,vi &arr){
        vi diffArr(n+1,0);
        int currWater=0;
        for(int i=0;i<n;i++){
            currWater+=diffArr[i];
            int val=arr[i]+currWater;
            if(val<mid){
                int days=mid-val;
                if(days>k) return false;
                diffArr[i]+=days;
                if(i+w<=n) diffArr[i+w]-=days;
                currWater+=days;
                k-=days;
            }
        }
        return true;
    }
  public:
    int maxMinHeight(vi &arr, int k, int w) {
        // code here
        int n=arr.size(), low=*min_element(arr.begin(),arr.end());
        int high=low+k, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool resp=check(mid,k,w,n,arr);
            if(resp){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};


int main(){

return 0;
}