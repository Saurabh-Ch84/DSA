#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

using pii = pair<int,int> ;

class kQueues {
    class entry{
            public:
        int val, id, nextIdx;
        entry(int val=-1,int id=-1,int nextIdx=-1){
            this->val=val;
            this->id=id;
            this->nextIdx=nextIdx;
        }
    };
    unordered_set<int> freeIndices;
    unordered_map<int,pii> queueMap;
    vector<entry> arr;
    int k;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this->k=k;
        arr.resize(n);
        for(int i=0;i<n;i++)
            freeIndices.insert(i);
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(freeIndices.empty() || i>=k) return ;
        auto itr=freeIndices.begin();
        int idx=*itr;
        freeIndices.erase(itr);
        if(!queueMap.count(i))
            queueMap[i]={idx,idx};
        else{
            int end=queueMap[i].second;
            arr[end].nextIdx=idx;
            queueMap[i].second=idx;
        }
        arr[idx].val=x;
        arr[idx].id=i;
        arr[idx].nextIdx=-1;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(!queueMap.count(i) || i>=k) return -1;
        int start=queueMap[i].first;
        int val=arr[start].val;
        if(arr[start].nextIdx==-1)
            queueMap.erase(i);
        else queueMap[i].first=arr[start].nextIdx;
        freeIndices.insert(start);
        return val;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return !queueMap.count(i);
    }

    bool isFull() {
        // check if array is full
        return freeIndices.empty();
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char letter: letters){
            if(letter>target)
                return letter;
        }
        return letters[0];
    }
};

int main(){

return 0;
}