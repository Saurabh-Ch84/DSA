#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n=num.size(), leftSum=0, rightSum=0;
        int left=0, right=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?') left++;
                else leftSum=leftSum+(num[i]-'0');
            }
            else{
                if(num[i]=='?') right++;
                else rightSum=rightSum+(num[i]-'0');
            }
        }
        if((left+right)%2==1) return 1;
        return !(2*leftSum+9*left==2*rightSum+9*right);
    }
};

int main(){

return 0;
}