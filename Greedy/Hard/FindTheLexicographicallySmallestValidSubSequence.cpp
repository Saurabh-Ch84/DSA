#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<int> last(n2,-1); // helps in greedy logic.
        int i=n1-1, j=n2-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
            i--;
        }
        i=0, j=0;
        bool flag=false;
        vector<int> res;
        while(i<n1 && j<n2){
            if(word1[i]==word2[j]){
                res.push_back(i);
                j++;
            }
            else if(!flag && (j==n2-1 || i<last[j+1])){
                // possible, it's almost equal
                res.push_back(i);
                j++;
                flag=true;
                // no further almost equal allowed.
            }
            i++;
        }
        if(j==n2) return res;
        return {};
    }
};

int main(){

return 0;
}