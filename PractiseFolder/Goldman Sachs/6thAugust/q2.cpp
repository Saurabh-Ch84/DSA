#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
        public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hashMap;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            hashMap[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto& p:hashMap){
            ans.push_back({});
            for(int &indx:p.second)
                ans.back().push_back(strs[indx]);
        }
        return ans;
    }
};

void print(vector<vector<string>> wordList){
    for(vector<string> &words:wordList){
        cout<<"{";
        for(string &word:words)
            cout<<" "<<word;
        cout<<" }";
    }
    cout<<endl;
}

int main(){
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    Solution s;
    print(s.groupAnagrams(strs));
return 0;
}