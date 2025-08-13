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

class Solution1 {
    ListNode* reverseList(ListNode* head){
        ListNode *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast) slow=slow->next;
        ListNode *restore=slow;
        slow=reverseList(slow);
        fast=head;
        
        while(slow){
            if(slow->val!=fast->val){
                reverseList(restore);
                return false;
            }
            fast=fast->next;
            slow=slow->next;
        }
        reverseList(restore);
        return true;
    }
};

class Solution2 {
    ListNode* reverseList(ListNode* head){
        ListNode *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast) slow=slow->next;
        slow=reverseList(slow);
        fast=head;
        
        while(slow){
            if(slow->val!=fast->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};

int main(){

return 0;
}