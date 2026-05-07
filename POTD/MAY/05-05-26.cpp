#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int getLength(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=getLength(head);
        k=k%len;
        if(!k) return head;
        int k_=len-k;
        ListNode* curr=head, *newHead, *prev;
        while(curr->next){
            if(k_>0) prev=curr;
            curr=curr->next;
            k_--;
        }
        newHead=prev->next;
        prev->next=nullptr;
        curr->next=head;
        return newHead;
    }
};

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        for(int bit=0; bit<32; bit++){
            long long set=0, unset=0;
            for(int i=0; i<n; i++){
                if(arr[i] & (1<<bit)) set++;
                else unset++;
            }
            sum+=set*unset*(1LL<<bit);
        }
        return sum;
    }
};

int main(){

return 0;
}