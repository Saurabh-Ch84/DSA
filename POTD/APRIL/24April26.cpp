#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
        public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0, right=0, dash=0;
        for(const char &move: moves){
            if(move=='L') left++;
            else if(move=='R') right++;
            else dash++;
        }
        return max(left+dash-right,right+dash-left);
    }
};

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n=arr.size(), count=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(st.empty()){
                st.push(i);
                count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}