#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    bool isCriticalPoint(int a,int b,int c){
        return ((b>a && b>c) || (b<a && b<c));
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head) return {-1,-1};
        int firstCriticalIdx=-1, lastCriticalIdx=-1, idx=0;
        int maxi=-1, mini=1e9;
        ListNode *prev=head, *curr=head->next;
        while(curr && curr->next){
            ListNode* next=curr->next;
            if(isCriticalPoint(prev->val,curr->val,next->val)){
                if(firstCriticalIdx==-1) firstCriticalIdx=idx;
                else{
                    maxi=idx-firstCriticalIdx;
                    mini=min(mini,idx-lastCriticalIdx);
                }
                lastCriticalIdx=idx;
            }
            prev=curr;
            curr=next;
            idx++;
        }
        if(maxi==-1 || mini==1e9) return {-1,-1};
        return {mini,maxi};
    }
};

int main(){

return 0;
}