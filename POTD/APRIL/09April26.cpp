#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> c;
        int i=0, n=a.size();
        int j=0, m=b.size();
        
        while(i<n && j<m){
            if(a[i]==b[j]){
                if(c.empty() || c.back()!=a[i])
                    c.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]) i++;
            else j++;
        }
        return c;
    }
};

int main(){

return 0;
}