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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                int val=curr->val;
                while(curr && curr->val==val){
                    ListNode* delNode=curr;
                    curr=curr->next;
                    delNode->next=nullptr;
                    delete delNode;
                }
                if(prev) prev->next=curr;
                else head=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};

int main(){

return 0;
}