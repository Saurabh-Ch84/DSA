#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

using vstr=vector<string>;
using vvstr=vector<vstr>;
using memo_t=unordered_map<string,int>;

class Solution {
    class Trie{
        string name, subPaths;
        map<string,Trie*> childMap; // unordered_map<string,Trie*> childMap; // this also will works but slower!!
                public:
        Trie(string name="/",string subPaths=""){
            this->name=name;
            this->subPaths=subPaths;
        }

        void insert(vstr &path){
            Trie *current=this;
            int n=path.size();
            for(int i=0;i<n;i++){
                if(!current->childMap.count(path[i])){
                    current->childMap[path[i]]=new Trie(path[i]);
                }
                current=current->childMap[path[i]];
            }
        }

        void search_DFS(memo_t &hashMap,vvstr &result,vstr &temp,Trie* current){
            for(auto &p: current->childMap){
                if(hashMap[p.second->subPaths]<=1){
                    temp.push_back(p.first);
                    result.push_back(temp);
                    search_DFS(hashMap,result,temp,p.second);
                    temp.pop_back();
                }
            }
        }

        string propagation_DFS(memo_t &hashMap,Trie* current){
            for(auto &p: current->childMap){
                string nextSubPath=propagation_DFS(hashMap,p.second);
                current->subPaths+="("+p.first+nextSubPath+")";
            }
            if(!current->subPaths.empty()) hashMap[current->subPaths]++;
            return current->subPaths;
        }
    };
public:
    vector<vector<string>> deleteDuplicateFolder(vvstr &paths) {
        int n=paths.size();
        Trie t;
        sort(paths.begin(),paths.end());
        for(int i=0;i<n;i++)
            t.insert(paths[i]);

        memo_t hashMap;
        t.propagation_DFS(hashMap,&t);

        vvstr result;
        vstr temp;
        t.search_DFS(hashMap,result,temp,&t);
        return result;
    }
};

int main(){

return 0;
}