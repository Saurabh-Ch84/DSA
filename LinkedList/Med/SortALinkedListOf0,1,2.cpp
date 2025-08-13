#include<iostream>
#include<vector>
using namespace std;

//Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


//striver's version

class Solution4 {
    
  public:
    Node* segregate(Node* head) {
        // code here
        Node *dummyZero=new Node(-1),*zero=dummyZero;
        Node *dummyOne=new Node(-1),*one=dummyOne;
        Node *dummyTwo=new Node(-1),*two=dummyTwo;
        Node *mover=head;
       while(mover){
            int num=mover->data;
            if(num==0){
                zero->next=mover;
                zero=zero->next;
            }
            else if(num==1){
                one->next=mover;
                one=one->next;
            }
            else{
                two->next=mover;
                two=two->next;
            }
            mover=mover->next;
        }
        zero->next=(dummyOne->next)?dummyOne->next:dummyTwo->next;
        one->next=dummyTwo->next;
        two->next=nullptr;
        return dummyZero->next;
    }
};


//striver's version
class Solution3 {
    
  public:
    Node* segregate(Node* head) {
        // code here

        //never use vector<Node*> nodes(3,new Node(-1));
        Node *dummyZero=new Node(-1),*zero=dummyZero;
        Node *dummyOne=new Node(-1),*one=dummyOne;
        Node *dummyTwo=new Node(-1),*two=dummyTwo;
        Node *mover=head;
       while(mover){
            int num=mover->data;
            Node *nextNode=mover->next;
            mover->next=nullptr;
            if(num==0){
                zero->next=mover;
                zero=zero->next;
            }
            else if(num==1){
                one->next=mover;
                one=one->next;
            }
            else{
                two->next=mover;
                two=two->next;
            }
            mover = nextNode;
        }
        zero->next=(dummyOne->next)?dummyOne->next:dummyTwo->next;
        one->next=dummyTwo->next;
        dummyTwo->next=nullptr;
        Node * newHead=dummyZero->next;
        delete dummyZero;
        delete dummyOne;
        delete dummyTwo;
        return newHead;
    }
};

// better code
class Solution2{
    
  public:
    Node* segregate(Node* head) {
        // code here
        vector<Node*> nodes(3,nullptr);
        Node *head0=nullptr,*head1=nullptr,*head2=nullptr;
        Node *mover=head;
       while(mover) {
            int num = mover->data;
            if (nodes[num] == nullptr) {
                if(num == 0) head0 = mover;
                else if(num == 1) head1 = mover;
                else head2 = mover;
            nodes[num] = mover;
            } else {
                nodes[num]->next = mover;
                nodes[num] = nodes[num]->next;
            }
            mover = mover->next;
        }
        // After traversal is finished, terminate each list properly
        if(nodes[0]) nodes[0]->next = nullptr;
        if(nodes[1]) nodes[1]->next = nullptr;
        if(nodes[2]) nodes[2]->next = nullptr;

        if(head2){
            if(head1){
                nodes[1]->next=head2;
                if(head0){
                    nodes[0]->next=head1;
                    return head0;
                }
                return head1;
            }
            else{
                if(head0){
                    nodes[0]->next=head2;
                    return head0;
                }
                return head2;
            }
        }
        if(head1){
            if(head0){
                nodes[0]->next=head1;
                return head0;
            }
            return head1;
        }
        return head0;
    }
};

//my version
class Solution1 {
    
  public:
    Node* segregate(Node* head) {
        // code here
        vector<Node*> nodes(3,nullptr);
        Node *head0=nullptr,*head1=nullptr,*head2=nullptr;
        Node *mover=head;
        while(mover){
            int num=mover->data;
            Node *temp=new Node(num);
            if(nodes[num]==nullptr)
            {
                if(num==0) head0=temp;
                if(num==1) head1=temp;
                if(num==2) head2=temp;
                nodes[num]=temp;
            }
            else{
                nodes[num]->next=temp;
                nodes[num]=nodes[num]->next;
            }
            mover=mover->next;
        }
        
        if(head2){
            if(head1){
                nodes[1]->next=head2;
                if(head0){
                    nodes[0]->next=head1;
                    return head0;
                }
                return head1;
            }
            else{
                if(head0){
                    nodes[0]->next=head2;
                    return head0;
                }
                return head2;
            }
        }
        
        if(head1){
            if(head0){
                nodes[0]->next=head1;
                return head0;
            }
            return head1;
        }
        
        return head0;
    }
};

int main(){

return 0;
}