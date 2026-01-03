#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(), ptr=n-1, carry=1;
        vector<int> ans;
        while(carry || ptr>=0){
            int val=(ptr>=0)? digits[ptr--]:0;
            int d=(val+carry)%10;
            carry=(val+carry)/10;
            ans.push_back(d);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* ptr1=head1;
        Node* ptr2=head2;
        while(ptr1!=ptr2){
            ptr1=(ptr1)? ptr1->next:head2;
            ptr2=(ptr2)? ptr2->next:head1;
        }
        return ptr1;
    }
};

int main(){

return 0;
}