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
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slowPtr=head, *fastPtr=head, *prev=nullptr;
        while(fastPtr && fastPtr->next){
            prev=slowPtr;
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        if(prev) prev->next=slowPtr->next;
        slowPtr->next=nullptr;
        if(slowPtr==head) return nullptr;
        delete slowPtr;
        return head;
    }
};

int main(){

return 0;
}