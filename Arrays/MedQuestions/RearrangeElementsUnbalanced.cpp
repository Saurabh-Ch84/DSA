#include<iostream>
#include<vector>
using namespace std;

//AI's version
class Solution1 {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        for (int a : arr) {
            if (a >= 0) pos.push_back(a);
            else neg.push_back(a);
        }
        int n = pos.size(), m = neg.size();
        vector<int> res;
        int i = 0, j = 0;
        // Alternate as long as both available
        while (i < n && j < m) {
            res.push_back(pos[i++]);
            res.push_back(neg[j++]);
        }
        // Add leftovers
        while (i < n) res.push_back(pos[i++]);
        while (j < m) res.push_back(neg[j++]);
        arr = res;
    }
};


// User function template for C++
class Solution2 {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos,neg;
        for(int &a:arr){
            if(a>=0) pos.push_back(a);
            else neg.push_back(a);
        }
        
        int n=pos.size(),m=neg.size();
        vector<int> res(m+n);
        int left=0,rightP=0,rightN=0;
        while(left<n+m){
            if((rightP<n && left%2==0) || rightN>=m){
                res[left]=pos[rightP];
                rightP++;
            }
            else if((rightN<m && left%2!=0) || rightP>=n){
                res[left]=neg[rightN];
                rightN++;
            }
            left++;
        }
        arr=res;
    }
};

int main(){

return 0;
}