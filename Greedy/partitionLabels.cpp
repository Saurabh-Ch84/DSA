#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> arr(26,0);
        for(int i=0;i<n;i++)
            arr[s[i]-'a']=i;

        vector<int> res;
        int left=0,right=0;
        for(int i=0;i<n;i++){
            right=max(right,arr[s[i]-'a']);
            if(i==right){
                res.push_back(right-left+1);
                left=i+1;
            }
        }
        return res;
    }
};

int main(){

return 0;
}