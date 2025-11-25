#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> str;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                string num=string(1,board[i][j]);
                string row = num + "R" + to_string(i);
                string col = num + "C" + to_string(j);
                string box = num + "B" + to_string(i/3) + "_" + to_string(j/3);
                if (str.count(row) || str.count(col)|| str.count(box)) 
                    return false;
                str.insert(row);
                str.insert(col);
                str.insert(box);
            }
        }
        return true;
    }
};


int main(){

return 0;
}