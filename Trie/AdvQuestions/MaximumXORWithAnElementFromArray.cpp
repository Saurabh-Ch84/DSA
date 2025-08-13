#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    Node *link[2];
        public:
    bool containsKey(int bit){
        return link[bit];
    }
    void put(int bit,Node *node){
        link[bit]=node;
    }
    Node* get(int bit){
        return link[bit];
    }
};

class Trie{
    Node * root;
        public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node * current=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!current->containsKey(bit))
                current->put(bit,new Node());
            current=current->get(bit);
        }
    }

    int maxXOR(int num){
        Node * current=root;
        int result=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int toggledBit=1^bit;
            if(current->containsKey(toggledBit))
            {
                result=result|(1<<i);
                current=current->get(toggledBit);
            }
            else current=current->get(bit);
        }
        return result;
    }
};
class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }

    vector<int> findQueryAnswers(vector<int> &nums,vector<vector<int>> &helperVector){
        vector<int> answer(helperVector.size(),-1);
        Trie trie;
        auto leftIterator=nums.begin();
        for(vector<int> &v:helperVector){
            int num=v[0],threshold=v[1],indx=v[2];
            auto rightIterator=upper_bound(leftIterator,nums.end(),threshold);
            if(rightIterator==nums.begin()) continue;
            for(auto jt=leftIterator;jt!=rightIterator;jt++) 
                trie.insert(*jt);
            answer[indx]=trie.maxXOR(num);
            leftIterator=rightIterator;
        }
        return answer;
    }
public:
    //optimal
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> helperVector;
        helperVector=queries;
        for(int i=0;i<queries.size();i++) helperVector[i].push_back(i);
        sort(helperVector.begin(),helperVector.end(),comp);
        return findQueryAnswers(nums,helperVector);
    }
    //brute
    vector<int> maximizeXOR(vector<int>& nums, vector<vector<int>>& queries) {
         sort(nums.begin(),nums.end());
         vector<int> answer;
         for (vector<int>& query : queries) {
            int xi = query[0], mi = query[1];
            auto it = upper_bound(nums.begin(), nums.end(), mi);
            if (it == nums.begin()) {
                answer.push_back(-1);
                continue;
            }
            int maxXor = -1;
            for (auto jt = nums.begin(); jt != it; ++jt) {
                maxXor = max(maxXor, xi ^ *jt);
            }
            answer.push_back(maxXor);
        }
        return answer;
    }
};

int main(){

return 0;
}