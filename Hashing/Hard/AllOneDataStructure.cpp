#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
using namespace std;

//Better Approach
class AllOne {
    unordered_map<string,int> hashMap;
    set<pair<int,string>> set_;

    void update(string &key){
        int f_=hashMap[key];
        set_.erase({f_,key});
    }
public:
    AllOne() {}
    
    void inc(string key) { //O(logn)
        if(hashMap.count(key))
            update(key);
        hashMap[key]++;
        int f=hashMap[key];
        set_.insert({f,key});
    }
    
    void dec(string key) { //O(logn)
        if(hashMap.count(key))
            update(key);
        hashMap[key]--;
        if(hashMap[key]){
            int f=hashMap[key];
            set_.insert({f,key});
        }
        else hashMap.erase(key);
    }
    
    string getMaxKey(){ //O(1)
        if(set_.empty()) return "";
        return set_.rbegin()->second;
    }
    
    string getMinKey(){ //O(1)
        if(set_.empty()) return "";
        return set_.begin()->second;
    }
};

class AllOne {
    class Node{
            public:
        int freq;
        unordered_set<string> stringSet;
        Node* prev;
        Node* next;
        Node(const string &str,int freq=1){
            this->freq=freq;
            stringSet.insert(str);
            next=nullptr, prev=nullptr;
        }
    };
    
    unordered_map<string,Node*> keyNode;
    Node *head, *tail;

    void insert(string &key,int f,Node* before){
        if(before->next->freq==f){
            auto &tempSet=before->next->stringSet;
            tempSet.insert(key);
        }
        else{
            Node* temp=new Node(key,f);
            temp->next=before->next;
            before->next->prev=temp;
            before->next=temp;
            temp->prev=before;
        }
        keyNode[key]=before->next;
        return ;
    }

    void remove(string &key,int f,Node* after){
        if(after->prev->freq==f){
            auto &tempSet=after->prev->stringSet;
            tempSet.insert(key);
        }
        else{
            Node* temp=new Node(key,f);
            temp->next=after;
            temp->prev=after->prev;
            after->prev->next=temp;
            after->prev=temp;
        }
        keyNode[key]=after->prev;
        return ;
    }

    void deleteNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;

        before->next=node->next;
        after->prev=node->prev;

        node->next=nullptr;
        node->prev=nullptr;
        delete node;
    }

public:
    AllOne() {
        head=new Node("",0);
        tail=new Node("",-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void inc(string key) {
        if(!keyNode.count(key)){
            insert(key,1,head);
        }
        else{
            Node* node=keyNode[key];
            auto &tempSet=node->stringSet;
            tempSet.erase(key);
            insert(key,node->freq+1,node);
            if(tempSet.empty()) deleteNode(node);
        }
    }
    
    void dec(string key) {
        Node* node=keyNode[key];
        auto &tempSet=node->stringSet;
        tempSet.erase(key);
        if(node->freq>1) remove(key,node->freq-1,node);
        else keyNode.erase(key);
        if(tempSet.empty()) deleteNode(node);
    }
    
    string getMaxKey() {
        if(tail->prev==head) return "";
        return *(tail->prev->stringSet.begin());
    }
    
    string getMinKey() {
        if(head->next==tail) return "";
        return *(head->next->stringSet.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(){

return 0;
}