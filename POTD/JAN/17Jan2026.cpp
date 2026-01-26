#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    bool isOperator(char ch){
        return (ch=='+' || ch=='-' || ch=='/' || ch=='*');
    }
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<bool> st;
        for(char ch: s){
            if(ch=='(')
                st.push(false);
            else if(isOperator(ch)){
                if(st.empty()) continue;
                st.pop();
                st.push(true);
            }
            else if(ch==')'){
                if(st.empty() || !st.top())
                    return true;
                st.pop();
            }
            else continue;
        }
        return false;
    }
};

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=topRight.size();
        long long maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int x1=max(bottomLeft[i][0],bottomLeft[j][0]);
                int x2=min(topRight[i][0],topRight[j][0]);

                int y1=max(bottomLeft[i][1],bottomLeft[j][1]);
                int y2=min(topRight[i][1],topRight[j][1]);

                if(x2>x1 && y2>y1){
                    int w=x2-x1, h=y2-y1;
                    int side=min(w,h);
                    maxi=max(maxi,1LL*side*side);
                }
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}