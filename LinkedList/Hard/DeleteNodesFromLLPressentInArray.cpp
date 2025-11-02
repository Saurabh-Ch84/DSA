#include<iostream>
#include<unordered_set>
#include<vector>
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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashSet(nums.begin(),nums.end());

        ListNode dummy(-1);
        ListNode *prev=&dummy,*curr=head;

        while(curr){
            int val=curr->val;
            if(hashSet.count(val)){
                curr=curr->next;
                prev->next=curr;
            }
            else{
                prev->next=curr;
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};

int main(){

return 0;
}