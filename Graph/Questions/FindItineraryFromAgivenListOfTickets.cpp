#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given a list of tickets, find the itinerary in order using the given list.
    Note: It may be assumed that the input list of tickets is not cyclic and there is one ticket from 
    every city except the final destination.
*/

class Solution1{
    void DFS(string u,vector<string> &ans,unordered_map<string,vector<string>> &adjMap){
        ans.push_back(u);
        for(string &v:adjMap[u])
            DFS(v,ans,adjMap);
    }
        public:
    vector<string> itineraryConstruction(vector<vector<string>> &travel){
        unordered_map<string,vector<string>> adjMap;
        unordered_map<string,int> indegMap;
        
        for(vector<string> &t:travel){
            string u=t[0],v=t[1];
            indegMap[u];
            indegMap[v]++;
            adjMap[u].push_back(v);
        }
        vector<string> ans;
        for(auto &p:indegMap){
            string u=p.first;
            int indeg=p.second;
            if(indeg==0) DFS(u,ans,adjMap);
        }
        return ans;
    }
};

void print(vector<string> list){
    for(string &str:list)
        cout<<str<<" ";
    cout<<endl;
}

int main(){
    vector<vector<string>> travel1={{"Chennai","Bangalore"},{"Bombay","Delhi"},{"Delhi","Goa"},{"Bangalore","Delhi"}};
    vector<vector<string>> travel2 = {
        {"Chennai", "Bangalore"},
        {"Bombay", "Delhi"},
        {"Goa", "Chennai"},
        {"Delhi", "Goa"}
    };
    Solution1 s;
    print(s.itineraryConstruction(travel1));
return 0;
}