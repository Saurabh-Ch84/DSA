#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//striver's version
class Solution1 {
    ListNode* getMid(ListNode *node){
        ListNode *slow=node,*fast=node->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *midNode=getMid(head);
        ListNode *nextNode=midNode->next;
        midNode->next=nullptr;
        ListNode * newHead1=mergeSort(head);
        ListNode * newHead2=mergeSort(nextNode);
        return merge(newHead1,newHead2);
    }

    ListNode* merge(ListNode* h1,ListNode * h2){
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy,*mover1=h1,*mover2=h2;
        while(mover1 && mover2){
            if(mover1->val > mover2->val){
                temp->next=mover2;
                mover2=mover2->next;
            }
            else{
                temp->next=mover1;
                mover1=mover1->next;
            }
            temp=temp->next;
        }
        if(mover1) temp->next=mover1;
        if(mover2) temp->next=mover2;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};



//my version
class Solution2 {
    ListNode* getMid(ListNode *node){
        ListNode *slow=node,*fast=node,*midNode=node;
        while(fast && fast->next){
            fast=fast->next->next;
            midNode=slow;
            slow=slow->next;
        }
        return midNode;
    }

    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *midNode=getMid(head);
        ListNode *nextNode=midNode->next;
        midNode->next=nullptr;
        ListNode * newHead1=mergeSort(head);
        ListNode * newHead2=mergeSort(nextNode);
        return merge(newHead1,newHead2);
    }

    ListNode* merge(ListNode* h1,ListNode * h2){
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy,*mover1=h1,*mover2=h2;
        while(mover1 && mover2){
            if(mover1->val > mover2->val){
                temp->next=mover2;
                mover2=mover2->next;
            }
            else{
                temp->next=mover1;
                mover1=mover1->next;
            }
            temp=temp->next;
        }
        if(mover1) temp->next=mover1;
        if(mover2) temp->next=mover2;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

int main(){

return 0;
}