#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> absDifOne(int n) {
        // code here
        vector<int> res;
        queue<int> q;
        for(int d=1;d<10;d++)
            q.push(d);
            
        while(!q.empty()){
            int currNum=q.front(); q.pop();
            if(currNum<=n && currNum>9) 
                res.push_back(currNum);
            int lastDigit=currNum%10;
            if(10LL*currNum<=n){
                if(lastDigit>0)
                    q.push(10LL*currNum+lastDigit-1);
                if(lastDigit<9) 
                    q.push(10LL*currNum+lastDigit+1);
            }
        }
        return res;
    }
};

int main(){

return 0;
}