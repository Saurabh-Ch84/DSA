#include<iostream>
using namespace std;

/*You are required to complete this method */
class Node{
    Node *link[26];
        public:
    Node(){
        for(int i=0;i<26;i++) link[i]=nullptr;
    }
        
    bool containsKey(char ch){
        return link[ch-'a'];
    }
    
    Node *get(char ch){
        return link[ch-'a'];
    }
    
    void put(char ch,Node *node){
        link[ch-'a']=node;
    }
};

int countDistinctSubstring(string s) {
    // Your code here
    int answer=0;
    int n=s.length();
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        Node *current=root;
        for(int j=i;j<n;j++)
        {
            if(!current->containsKey(s[j])){
                answer++;
                current->put(s[j],new Node());
            }
            current=current->get(s[j]);
        }
    }
    return answer+1;
}

int main(){

return 0;
}