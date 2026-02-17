#include<iostream>
#include<vector>
#include<list>

using namespace std;

// Brute-Force
class MyHashSet {
    vector<bool> indexKey;
public:
    MyHashSet() {
        indexKey.resize(1e6+1,false);
    }
    
    void add(int key) {
        indexKey[key]=true;
    }
    
    void remove(int key) {
        indexKey[key]=false;
    }
    
    bool contains(int key) {
        return indexKey[key];
    }
};

class MyHashSet {
    vector<list<int>> v;
    int sz;
public:
    MyHashSet() {
        sz=1e5;
        v.resize(sz+1);
    }
    
    void add(int key) {
        int idx=key%sz;
        list<int> &list_=v[idx];
        for(int x: list_)
            if(x==key) return;
        list_.push_back(key);
    }
    
    void remove(int key) {
        int idx=key%sz;
        list<int> &list_=v[idx];
        list_.remove(key);
    }
    
    bool contains(int key) {
        int idx=key%sz;
        list<int> &list_=v[idx];
        for(int x: list_)
            if(x==key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){

return 0;
}