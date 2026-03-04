#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<bool> visited(high-low+1,false);
        for(int &a: arr){
            if(a<low || a>high) continue;
            visited[a-low]=true;
        }
        vector<int> result;
        int n=visited.size();
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            result.push_back(i+low);
        }
        return result;
    }
};

class Solution2 {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, result = 0;
        int n=s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                curr++; 
            } else {
                result += min(prev, curr);
                prev = curr;  // shift window
                curr = 1;     // reset for new group
            }
        }20Feb
        result += min(prev, curr); 
        return result;
    }
};


int main(){

return 0;
}