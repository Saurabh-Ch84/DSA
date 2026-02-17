#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution1 {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size(), miniDiff=INT_MAX;
        sort(a.begin(),a.end());
        for(int i=0;i<n-m+1;i++){
            int mini=a[i], maxi=a[i+m-1];
            int diff=maxi-mini;
            miniDiff=min(miniDiff,diff);
        }
        return miniDiff;
    }
};

class Solution2 {
public:
    string addBinary(string a, string b) {
        string c;
        int n=a.size(), m=b.size(), carry=0;
        int i=n-1, j=m-1;
        while(i>=0 || j>=0 || carry){
        	int valA=(i>=0? a[i--]-'0':0);
        	int valB=(j>=0? b[j--]-'0':0);
        	int total=valA+valB+carry;
        	int bit=total%2;
        	carry=total/2;
        	c.push_back(bit+'0');
        }
        reverse(c.begin(),c.end());
        return c;
    }
};

int main(){

return 0;
}