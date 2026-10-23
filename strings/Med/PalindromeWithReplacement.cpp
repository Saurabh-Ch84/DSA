#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isLowercaseAlpha(char ch){
        return (ch>='a' && ch<='z');
    }
    bool preprocessing(string &res,int n){
        int left=0, right=n-1;
        while(left<right){
            if(res[left]!='?' && res[right]!='?' && res[left]!=res[right]){
                return 0;
            }
            else if(isLowercaseAlpha(res[left])) res[right]=res[left]; 
            else if(isLowercaseAlpha(res[right])) res[left]=res[right];  
            left++;
            right--;
        }
        return 1;
    }
  public:
    int minimumSum(string &s) {
        // code here
        string res=s;
        int n=s.size();
        if(!preprocessing(res,n)) return -1;
        
        vector<int> leftAlpha(n,-1), rightAlpha(n,-1);
        char prefixAlpha=res[0];
        for(int i=1;i<n;i++){
            leftAlpha[i]=(isLowercaseAlpha(prefixAlpha) ? prefixAlpha-'a':-1);
            if(isLowercaseAlpha(res[i])) prefixAlpha=res[i];
        }
        char suffixAlpha=res[n-1]; 
        for(int i=n-2;i>=0;i--){
            rightAlpha[i]=(isLowercaseAlpha(suffixAlpha) ? suffixAlpha-'a':-1);
            if(isLowercaseAlpha(res[i])) suffixAlpha=res[i];
        }
        
        for(int i=0;i<n;i++){
            if(isLowercaseAlpha(res[i])) continue;
            int x=leftAlpha[i], y=rightAlpha[i];
            if(x==-1 && y==-1) res[i]='a';
            else if(x==-1 || y==-1){
                if(x==-1) res[i]='a'+y;
                else res[i]='a'+x;
            }
            else res[i]='a'+(x+y)/2;
        }
        
        int minScore=0;
        for(int i=0;i<n-1;i++){
            minScore=minScore+abs(res[i+1]-res[i]);
        }
        return minScore;
    }
};

int main(){

return 0;
}