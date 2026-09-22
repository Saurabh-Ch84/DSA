#include<bits/stdc++.h>
using namespace std;

class SolutionBrute {
    class PrefixSum2D{
        vector<vector<int>> prefixSum;
    public:
        PrefixSum2D(vector<vector<char>> &mat){
            int n = mat.size();
            prefixSum.resize(n, vector<int>(n, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    prefixSum[i][j] = (mat[i][j] == 'X' ? 1 : 0)
                        + (i ? prefixSum[i - 1][j] : 0)
                        + (j ? prefixSum[i][j - 1] : 0)
                        - ((i && j) ? prefixSum[i - 1][j - 1] : 0);
                }
            }
        }
        int rangeSumQuery(int i1, int j1, int i2, int j2){
            return prefixSum[i2][j2]
                   - (i1 ? prefixSum[i1 - 1][j2] : 0)
                   - (j1 ? prefixSum[i2][j1 - 1] : 0)
                   + ((i1 && j1) ? prefixSum[i1 - 1][j1 - 1] : 0);
        }
    };
    bool isValid(int i, int j, int n){
        return (i < n && j < n && i >= 0 && j >= 0);
    }
public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        PrefixSum2D ps2d(mat);

        // Outermost loop: Check largest possible side lengths first
        for(int sideLen = n; sideLen >= 1; sideLen--){
            // Inner loops: Anchor the top-left corner
            // We only need to iterate up to n - sideLen to prevent out-of-bounds
            for(int i = 0; i <= n - sideLen; i++){
                for(int j = 0; j <= n - sideLen; j++){
                    if(mat[i][j] == 'O') continue;
                    int i1 = i, j1 = j, i2 = i + sideLen - 1, j2 = j + sideLen - 1;
                    int outerSquare = ps2d.rangeSumQuery(i1, j1, i2, j2);
                    int innerSquare = 0;
                    int ii1 = i1 + 1, jj1 = j1 + 1, ii2 = i2 - 1, jj2 = j2 - 1;
                    if(isValid(ii1, jj1, n) && isValid(ii2, jj2, n)){
                        innerSquare = ps2d.rangeSumQuery(ii1, jj1, ii2, jj2);
                    }
                    int countOfX = outerSquare - innerSquare;
                    // The moment we find a valid square, we exit. 
                    if(countOfX >= 4 * (sideLen - 1)) return sideLen; 
                }
            }
        }
        return 0;
    }
};

class SolutionOptimal {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> down(n,vector<int>(n,0)), right(n,vector<int>(n,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]=='O') continue;
                right[i][j]=1+(j+1<n? right[i][j+1]:0);
                down[i][j]=1+(i+1<n? down[i+1][j]:0);
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int maxSide=min(down[i][j],right[i][j]);
                for(int k=maxSide;k>maxi;k--){
                    int bottom=i+k-1, rightCol=j+k-1;
                    if(right[bottom][j]>=k && down[i][rightCol]>=k){
                        maxi=k;
                        break;
                    }
                }
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}