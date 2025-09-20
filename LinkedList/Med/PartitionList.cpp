#include<iostream>
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
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* dummy1=new ListNode(-201);
        ListNode* mover1=dummy1;
        ListNode* dummy2=new ListNode(-201);
        ListNode* mover2=dummy2;

        ListNode* curr=head;

        while(curr){
            int val=curr->val;
            if(val<x){
                mover1->next=curr;
                mover1=mover1->next;
            }
            else{
                mover2->next=curr;
                mover2=mover2->next;
            }
            curr=curr->next;
        }
        
        mover2->next=nullptr;
        mover1->next=dummy2->next;
        
        dummy2->next=nullptr;
        curr=dummy1->next;
        dummy1->next=nullptr;
        delete dummy1,dummy2;

        return curr;
    }
};

int main(){

return 0;
}