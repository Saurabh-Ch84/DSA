#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution1 {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(capacity[i]<itemSize) continue;
            while(!s.empty() && capacity[s.top()]>capacity[i]) s.pop();
            if(s.empty()) s.push(i);
        }
        return (s.empty()? -1: s.top());
    }
};

class Solution2 {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size(), mini=1e8, idx=-1;
        for(int i=0;i<n;i++){
            if(capacity[i]<itemSize) continue;
            int offset=capacity[i]-itemSize;
            if(mini>offset){
                mini=offset;
                idx=i;
                if(!mini) break;
            }
        }
        return idx;
    }
};

int main(){

return 0;
}