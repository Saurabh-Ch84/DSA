#include <iostream>
using namespace std;

// Definition for singly-linked list.

//Leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//striver's code
class Solution3 {
    void reverse(ListNode *head){
        ListNode *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
    }

    ListNode* findKthNode(ListNode *head,int k){
        ListNode *temp=head;
        k-=1;
        while(k && temp){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head,*prevLast=nullptr;
        while(temp!=nullptr){
            ListNode *kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode *nextNode=kthNode->next;
            kthNode->next=nullptr;
            reverse(temp);
            if(temp==head) head=kthNode;
            else prevLast->next=kthNode;
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};





class Solution1 {
    ListNode* reverse(ListNode *head,ListNode *tail){
        ListNode *prev=nullptr,*curr=head,*front=head;
        while(front!=tail)
        {
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        int K=0;
        ListNode *tail=head;
        while(K<k && tail){
            K++;
            tail=tail->next;
        }
        if(K<k) return head;
        ListNode *newHead=reverse(head,tail);
        head->next=reverseKGroup(tail,k);
        return newHead;
    }
};


//GFG
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

class Solution2
{
    Node *reverse(Node *head, Node *tail)
    {
        Node *prev = nullptr, *curr = head;
        while (curr != tail)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        if (!head)
            return head;
        int K = 0;
        Node *lastNode = head;
        while (K < k && lastNode)
        {
            lastNode = lastNode->next;
            K++;
        }
        Node *newHead = reverse(head, lastNode); // lastNode exclusive
        if (K < k)
            return newHead; // swap if left out nodes are not k's multiple
        head->next = reverseKGroup(lastNode, k);
        return newHead;
    }
};

int main()
{

    return 0;
}