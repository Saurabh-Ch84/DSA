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
        ListNode* prev=head;
        ListNode* curr=head->next;
        
        while(curr){
            while(curr && curr->val==prev->val){
                ListNode* delNode=curr;
                curr=curr->next;
                delNode->next=nullptr;
                delete delNode;
            }
            if(curr){
                prev->next=curr;
                prev=prev->next;
                curr=curr->next;
            }
        }
        prev->next=nullptr;
        return head;
    }
};

int main(){

return 0;
}