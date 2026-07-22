#include<vector>
using namespace std;

class Solution3 {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1);
        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result = result * (N - r + i) / i;
        }
        return static_cast<int>(result);
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dpMatrix(m,vector<int>(n,1));
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--){
                dpMatrix[i][j]=dpMatrix[i+1][j]+dpMatrix[i][j+1];
            }
        }
        return dpMatrix[0][0];
    }
};

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dpArray(n,1);
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--)
                dpArray[j]=dpArray[j]+dpArray[j+1];
        }
        return dpArray[0];
    }
};

int main(){
    return 0;
}