#include<iostream>
using namespace std;

// Link list Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


//striver's version
class Solution2 {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *dummy=new Node(-1);
        Node *t1=list1,*t2=list2,*temp=dummy;
        while(t1 && t2){
            if(t1->val>t2->val){
                temp->next=t2;
                t2=t2->next;
            }
            else{
                temp->next=t1;
                t1=t1->next;
            }
            temp=temp->next;
        }

        if(t1) temp->next=t1;
        if(t2) temp->next=t2;

        return dummy->next;
    }
};
class Solution1 {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1 && head2 && head1->data > head2->data) swap(head2,head1);
        if(!head1 && !head2) return nullptr;
        if(!head1 && head2) return head2;
        if(head1 && !head2) return head1;
        
        head1->next=sortedMerge(head1->next,head2);
        return head1;
    }
};

int main(){

return 0;
}