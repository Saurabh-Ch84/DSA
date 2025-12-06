#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size(),m=boxGrid[0].size();
        vector<vector<char>> matrix(m,vector<char>(n));

        for(int i=0;i<n;i++){
            int ptr=m;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j]=='.'){
                    if(ptr==m) ptr=j;
                    else continue;
                }
                else if(boxGrid[i][j]=='*') ptr=m;
                else{
                    if(ptr!=m && ptr>=0){
                        boxGrid[i][ptr]='#';
                        boxGrid[i][j]='.';
                        ptr-=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=boxGrid[i][j];
                matrix[j][abs(n-1-i)]=ch;
            }
        }
        return matrix;
    }
};

int main(){

return 0;
}