#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char ch){
        ch=tolower(ch);
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    string deVowel(const string &word){
        string res=word;
        int n=word.length();
        for(int i=0;i<n;i++)
            res[i]=isVowel(res[i])? '*':tolower(res[i]);
        return res;
    }

    string toLower(const string &word){
        string res=word;
        int n=word.length();
        for(int i=0;i<n;i++)
            res[i]=tolower(res[i]);
        return res;
    }

public:
    vector<string> spellchecker2(vector<string>& wordlist, vector<string>& queries){
        unordered_set<string> exactHashSet;
        unordered_map<string,string> caseInsensitiveHashMap;
        unordered_map<string,string> vowelErrorHashMap;

        for(const string &word:wordlist){
            string lower=toLower(word);
            string devow=deVowel(word);
            exactHashSet.insert(word);
            if(caseInsensitiveHashMap.count(lower)==0)
                caseInsensitiveHashMap[lower]=word;
            if(vowelErrorHashMap.count(devow)==0)
                vowelErrorHashMap[devow]=word;
        }

        vector<string> result;
        for(const string &query:queries){
            if(exactHashSet.count(query)) result.push_back(query);
            else{
                string lower=toLower(query);
                string devow=deVowel(query);
                if(caseInsensitiveHashMap.count(lower)) 
                    result.push_back(caseInsensitiveHashMap[lower]);
                else if(vowelErrorHashMap.count(devow))
                    result.push_back(vowelErrorHashMap[devow]);
                else 
                    result.push_back("");
            }
        }
        return result;
    }

    vector<string> spellchecker1(vector<string>& wordlist, vector<string>& queries){
        unordered_set<string> exactHashSet;
        unordered_map<string,int> caseInsensitiveHashMap;
        unordered_map<string,int> vowelErrorHashMap;

        int n=wordlist.size();
        for(int i=0;i<n;i++){
            string lower=toLower(wordlist[i]);
            string devow=deVowel(wordlist[i]);
            exactHashSet.insert(wordlist[i]);
            if(caseInsensitiveHashMap.count(lower)==0)
                caseInsensitiveHashMap[lower]=i;
            if(vowelErrorHashMap.count(devow)==0)
                vowelErrorHashMap[devow]=i;
        }

        vector<string> result;
        for(const string &query:queries){
            if(exactHashSet.count(query)) result.push_back(query);
            else{
                string lower=toLower(query);
                string devow=deVowel(query);
                if(caseInsensitiveHashMap.count(lower)){
                    int i=caseInsensitiveHashMap[lower];
                    result.push_back(wordlist[i]);
                } 
                else if(vowelErrorHashMap.count(devow)){
                    int i=vowelErrorHashMap[devow];
                    result.push_back(wordlist[i]);
                }
                else 
                    result.push_back("");
            }
        }
        return result;
    }
};

void print(vector<string> res){
    for(string &str:res){
        cout<<str<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<string> wordList={"Kite","kity","PussY","puSSY","puss","aura"};
    vector<string> queries={"puss","PUSSY","KiTe","Katy","PissY","fish","piss","euro"};
    print(s.spellchecker1(wordList,queries));
return 0;
}