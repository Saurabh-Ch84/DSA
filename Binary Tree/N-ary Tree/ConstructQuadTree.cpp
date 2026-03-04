#include<iostream>
#include<vector>
using namespace std;

// Definition for a QuadTree node.

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

using vi=vector<int>;
using vvi=vector<vi>;
using pbb=pair<bool,bool>;

class Solution {
    pair<bool,bool> isLeaf(vvi &grid,int firstRow,int firstCol,int lastRow,int lastCol){
        bool val=grid[firstRow][firstCol];
        for(int i=firstRow;i<=lastRow;i++){
            for(int j=firstCol;j<=lastCol;j++){
                if(grid[i][j]!=val)
                    return {val,false};
            }
        }
        return {val,true};
    }

    Node* makeTree(vvi &grid,int firstRow,int firstCol,int lastRow,int lastCol){  
        auto resp=isLeaf(grid,firstRow,firstCol,lastRow,lastCol);
        Node* node=new Node(resp.first,resp.second);
        if(!resp.second){
            int midRow=(firstRow+lastRow)/2, midCol=(firstCol+lastCol)/2;
            node->topLeft=makeTree(grid,firstRow,firstCol,midRow,midCol);
            node->topRight=makeTree(grid,firstRow,midCol+1,midRow,lastCol);
            node->bottomLeft=makeTree(grid,midRow+1,firstCol,lastRow,midCol);
            node->bottomRight=makeTree(grid,midRow+1,midCol+1,lastRow,lastCol);
        }
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        return makeTree(grid,0,0,n-1,m-1);
    }
};

int main(){

return 0;
}