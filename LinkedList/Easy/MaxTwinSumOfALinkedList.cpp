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
    void findMaxPairSum(ListNode* head,vector<int> &arr,int &maxi,int sz,int i){
        if(!head) return ;
        if(i<sz){
            arr[i]+=head->val;
            maxi=max(maxi,arr[i]);
        }
        else{
            arr[2*sz-i-1]+=head->val;
            maxi=max(maxi,arr[2*sz-i-1]);
        }
        findMaxPairSum(head->next,arr,maxi,sz,i+1);
    }
public:
    int pairSum(ListNode* head) {
        int n=0, maxi=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        vector<int> arr(n/2,0);
        findMaxPairSum(head,arr,maxi,n/2,0);
        return maxi;
    }
};

int main(){

return 0;
}