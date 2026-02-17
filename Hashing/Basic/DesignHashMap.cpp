#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Brute-force
class MyHashMap {
    vector<int> arr;
public:
    MyHashMap() {
        arr.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        arr[key]=value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
};

//Optimal
class MyHashMap {
    vector<list<pair<int,int>>> arr;
    int M;
public:
    MyHashMap() {
        M=1e3+9;
        arr.resize(M);
    }
    
    void put(int key, int value) {
        int idx=key%M;
        list<pair<int,int>> &l=arr[idx];
        for(auto &p: l){
            if(p.first==key){
                p.second=value;
                return ;
            }
        }
        l.push_back({key,value});
    }
    
    int get(int key) {
        int idx=key%M;
        list<pair<int,int>> &l=arr[idx];
        for(auto &p: l){
            if(p.first==key)
                return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=key%M;
        list<pair<int,int>> &l=arr[idx];
        for(auto itr=l.begin();itr!=l.end();itr++){
            if(itr->first==key){
                l.erase(itr);
                return ;
            }
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){

return 0;
}