#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    class DSU{
        vector<int> parent;
            public:
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }

        void unionMerge(int u,int v){
            int U=findUPar(u);
            int V=findUPar(v);
            parent[V]=U;
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int persons=accounts.size();
        DSU ds(persons);
        unordered_map<string,int> emailToIndex;

        for(int person=0;person<persons;person++){
            for(int eID=1;eID<accounts[person].size();eID++){
                string email=accounts[person][eID];
                if(emailToIndex.find(email)==emailToIndex.end()) emailToIndex[email]=person;
                else ds.unionMerge(emailToIndex[email],person);
            }
        }
        
        vector<vector<string>> mergeResult(persons);
        for(const auto &itr:emailToIndex){
            string email=itr.first;
            int person=itr.second;
            int actualPerson=ds.findUPar(person);
            mergeResult[actualPerson].push_back(email);
        }

        vector<vector<string>> result;
        for(int person=0;person<persons;person++){
            if(!mergeResult[person].size()) continue;
            string name=accounts[person][0];
            vector<string> temp;
            temp.push_back(name);
            for(const string& email:mergeResult[person]) temp.push_back(email);
            sort(temp.begin()+1,temp.end());
            result.push_back(temp);
        }
        return result;
    }
};

int main(){

return 0;
}