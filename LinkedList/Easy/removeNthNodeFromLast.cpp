#include<iostream>
using namespace std;


// Definition for singly-linked list.


//my version
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2 { 
    int getLength(ListNode *head){
        int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* deleteHead(ListNode *head){
        ListNode *temp=head->next;
        head->next=nullptr;
        delete head;
        head=temp;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=getLength(head);
        int k=l-n;
        if(k==0) return deleteHead(head);
        ListNode *prev=head;
        while(--k)
            prev=prev->next;
        ListNode *delNode=prev->next;
        prev->next=delNode->next;
        delNode->next=nullptr;
        delete delNode;
        return head;
    }
};


class Solution1 {
    int getLength(ListNode *head){
        int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* deleteHead(ListNode *head){
        ListNode *temp=head->next;
        head->next=nullptr;
        delete head;
        head=temp;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=getLength(head);
        int k=l-n;
        if(k==0) return deleteHead(head);
        ListNode *prev=nullptr,*curr=head;
        while(k--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=nullptr;
        delete curr;
        return head;
    }
};

int main(){

return 0;
}