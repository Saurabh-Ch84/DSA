#include<iostream>
using namespace std;

// User function Template for C++

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node() { data = 0; next = prev = NULL; }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        if(!*head_ref) return ;
        Node* dummy = new Node();
        dummy->data = -1;
        dummy->next = nullptr;
        dummy->prev = nullptr;

        Node *temp=*head_ref;
        temp->prev=dummy;
        dummy->next=temp;
        
        while(temp){
            if(temp->data==x){
                Node *nextNode=temp->next;
                temp->prev->next=temp->next;
                if(temp->next) temp->next->prev=temp->prev;
                temp->next=temp->prev=nullptr;
                delete temp;
                temp=nextNode;
                continue;
            }
            temp=temp->next;
        }
        *head_ref=dummy->next;
    }
};

int main(){

return 0;
}