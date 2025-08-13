#include <iostream>
using namespace std;

class Node {
    Node* links[26];
    bool flag;
    int countEndWith;
    int countPrefix;
public:
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        flag = false;
        countEndWith=0;
        countPrefix=0;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    void increaseEnd(){
        countEndWith++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void deleteEnd(){
        countEndWith--;
    }

    void reducePrefix(){
        countPrefix--;
    }

    int getEnd(){
        return countEndWith;
    }

    int getPrefix(){
        return countPrefix;
    }

    ~Node() {
        for (int i = 0; i < 26; ++i) {
            if (links[i]) {
                delete links[i];
            }
        }
    }
};

class Trie{
    Node* root;

        public:
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch))
                current->put(ch,new Node());
            current=current->get(ch);
            current->increasePrefix();
        }
        current->setEnd();
        current->increaseEnd();
    }

    bool search(string word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch))
                return false;
            current=current->get(ch);
        }
        return current->isEnd();
    }

    bool startsWith(string word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch))
                return false;
            current=current->get(ch);
        }
        return true;
    }

    int countWordsEqualTo(string word){
        Node * current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch)) return 0;
            current=current->get(ch);
        }
        return current->getEnd();
    }

    int countWordsStartingWith(string word){
        Node * current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch)) return 0;
            current=current->get(ch);
        }
        return current->getPrefix();
    }

    void erase(string word){
        Node * current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch)) return ;
            current=current->get(ch);
            current->reducePrefix();
        }
        if(current->isEnd()<=0) return;
        current->deleteEnd();
    }

    ~Trie() {
        delete root;
    }
};

int main() {
    
    return 0;
}
