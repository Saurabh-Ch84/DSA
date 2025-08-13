#include<iostream>
using namespace std;

// Link list Node
struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        if(!head) return -1;
        // code here
        Node *fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
};

int main(){

return 0;
}