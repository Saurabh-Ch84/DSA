#include<iostream>
#include<vector>
using namespace std;
using vi = vector<int> ;

//Optimal
class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans(n);
        int xorTotal=0;
        for(int i=0;i<n;i++){
            ans[i]=i+1;
            xorTotal=xorTotal^ans[i];
        }
        //no-removal
        if(xorTotal==n) return ans;
        //one-removal
        int numToDel=xorTotal^n;
        ans.erase(ans.begin()+(numToDel-1));
        return ans;
    }
};

//Brute
class Solution1 {
    void recursion(int i,int n,vi &temp,vi &ans,int totalXOR){
        if(i>n){
            if (totalXOR==n) {
                if(temp.size()>ans.size()) ans=temp;
                else if(temp.size()==ans.size()) ans=min(ans,temp);
            }
            return ;
        }
        //take
        temp.push_back(i);
        recursion(i+1,n,temp,ans,totalXOR^i);
        temp.pop_back();
        //notTake
        recursion(i+1,n,temp,ans,totalXOR);
    }
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans,temp;
        recursion(1,n,temp,ans,0);
        return ans;
    }
};


int main(){

return 0;
}