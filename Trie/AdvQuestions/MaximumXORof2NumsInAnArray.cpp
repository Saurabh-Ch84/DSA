#include<iostream>
#include<vector>
using namespace std;

class Node {
    Node* links[2];
public:
    bool containsKey(int bit) {
        return links[bit];
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    ~Node() {
        for (int i = 0; i < 2; ++i) {
            if (links[i]) {
                delete links[i];
            }
        }
    }
};

class Trie{
    Node * root;
        public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* current=root;
        for(int i=31;i>=0;i--)
        { 
            int bit=(num>>i)&1;
            if(!current->containsKey(bit)) current->put(bit,new Node());
            current=current->get(bit);
        }
    }

    int findXOR(int num)
    {
        Node *current=root;
        int result=0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int toggledBit = 1 ^ bit;
            if(current->containsKey(toggledBit))
            {
                result = result|(1<<i);
                current = current->get(toggledBit);
            } 
            else current = current->get(bit);
        }
        return result;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int answer=0;
        Trie trie;
        for(int &num:nums)
            trie.insert(num);
        for(int &num:nums){
            int tempAns=trie.findXOR(num);
            answer=max(tempAns,answer);
        }
        return answer;
    }
};

int main(){

return 0;
}