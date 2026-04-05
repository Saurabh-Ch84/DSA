#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

using vint=vector<int>;
using vvint=vector<vint>;

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        unordered_map<int,vector<int>> hashMap;
        hashMap[0]={root->data};
        int mini=INT_MAX;
        
        
        while(!q.empty()){
            pair<Node*,int> entry=q.front(); q.pop();
            mini=min(mini,entry.second);
            if(entry.first->left){
                q.push({entry.first->left,entry.second-1});
                hashMap[entry.second-1].push_back(entry.first->left->data);
            }
            if(entry.first->right){
                q.push({entry.first->right,entry.second+1});
                hashMap[entry.second+1].push_back(entry.first->right->data);
            }
        }
        
        int n=hashMap.size();
        vvint result(n);
        for(auto &p: hashMap){
            //normalize
            result[p.first-mini]=p.second;
        }
        return result;
    }
};

//Brute-Force Solution
class Fancy1{
    vector<long long> arr, multFactor, addFactor;
    const int mod=1e9+7;
public:
    Fancy1(){}
    
    void append(int val) {
        arr.push_back(val);
        multFactor.push_back(1);
        addFactor.push_back(0);
    }
    
    void addAll(int inc) {
        if(arr.empty()) return ;
        addFactor.back()=(addFactor.back()+inc)%mod;
    }
    
    void multAll(int m) {
        if(arr.empty()) return ;
        multFactor.back()=((multFactor.back()%mod)*m)%mod;
        addFactor.back()=((addFactor.back()%mod)*m)%mod;
    }
    
    int getIndex(int idx){
        if(idx>=arr.size()) return -1;
        long long val = arr[idx];
        for(int i = idx; i < arr.size(); i++){
            val = (val * multFactor[i]) % mod;
            val = (val + addFactor[i]) % mod;
        }
        return (int)val;
    }
};

//Optimal Solution
class Fancy2{
    const int mod=1e9+7;
    vector<long long> arr;
    long long add, mult;

    int inverseModM(long long mult){
        int p=mod-2;
        return binExpo(mult,p);
    }

    long long binExpo(long long b, int p){
        long long res = 1;
        b %= mod;
        while(p > 0){
            if (p & 1) 
                res = (res * b) % mod;
            b = (b * b) % mod;
            p = (p>>1);
        }
        return res;
    }

public:
    Fancy2(): add(0), mult(1) {}
    
    void append(int val) {
        // storing inverse intentionally.
        int numerator=((val%mod)-(add%mod)+mod)%mod;
        int inverseDenominator=inverseModM(mult);
        arr.push_back((1LL*numerator*inverseDenominator)%mod);
    }
    
    void addAll(int inc){
        add=(add+inc)%mod;
    }
    
    void multAll(int m){
        add=((add%mod)*m)%mod;
        mult=((mult%mod)*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size()) return -1;
        return ((arr[idx]*mult)%mod+(add%mod))%mod;
    }
};


/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

int main(){
    return 0;
}