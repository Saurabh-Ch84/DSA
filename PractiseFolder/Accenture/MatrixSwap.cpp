#include<iostream>
#include<vector>
using namespace std;

/*
    1. Matrix Swap Problem 
        ○ Given a 5×5 binary matrix having only one 1. 
        ○ Find the minimum number of swaps required to bring the 1 to the center of the matrix. 
*/

int findMinSwaps(vector<vector<int>> &matrix,int n,int m){
    int i_=-1,j_=-1;
    bool coordinatesFound=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]){
                i_=i;
                j_=j;
                coordinatesFound=true;
                break;
            }
        }
        if(coordinatesFound)
            break;
    }
    // Manhattan distance
    int steps=abs(2-i_)+abs(2-j_);
    return steps;
}

int main(){
    int n=5,m=5;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    // I will assume that I don't know the exact coordinates and in one step I can swap  with 4 only neighbor cells.
    int i,j;
    cout<<"Enter row index and col index coordinates: ";
    cin>>i>>j;
    matrix[i][j]=1;

    int minSwaps=findMinSwaps(matrix,n,m);
    cout<<"MinSwaps required is :"<<minSwaps<<endl;
return 0;
}