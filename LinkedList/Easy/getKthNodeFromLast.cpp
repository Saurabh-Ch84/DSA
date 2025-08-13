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


//my version
// Function to find the data of kth node from the end of a linked list.
class Solution {
    int findLen(Node *head){
        Node *temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
    
    int getKthFromFirst(Node *head,int k){
        Node *temp=head;
        while(k-->0 && temp)
            temp=temp->next;
        return temp->data;
    }
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int l=findLen(head);
        if(l<k) return -1;
        int k_=l-k;
        return getKthFromFirst(head,k_);
    }
};

int main(){

return 0;
}