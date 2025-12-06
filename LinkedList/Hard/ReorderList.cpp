#include<iostream>
#include<stack>
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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        ListNode* midNode=findMid(curr);
        ListNode* revNode=reverse(midNode);
        ListNode* frontNode=head;
        while(revNode){
            ListNode* nextNode1=frontNode->next;
            ListNode* nextNode2=revNode->next;
            frontNode->next=revNode;
            revNode->next=nextNode1;
            frontNode=nextNode1;
            revNode=nextNode2;
        }   
        frontNode->next=nullptr;
    }
};

class Solution2 {
    int findLen(ListNode* curr){
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        int len=findLen(curr);
        int half=(len+1)/2;
        curr=head;
        while(half){
            half--;
            if(half==0){
                ListNode* revNode=reverse(curr->next);
                ListNode* frontNode=head;
                while(revNode){
                    ListNode* nextNode1=frontNode->next;
                    ListNode* nextNode2=revNode->next;
                    frontNode->next=revNode;
                    revNode->next=nextNode1;
                    frontNode=nextNode1;
                    revNode=nextNode2;
                }   
                frontNode->next=nullptr;
                return ;
            }
            curr=curr->next;
        }
    }
};


//Brute
class Solution1 {
    int findLen(ListNode* curr){
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        return len;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        int len=findLen(curr);
        int half=(len+1)/2,count=0;
        stack<ListNode*> s;
        curr=head;
        while(curr){
            count++;
            if(count>half)
                s.push(curr);
            curr=curr->next;
        }
        curr=head;
        while(!s.empty()){
            ListNode* frontNode=curr->next;
            ListNode* newNode = s.top(); s.pop();
            newNode->next = frontNode;
            curr->next = newNode;
            curr=frontNode;
        }
        curr->next=nullptr;
    }
};

int main(){

return 0;
}