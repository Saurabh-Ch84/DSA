#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution1 {
    int recursion(Node *head){
        if(!head) return 1;
        head->data=head->data+recursion(head->next);
        int carry=head->data/10;
        head->data=head->data%10;
        return carry;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        Node *mover=head;
        if(recursion(mover)){
            Node *temp=new Node(1);
            temp->next=head;
            head=temp;
        }
        return head;
        // return head of list after adding one
    }
};

//my version
class Solution2 {
    Node* reverse(Node *head){
        Node *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        head=reverse(head);
        Node *mover=head;
        int carry=1;
        while(mover){
            int num=mover->data;
            int newNum=num+carry;
            carry=newNum/10;
            mover->data=newNum%10;
            mover=mover->next;
            if(carry==0) break; 
        }
        head=reverse(head);
        if(carry){
            Node *temp=new Node(1);
            temp->next=head;
            head=temp;
        }
        return head;
        // return head of list after adding one
    }
};

int main(){

return 0;
}