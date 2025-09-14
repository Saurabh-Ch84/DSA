#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,-1),right(n,-1);
        
        if(dominoes[0]=='R')
            left[0]=0;
        if(dominoes[n-1]=='L')
            right[n-1]=n-1;

        for(int i=1;i<n;i++){
            char d=dominoes[i];
            if(d=='L') continue;
            else if(d=='R') left[i]=i;
            else left[i]=left[i-1];
        }

        for(int i=n-2;i>=0;i--){
            char d=dominoes[i];
            if(d=='R') continue;
            else if(d=='L') right[i]=i;
            else right[i]=right[i+1];
        }

        for(int i=0;i<n;i++){
            int l=left[i],r=right[i];
            if(l==-1 && r==-1) continue;
            else if(l==-1 || r==-1){
                if(l==-1) dominoes[i]='L';
                else dominoes[i]='R';
            }
            else{
                int dr=i-l,dl=r-i;
                if(dr<dl) dominoes[i]='R';
                else if(dl<dr) dominoes[i]='L';
            }
        }
        return dominoes;
    }
};

int main(){

return 0;
}