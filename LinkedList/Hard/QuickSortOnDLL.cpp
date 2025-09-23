#include<iostream>
using namespace std;

/* a Node of the doubly linked list */

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
    DLLNode* partition(DLLNode* low,DLLNode* high){
        DLLNode* pIdx=low;
        for(DLLNode* i=low;i!=high;i=i->next){
            if(i->data < high->data){
                swap(i->data,pIdx->data);
                pIdx=pIdx->next;
            }
        }
        swap(high->data,pIdx->data);
        return pIdx;
    }
    
    DLLNode* getTail(DLLNode* head){
        while(head && head->next)
            head=head->next;
        return head;
    }
    
    void quickSortRec(DLLNode* low,DLLNode* high){
        if(!low || low==high || low==high->next) return;
        DLLNode* pIdx=partition(low,high);
        if(pIdx && pIdx->prev)
            quickSortRec(low,pIdx->prev);
        if(pIdx && pIdx->next)
            quickSortRec(pIdx->next,high);
    }
    
  public:
    DLLNode* quickSort(DLLNode* head) {
        // Your code goes here
        DLLNode* tail=getTail(head);
        quickSortRec(head,tail);
        return head;
    }
};

int main(){
return 0;
}