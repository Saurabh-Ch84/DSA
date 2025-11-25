#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution1 {
    class DSU{
        vector<int> parent,size;
        int find(int node){
            if(node==parent[node])
                return node;
            return parent[node]=find(parent[node]);
        }
            public:
        DSU(int n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        void unionBySize(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return ;
            else if(U<V){
                size[U]+=size[V];
                parent[V]=U;
            }
            else{
                size[V]+=size[U];
                parent[U]=V;
            }
        }

        int sizeOfLCC(){
            int maxi=0;
            for(int i=0;i<parent.size();i++){
                if(i==parent[i]){
                    maxi=max(maxi,size[i]);
                }
            }
            return maxi;
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int &num: nums)
            hashSet.insert(num);
        
        int n=hashSet.size();
        DSU ds(n);

        unordered_map<int,int> hashMap;
        int node=0;
        for(const int& num: hashSet)
            hashMap[num]=node++;

        for(const int &num: hashSet){
            if(hashSet.count(num+1))
                ds.unionBySize(hashMap[num],hashMap[num+1]);
        }
        return ds.sizeOfLCC();
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(),nums.end());
        int sizeOfLCC=0;
        for(const int &num: nums){
            if(!hashSet.count(num-1)){
                int sz=1,n=num+1;
                while(hashSet.count(n)){
                    hashSet.erase(n);
                    sz++;
                    n++;
                }
                sizeOfLCC=max(sizeOfLCC,sz);
            }
        }
        return sizeOfLCC;
    }
};

int main(){

return 0;
}