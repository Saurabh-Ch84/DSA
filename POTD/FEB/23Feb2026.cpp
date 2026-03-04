#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        unordered_set<string> hashSet;
        for(int i=0;i<n-k+1;i++){
            hashSet.insert(s.substr(i,k));
            if(hashSet.size()==(1<<k))
                return true;
        }
        return false;
    }
};

using vi=vector<int>;
class Solution2 {
    void selector(vi &arr,int p,vi &c,unordered_set<int> &hashSet){
        if(!hashSet.count(arr[p])){
            c.push_back(arr[p]);
            hashSet.insert(arr[p]);
        }
    }
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(), m=b.size(), i=0, j=0;
        unordered_set<int> hashSet;
        vi c;
        while(i<n && j<m){
            if(a[i]<b[j]){  
                selector(a,i++,c,hashSet);
            }
            else{
                selector(b,j++,c,hashSet);
            }
        }
        
        while(i<n){
            selector(a,i++,c,hashSet);
        }
        
        while(j<m){
            selector(b,j++,c,hashSet);
        }
        
        return c;
    }
};

int main(){

return 0;
}