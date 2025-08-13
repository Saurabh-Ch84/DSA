#include<iostream>
#include<vector>
using namespace std;

//striver's version
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // Traverse from Left to Right
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        // Traverse Downwards
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // Traverse from Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse Upwards
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}


//my solution
class Solution {
    void leftRight(vector<vector<int>>& matrix,
                    vector<int> &result,int &left,int &right,int &top){
        for(int i=left;i<=right;i++)
            result.push_back(matrix[top][i]);
        top++;
    }
    void topBottom(vector<vector<int>>& matrix,
                    vector<int> &result,int &top,int &bottom,int &right){
        for(int i=top;i<=bottom;i++)
            result.push_back(matrix[i][right]);
        right--;
    }
    void rightLeft(vector<vector<int>>& matrix,
                    vector<int> &result,int &left,int &right,int &bottom){
        for(int i=right;i>=left;i--)
            result.push_back(matrix[bottom][i]);
        bottom--;
    }
    void bottomTop(vector<vector<int>>& matrix,
                    vector<int> &result,int &top,int &bottom,int &left){
        for(int i=bottom;i>=top;i--)
            result.push_back(matrix[i][left]);
        left++;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n=matrix.size(),m=matrix[0].size();
        int left=0,right=m-1,top=0,bottom=n-1;
        while(1){
            if(left>right) break;
            leftRight(matrix,result,left,right,top);
            if(top>bottom) break;
            topBottom(matrix,result,top,bottom,right);
            if(right<left) break;
            rightLeft(matrix,result,left,right,bottom);
            if(bottom<top) break;
            bottomTop(matrix,result,top,bottom,left);
        }
        return result;
    }
};

int main(){

return 0;
}