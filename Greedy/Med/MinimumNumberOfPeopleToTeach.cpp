#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isFriendshipCommunicating(int u,int v,vector<vector<int>>& languages){
        unordered_set<int> hashSet(languages[u-1].begin(),languages[u-1].end());
        for(int &lang:languages[v-1])
            if(hashSet.count(lang)) return true;
        return false;
    }

    int findUsersToTeach(unordered_map<int,unordered_set<int>> &hashMap,int lang){
        int count=0;
        for(auto &itr:hashMap)
            if(!itr.second.count(lang)) count++;
        return count;
    }

public:
    int minimumTeachings1(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships){
        unordered_map<int,unordered_set<int>> hashMap;

        for(vector<int> &friendship:friendships){
            int u=friendship[0],v=friendship[1];
            if(!isFriendshipCommunicating(u,v,languages)){
                hashMap[u].insert(languages[u-1].begin(),languages[u-1].end());
                hashMap[v].insert(languages[v-1].begin(),languages[v-1].end());
            }
        }

        if(hashMap.empty()) return 0;

        vector<int> langKnow(n+1,0);
        int maxSpokenLang=0,maxSpokenCount=0;
        for(auto &itr:hashMap){
            int u=itr.first;
            for(int &lang:languages[u-1])
            {
                langKnow[lang]++;
                if(langKnow[lang]>maxSpokenCount){
                    maxSpokenLang=lang;
                    maxSpokenCount=langKnow[lang];
                }
            }
        }
        int ans=findUsersToTeach(hashMap,maxSpokenLang);
        return ans;
    }
    //Most optimal
    int minimumTeachings2(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships){
        unordered_set<int> hashSet;

        for(vector<int> &friendship:friendships){
            int u=friendship[0],v=friendship[1];
            if(!isFriendshipCommunicating(u,v,languages)){
                hashSet.insert(u);
                hashSet.insert(v);
            }
        }

        if(hashSet.empty()) return 0;
        vector<int> langKnow(n+1,0);
        int maxSpokenLang=0,maxSpokenLangCount=0;
        int totalNonCommunicatingUsers=hashSet.size();

        for(int u:hashSet){
            for(int &lang:languages[u-1])
            {
                langKnow[lang]++;
                if(langKnow[lang]>maxSpokenLangCount){
                    maxSpokenLang=lang;
                    maxSpokenLangCount=langKnow[lang];
                }
            }
        }

        int ans=totalNonCommunicatingUsers-maxSpokenLangCount;
        return ans;
    }
};

int main(){
    Solution s;
    int n=4;
    vector<vector<int>> languages={{1,4},{2,3},{3,4},{1},{4}};
    vector<vector<int>> friendships={{1,2},{2,3},{3,4},{4,5},{1,5}};
    cout<<s.minimumTeachings2(n,languages,friendships)<<endl;
return 0;
}