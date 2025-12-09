#include<iostream>
#include<vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution{
    bool isValid(int row,int col,int n,int m,vvi &field,vvi &figure){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(figure[i][j]==1){
                    if(row+i>=n || field[row+i][col+j]==1)
                        return false;
                }
            }
        }
        return true;
    }
    bool isRowFull(int row,int col,int n,int m,vvi &field,vvi &figure){
        for(int i=0;i<3;i++){
            int currRow=row+i;
            if(currRow>=n) break;
            bool full=true;
            for(int j=0;j<m;j++){
                bool fieldCell=(field[currRow][j]==1);
                bool figureCell=(j-col>=0 && j-col<3)? figure[i][j-col]: false;
                if(!fieldCell && !figureCell){
                    full=false;
                    break;
                }
            }
            if(full) return true;
        }
        return false;
    }
        public:
    int tetrisDrop(vvi field, vvi figure){
        int n=field.size(),m=field[0].size();
        for(int j=0;j<m-3+1;j++){
            int row=-1;
            for(int i=0;i<n-3+1;i++){
                if(isValid(i,j,n,m,field,figure)) row=i;
                else break;
            }
            if(row!=-1){
                if(isRowFull(row,j,n,m,field,figure))
                    return j;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vvi field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {1, 0, 0},
        {1, 1, 0}
    };
    vvi figure = {
        {0, 0, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    
    // Expected Output: 0
    cout << s.tetrisDrop(field, figure) << endl; 

    vvi field2 = {
          {0, 0, 0, 0},
          {0, 0, 0, 0},
          {0, 0, 0, 0},
          {1, 0, 0, 1},
          {1, 1, 0, 1}
    };
    vvi figure2 = {
          {1, 1, 0},
          {1, 0, 0},
          {1, 0, 0}
    };
    
    // Expected Output: -1
    cout << s.tetrisDrop(field2, figure2) << endl; 

    // Field matrix
    vvi field3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };

    vvi figure3 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1}
    };

    cout<<s.tetrisDrop(field3,figure3)<<endl;
    return 0;
}