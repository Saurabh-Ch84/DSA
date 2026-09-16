#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    hierholzer's algo
*/

class Solution1 {
    void DFS(vector<string> &res,unordered_map<string,multiset<string>> &adjMap,string current){
        while(!adjMap[current].empty()){
            string neighbor=*adjMap[current].begin();
            adjMap[current].erase(adjMap[current].begin());
            DFS(res,adjMap,neighbor);
        }
        res.push_back(current);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adjMap;
        for(vector<string> &ticket:tickets){
            string u=ticket[0],v=ticket[1];
            adjMap[u].insert(v);
        }
        vector<string> res;
        DFS(res,adjMap,"JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};

void print(vector<string> list){
    for(string &str:list)
        cout<<str<<" ";
    cout<<endl;
}

class Solution2 {
    void DFS(vector<string> &res,unordered_map<string,vector<string>> &adjMap,string current){
        while(!adjMap[current].empty()){
            string neighbor=adjMap[current].back();
            adjMap[current].pop_back();
            DFS(res,adjMap,neighbor);
        }
        res.push_back(current);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adjMap;
        for(vector<string> &ticket:tickets){
            string u=ticket[0],v=ticket[1];
            adjMap[u].push_back(v);
        }
        for(auto &p:adjMap)
            sort(p.second.rbegin(),p.second.rend());
            
        vector<string> res;
        DFS(res,adjMap,"JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution1 s;

    vector<vector<string>> tickets = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "JFK"},
        {"ATL", "AAA"}, {"AAA", "ATL"}, {"ATL", "BBB"}, {"BBB", "ATL"},
        {"ATL", "CCC"}, {"CCC", "ATL"}, {"ATL", "DDD"}, {"DDD", "ATL"},
        {"ATL", "EEE"}, {"EEE", "ATL"}, {"ATL", "FFF"}, {"FFF", "ATL"},
        {"ATL", "GGG"}, {"GGG", "ATL"}, {"ATL", "HHH"}, {"HHH", "ATL"},
        {"ATL", "III"}, {"III", "ATL"}, {"ATL", "JJJ"}, {"JJJ", "ATL"},
        {"ATL", "KKK"}, {"KKK", "ATL"}, {"ATL", "LLL"}, {"LLL", "ATL"},
        {"ATL", "MMM"}, {"MMM", "ATL"}, {"ATL", "NNN"}, {"NNN", "ATL"}
    };

    print(s.findItinerary(tickets));
return 0;
}