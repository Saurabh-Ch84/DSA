#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//striver's approach
class Solution1 {
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len += 1;
        }
        k=k%len;
        if (k == 0) return head;
        // attach the tail to the head
        tail->next = head;
        k=len-k;
        ListNode* newLastNode = findNthNode(head,k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};


class Solution2 {
    int getLength(ListNode* head){
        int count=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* reverse(ListNode *head){
        ListNode *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    
    ListNode* getKthNode(ListNode *head,int k){
        ListNode *temp=head;
        while(k>0 && temp){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len=getLength(head);
        k=k%len;
        if(k==0) return head;
        k=len-k-1;
        ListNode *kthNode=getKthNode(head,k);
        ListNode *nextNode=kthNode->next;
        kthNode->next=nullptr;
        ListNode *newHead=reverse(head);
        head->next=reverse(nextNode);
        return reverse(newHead);
    }
};

int main(){

return 0;
}