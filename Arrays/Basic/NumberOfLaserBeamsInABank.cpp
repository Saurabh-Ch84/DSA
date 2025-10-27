#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0,totalBeams=0,n=bank[0].length();

        for(string &row: bank){
            int curr=0;
            for(int i=0;i<n;i++) if(row[i]=='1') curr++;
            totalBeams+=curr*prev;
            if(curr) prev=curr;
        }
        
        return totalBeams;
    }
};

int main(){

return 0;
}