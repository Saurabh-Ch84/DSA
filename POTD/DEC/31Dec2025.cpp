#include<iostream>
#include<stack>
#include<vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    bool isValid(int i,int j,int row,int col){
        return (i<row && j<col && i>=0 && j>=0);
    }    
    bool DFS(int i,int j,int row,int col,vi &di,vi &dj,vvi &matrix){
        if(i==row-1) return true;
        matrix[i][j]=1;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_,row,col) || matrix[i_][j_])
                continue;
            bool nextAns=DFS(i_,j_,row,col,di,dj,matrix);
            if(nextAns) return true;
        }
        return false;
        
    }
    bool check(int mid,int row,int col,vvi &cells){
        vvi matrix(row,vi(col,0));
        for(int i=0;i<=mid;i++){
            int r=cells[i][0]-1, c=cells[i][1]-1;
            matrix[r][c]=1;
        }
        vi di={-1,0,1,0}, dj={0,1,0,-1};
        for(int j=0;j<col;j++){
            if(!matrix[0][j] && DFS(0,j,row,col,di,dj,matrix))
                return true;
        }
        return false;
    }
public:
    int latestDayToCross(int row,int col,vvi &cells) {
        int low=0, high=cells.size()-1, ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(mid,row,col,cells);
            if(response){
                low=mid+1;
                ans=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
       data = x;
       next = NULL;
    }
};

class Solution {
  public:
    bool isPalindrome(Node *head){
        stack<int> st;
        Node* curr=head;
        while(curr){
            st.push(curr->data);
            curr=curr->next;
        }
        Node* temp=head;
        int halfLen=st.size()/2;
        while(halfLen){
            halfLen--;
            if(temp->data!=st.top()) 
                return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

int main(){

return 0;
}