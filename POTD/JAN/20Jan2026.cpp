#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    string doc;
    stack<char>undone;
  public:
    Solution(){
        doc="";
    }
  
    void append(char x){
        // append x into document
        doc.push_back(x);
    }

    void undo(){
        // undo last change
        if(doc.empty()) return ;
        undone.push(doc.back());
        doc.pop_back();
    }

    void redo(){
        // redo changes
        if(undone.empty()) return ;
        doc.push_back(undone.top());
        undone.pop();
    }

    string read() {
        // read the document
        return doc;
    }
};


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            if(nums[i]==2) continue;
            int num=nums[i];
            for(int j=0;j<32;j++){
                if(num & (1<<j)){
                    continue;
                }else{
                    if (j == 0) break;
                    int k=j-1;
                    int mask=1<<k;
                    ans[i]=mask^num;
                    break;
                }
            }
        }

        return ans;
    }
};

int main(){

return 0;
}