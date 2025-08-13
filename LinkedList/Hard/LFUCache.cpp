#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LFUCache1 {
    class CacheEntry{
          public:  
        int val,freq; //value of key and freq of key
        list<int>::iterator itr; //iterator to frequency list of frequnecy freq
        CacheEntry(int val_,int freq_,list<int>::iterator itr_){ //for entries in KeyToNode hashMap
            val=val_;
            freq=freq_;
            itr=itr_;
        }
        CacheEntry():val(0),freq(0),itr(nullptr){} //very important while using maps
    };
    
    unordered_map<int,CacheEntry> keyToNode; //stores LFUCache key->cacheEntry
    unordered_map<int,list<int>> freqToNodes; // stores frequency->Doubly Linked List
    int minFreq; //Tracks minimum Frequency
    int capacity; //Cache's Capacity

    void deleteLFU(){ //Delete the LFU 
        int LFU_key=freqToNodes[minFreq].back(); //Delete from back ensuring LRU property
        list<int>::iterator LFU_node=keyToNode[LFU_key].itr;
        freqToNodes[minFreq].erase(LFU_node); //Delete the LFU node
        if(freqToNodes[minFreq].empty())
            freqToNodes.erase(minFreq); //Delete the linked list if it's empty     
        keyToNode.erase(LFU_key); //Delete the LFU node's key
    }

    void updateCache(int key){ //Update frequencies of prexisting entries
        int oldFreq=keyToNode[key].freq;
        list<int>::iterator node=keyToNode[key].itr;
        int newFreq=oldFreq+1;
        freqToNodes[oldFreq].erase(node);//Delete old frequency
        if(freqToNodes[oldFreq].empty())
        {
            freqToNodes.erase(oldFreq); //Delete the linked list if it's empty
            if(minFreq==oldFreq) minFreq=newFreq; //update the minimum Frequecny
        }
        //update new frequency
        freqToNodes[newFreq].push_front(key); //Insert at front to ensure LRU property
        keyToNode[key].freq=newFreq; //Update entry don't make new entry
        keyToNode[key].itr=freqToNodes[newFreq].begin(); //Store latest data
    }
public:
    LFUCache1(int capacity) {
        minFreq=1;  
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(keyToNode.find(key)!=keyToNode.end()){
            int value=keyToNode[key].val;
            updateCache(key);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0) return ;
        if(keyToNode.find(key)!=keyToNode.end()){
            //Update old Value
            keyToNode[key].val=value;
            updateCache(key);
            return ;
        }
        else if(keyToNode.find(key)==keyToNode.end() && keyToNode.size()==capacity)
            deleteLFU(); //cache full 

        //inserting for the first time
        minFreq=1;
        freqToNodes[minFreq].push_front(key); //Ensure LRU 
        CacheEntry ce(value,minFreq,freqToNodes[minFreq].begin()); //create object
        keyToNode[key]=ce;//new entry made
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LFUCache2 {
    struct collection{
        int val;
        int freq;
        list<int>::iterator itr_;
        collection():val(-1),freq(-1),itr_(nullptr){}
    };
    unordered_map<int,collection> keyToNode;
    unordered_map<int,list<int>> freqToNodes;
    int minFreq;
    int capacity;

    void deleteLFU(){
        int LFU_key=freqToNodes[minFreq].back();
        list<int>::iterator LFU_itr=keyToNode[LFU_key].itr_;
        freqToNodes[minFreq].erase(LFU_itr);
        if(freqToNodes[minFreq].empty())
            freqToNodes.erase(minFreq);      
        keyToNode.erase(LFU_key);
    }

    void updateCache(int key){
        int oldFreq=keyToNode[key].freq;
        list<int>::iterator itr=keyToNode[key].itr_;
        int newFreq=oldFreq+1;
        freqToNodes[oldFreq].erase(itr);
        if(freqToNodes[oldFreq].empty())
        {
            freqToNodes.erase(oldFreq);
            if(minFreq==oldFreq) minFreq=newFreq;
        }
        freqToNodes[newFreq].push_front(key);
        keyToNode[key].freq=newFreq;
        keyToNode[key].itr_=freqToNodes[newFreq].begin();
    }
public:
    LFUCache2(int capacity) {
        minFreq=-1;  
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(keyToNode.find(key)!=keyToNode.end()){
            int value=keyToNode[key].val;
            updateCache(key);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyToNode.find(key)!=keyToNode.end()){
            keyToNode[key].val=value;
            updateCache(key);
            return ;
        }
        else if(keyToNode.find(key)==keyToNode.end() && keyToNode.size()==capacity)
            deleteLFU();
        
        minFreq=1;
        freqToNodes[minFreq].push_front(key);
        collection temp;
        temp.val=value;
        temp.freq=minFreq;
        temp.itr_=freqToNodes[minFreq].begin();
        keyToNode[key]=temp;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

return 0;
}