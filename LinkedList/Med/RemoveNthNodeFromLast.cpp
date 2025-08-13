#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head;
        for(int i=0;i<n;i++) fast=fast->next;
        if(fast==nullptr){
            slow=head->next;
            head->next=nullptr;
            delete head;
            head=slow;
            return head;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *delNode=slow->next;
        slow->next=delNode->next;
        delNode->next=nullptr;
        delete delNode;
        return head;
    }
};

int main(){

return 0;
}