#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    class Trie{
        public:
            Trie *children[26];
            bool isEnd;
        Trie()    
        {
            isEnd=false;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        }

        void insert(string word)
        {
            Trie *current=this;
            for(char ch: word)
            {
                if(!current->children[ch-'a'])
                    current->children[ch-'a']=new Trie();   
                current=current->children[ch-'a'];
            }
            current->isEnd=true;
        }

        string searchRoot(string derivative)
        {
            Trie * current=this;
            string ans="";
            for(char ch: derivative)
            {
                if(current->children[ch-'a'])
                {
                    if(current->isEnd)
                        return ans;
                    ans+=ch;
                }
                else
                    break;  
                current=current->children[ch-'a'];
            }
            if(current->isEnd)    
                return ans;    
            return derivative;    
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie * t= new Trie();
        for(string &s: dictionary)
            t->insert(s);
        dictionary.clear();
        splitSentence(sentence,dictionary);
        sentence.clear();
        for(string &str:dictionary)
            sentence+=t->searchRoot(str)+" ";
        sentence.pop_back();
        return sentence;
    }

    void splitSentence(const string& sentence,vector<string> &words)
    {
        istringstream iss(sentence);
        string word;
        while(iss>>word)
            words.push_back(word);    
    }
};

int main(){

return 0;
}