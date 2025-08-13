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

//striver's approach
class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *odd=head;
        ListNode *even=odd->next;
        ListNode *evenHead=odd->next;
        while(even && even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};

//My approach
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *prevPtr=head;
        ListNode *currPtr=prevPtr->next;
        ListNode *frontPtr=currPtr->next;
        while(frontPtr && currPtr){
            currPtr->next=frontPtr->next;
            frontPtr->next=prevPtr->next;
            prevPtr->next=frontPtr;
            prevPtr=frontPtr;
            currPtr=currPtr->next;
            frontPtr=nullptr;
            if(currPtr) frontPtr=currPtr->next;
        }
        return head;
    }
};

int main(){

return 0;
}