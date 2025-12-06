#include<iostream>
#include<vector>
using namespace std;

/*

**Matrix Elements Sum**

After becoming famous, the CodeBots decided to move into a new building together. 
Each of the rooms has a different cost, and some of them are free, but there's a rumour 
that all the free rooms are haunted! Since the CodeBots are quite superstitious, they refuse 
to stay in any of the free rooms, or any of the rooms below any of the free rooms.

Given `matrix`, a rectangular matrix of integers, where each value represents the cost of the room,
your task is to return the total sum of all rooms that are suitable for the CodeBots 
(i.e., add up all the values that don't appear below a 0).

**Example:**

For  
```
matrix = [[0, 1, 1, 2],  
          [0, 5, 0, 0],  
          [2, 0, 3, 3]]
```

the output should be  
`matrixElementsSum(matrix) = 9`.

*/

int matrixElementsSum(vector<vector<int>> matrix){
    int rooms=0;
    int n=matrix.size(),m=matrix[0].size();
    vector<int> cols(m,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!matrix[i][j] && cols[j]==n)
                cols[j]=i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] && cols[j]>i)
                rooms+=matrix[i][j];
        }
    }
    return rooms;
}

int main(){ 
    vector<vector<int>> matrix = {{0, 1, 1, 2},  
          {0, 5, 0, 0},  
          {2, 0, 3, 3}};
    cout<<matrixElementsSum(matrix);
return 0;
}