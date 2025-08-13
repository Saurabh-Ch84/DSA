#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


//tortoise-hare algo
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *fast=head,*slow=head;
        bool isCyclic=false;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                isCyclic=true;
                break;
            }
        }
        if(!isCyclic) return 0;
        
        int cycleLength=0;
        do{
            slow=slow->next;
            cycleLength++;
        } while(fast!=slow);
        
        return cycleLength;
    }
};

int main(){

return 0;
}