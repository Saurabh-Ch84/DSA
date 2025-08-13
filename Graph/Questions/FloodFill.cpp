#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void DFS(vector<vector<int>> &image,int r,int c,int color,int origColor,int n,int m)
    {
        if(r<0 || c<0 || r>=n || c>=m || image[r][c]!=origColor || image[r][c]==color) return;
        image[r][c]=color;
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(abs(dr)==abs(dc)) continue;
                DFS(image,r+dr,c+dc,color,origColor,n,m);
            }
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) 
    {
        // Code here
        int orignalColor=image[sr][sc];
        DFS(image,sr,sc,newColor,orignalColor,image.size(),image[0].size());
        return image;
    }
};

int main(){

return 0;
}