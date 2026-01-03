#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
    bool isMagicSquare(int i_,int j_,int n,vector<vector<int>>& grid){
        unordered_set<int> hashSet;
        vector<int> row(n,0);
        vector<int> col(n,0);
        int posDiagSum=0, negDiagSum=0;

        for(int i=i_;i<i_+n;i++){
            for(int j=j_;j<j_+n;j++){
                int val=grid[i][j];
                if(val>9 || val<1) 
                    return false;
                if(hashSet.count(val)) 
                    return false;
                hashSet.insert(val);
                row[i-i_]+=val;
                col[j-j_]+=val;
                if((i-i_)-(j-j_)==0) negDiagSum+=val;
                if((i-i_)+(j-j_)==2) posDiagSum+=val;
            }
        }
        for(int k=0;k<3;k++){
            if(row[k]!=15 || col[k]!=15)
                return false;
        }
        if(posDiagSum!=15 || negDiagSum!=15) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int count=0;
        for(int i=0;i<n-3+1;i++){
            for(int j=0;j<m-3+1;j++){
                if(isMagicSquare(i,j,3,grid))
                    count++;
            }
        }
        return count;
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
    Node* reverse(Node* head){
        Node* front=head;
        Node* curr=head;
        Node* prev=nullptr;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node* curr1=head1; 
        Node* curr2=head2;
        
        while(curr1 && curr1->data==0){
            curr1=curr1->next;
        }
        while(curr2 && curr2->data==0){
            curr2=curr2->next;
        }
        
        Node* revHead1=reverse(curr1);
        Node* revHead2=reverse(curr2);
        
        Node* ans=nullptr;
        Node* curr=nullptr;
        int carry=0;
        while(carry || revHead1 || revHead2){
            int val1=0,val2=0;
            if(revHead1){
                val1=revHead1->data;
                revHead1=revHead1->next;
            }
            if(revHead2){
                val2=revHead2->data;
                revHead2=revHead2->next;
            }
            int d=(val1+val2+carry)%10;
            carry=(val1+val2+carry)/10;
            Node* newNode=new Node(d);
            if(!ans){
                ans=newNode;
                curr=newNode;
            }
            else{
                curr->next=newNode;
                curr=newNode;
            }
        }
        
        Node* finalAns=reverse(ans);
        return finalAns;
    }
};

int main(){

return 0;
}