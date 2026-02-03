#include<iostream>
#include<vector>
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=head->next;
        head->next=nullptr;
        while(curr){
            ListNode* nextNode=curr->next;
            ListNode* prev=&dummy;
            ListNode* front=dummy.next;
            while(front && front->val<curr->val){
                prev=front;
                front=front->next;
            }
            prev->next=curr;
            curr->next=front;
            curr=nextNode;
        }
        return dummy.next;
    }
};

int main(){

return 0;
}