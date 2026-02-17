#include<iostream>
#include<vector>
using namespace std;
using vi=vector<int>;

class Solution {
    bool isBalanced(vi &arr,int maxF){
        for(int &f: arr)
            if(f && f!=maxF) return false;
        return true;
    }
public:
    int longestBalanced(string s) {
        int n=s.size(), maxi=1;
        for(int i=0;i<n;i++){
            vi arr(26,0);
            int maxF=0;
            for(int j=i;j<n;j++){
                arr[s[j]-'a']++;
                maxF=max(maxF,arr[s[j]-'a']);
                if(arr[s[j]-'a']==maxF && j-i+1>maxi && isBalanced(arr,maxF))
                    maxi=j-i+1;
            }
        }
        return maxi;
    }
};


int main(){

return 0;
}