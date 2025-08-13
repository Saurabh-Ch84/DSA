#include<iostream>
#include<vector>
using namespace std;

class MagicDictionary {
    class Trie{
        public:
        Trie * children[26];
        bool isEnd;
        Trie()
        {
            isEnd=false;
            for(int i=0;i<26;i++) children[i]=nullptr;
        }

        void insert(string word)
        {
            Trie * current=this;
            for(char ch: word)
            {
                if(!current->children[ch-'a'])
                    current->children[ch-'a']=new Trie();
                current=current->children[ch-'a'];    
            }
            current->isEnd=true;
        }

        bool normalSearch(string word)
        {
            Trie * current=this;
            for(char ch: word)
            {
                if(!current->children[ch-'a'])
                    return false;
                current=current->children[ch-'a'];    
            }
            return current->isEnd;
        }

        bool magicSearch(string word)
        {
            Trie * current=this;
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    if(ch==original) continue;
                    word[i]=ch;
                    if(normalSearch(word)) return true;
                }
                word[i]=original;
            }
            return false;
        }
    };
public:
    Trie * t;
    MagicDictionary() {
        t=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string str:dictionary)
            t->insert(str);
    }
    
    bool search(string searchWord){
        return t->magicSearch(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(){

return 0;
}