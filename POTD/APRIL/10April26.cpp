#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size(), mini=1e9;
        unordered_map<int,vint> hashMap;
        for(int i=0;i<n;i++){
            hashMap[nums[i]].push_back(i);
            int sz=hashMap[nums[i]].size();
            if(sz>2){
                vint &indices=hashMap[nums[i]];
                int k=indices[sz-1];
                int j=indices[sz-2];
                int i=indices[sz-3];
                mini=min(mini,abs(i-j)+abs(j-k)+abs(k-i));
            }
        }    
        return (mini==1e9? -1: mini);
    }
};

class Solution {
    using vint=vector<int>;
    void getNGE(vint &arr,vint &ngeIdx,int n){
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]) s.pop();
            if(!s.empty()) ngeIdx[i]=s.top();
            s.push(i);
        }
    }
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vint ngeIdx(n,-1);
        getNGE(arr,ngeIdx,n);
        
        int pse=1e9, pseIndx=-1;
        for(int i=0;i<n;i++){
            if(pse<arr[i] && arr[i]<arr[ngeIdx[i]])
                return {arr[pseIndx],arr[i],arr[ngeIdx[i]]};
            if(arr[i]<pse){
                pse=arr[i];
                pseIndx=i;
            }
        }
        return {};
    }
};

int main(){

return 0;
}