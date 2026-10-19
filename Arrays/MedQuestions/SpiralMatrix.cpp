#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;;

class Solution {
    const int marker = INT_MAX;
    bool isBoundary(int i, int j, int n, int m) {
        return (i<0 || j<0 || i>=n || j>=m);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vvi dir = {{0,1},{1,0},{0,-1},{-1,0}}; // right, down, left, up
        vi result;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0, d = 0; // start at (0,0), direction = right
        
        for (int step = 0; step < n*m; step++) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = marker; // mark visited
            
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            
            if (isBoundary(ni, nj, n, m) || matrix[ni][nj] == marker) {
                d = (d + 1) % 4; // change direction
                ni = i + dir[d][0];
                nj = j + dir[d][1];
            }
            i = ni;
            j = nj;
        }
        return result;
    }
};

class Solution {
    void leftRight(vvi &matrix,vi &result,int &left,int &right,int &top){
        for(int i=left;i<=right;i++)
            result.push_back(matrix[top][i]);
        top++;
    }
    void topBottom(vvi & matrix,vi &result,int &top,int &bottom,int &right){
        for(int i=top;i<=bottom;i++)
            result.push_back(matrix[i][right]);
        right--;
    }
    void rightLeft(vvi &matrix,vi &result,int &left,int &right,int &bottom){
        for(int i=right;i>=left;i--)
            result.push_back(matrix[bottom][i]);
        bottom--;
    }
    void bottomTop(vvi &matrix,vi &result,int &top,int &bottom,int &left){
        for(int i=bottom;i>=top;i--)
            result.push_back(matrix[i][left]);
        left++;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vi result;
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

class Solution {
    bool isValid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), visited=-1e8; 
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});

        vector<int> res;
        while(!q.empty()){
            auto entry=q.front(); q.pop();
            int i=get<0>(entry), j=get<1>(entry), k=get<2>(entry);
            res.push_back(matrix[i][j]);
            matrix[i][j]=visited;
            int numberOfTurnsTaken=0;
            while(numberOfTurnsTaken<2){
                int ii=i+dir[k][0], jj=j+dir[k][1];
                if(isValid(ii,jj,m,n) && matrix[ii][jj]!=visited){
                    q.push({ii,jj,k});
                    break;
                }
                else{
                    k=(k+1)%4;
                    numberOfTurnsTaken++;
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}