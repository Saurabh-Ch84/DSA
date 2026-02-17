#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Node{
        public:
    int freq;
    unordered_set<string> keysSet;
    Node* prev;
    Node* next;
    Node(const string &str,int freq=1){
        this->freq=freq;
        keysSet.insert(str);
        next=nullptr, prev=nullptr;
    }
};

class AllOne {
    void insert(string &key,int f,Node* before){
        if(before->next->freq==f){
            auto &tempSet=before->next->keysSet;
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
            auto &tempSet=after->prev->keysSet;
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

    bool isEmpty(){
        return (head->next==tail);
    }
    
    unordered_map<string,Node*> keyNode;
    Node *head, *tail;
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
            auto &tempSet=node->keysSet;
            tempSet.erase(key);
            insert(key,node->freq+1,node);
            if(tempSet.empty()) deleteNode(node);
        }
    }
    
    void dec(string key) {
        Node* node=keyNode[key];
        auto &tempSet=node->keysSet;
        tempSet.erase(key);
        if(node->freq>1) remove(key,node->freq-1,node);
        else keyNode.erase(key);
        if(tempSet.empty()) deleteNode(node);
    }
    
    string getMaxKey() {
        if(isEmpty()) return "";
        return *(tail->prev->keysSet.begin());
    }
    
    string getMinKey() {
        if(isEmpty()) return "";
        return *(head->next->keysSet.begin());
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