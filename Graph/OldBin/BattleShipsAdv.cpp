#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    Battleships
    Problem Description
    Battleships is a game played on a rectangular board. You are given a representation of such a board of size N (height) x M (width) with information about the locations of the ships.

    The board is given as an array B, whose every element is a string that corresponds to one row of the game board. Each character of each string represents a cell of the board and is either:

    a '#' character, marking a part of a ship; or
    a '.' character, representing an empty cell.
    Two cells that share a side and have a value of '#' are parts of the same ship. Cell (X, Y) shares a side with cells (X, Y-1), (X, Y+1), (X-1, Y) and (X+1, Y).

    In the Battleships game there are three types of ships:

    Patrol Boats of size 1:

    A single cell (e.g., #).

    Submarines of size 2, which come in two shapes:

    Horizontal: ##
    Vertical: #
              #

    Destroyers of size 3, which come in six shapes:

    Horizontal: ###
    Vertical: #
              #
              #
              
    L-shape 1 (top-left 2x2 with bottom-right missing): ##
                                                        #

    L-shape 2 (top-left 2x2 with bottom-left missing): ##
                                                        #
    L-shape 3 (top-left 2x2 with top-right missing): #
                                                     ##

    L-shape 4 (top-left 2x2 with top-left missing):  #
                                                    ##

    Your task is to find the number of ships of each type occurring on the board.

    For example, on the board represented by B = [".,##.,.", "#.,#.#", ".##.#." ], there are two patrol boats, one submarine, and two destroyers. The visual representation of this board with identified ship types (D for Destroyer, S for Submarine, P for Patrol Boat) is:

    D D . P
    D D . P
    D S S .
    D . . .

    Write a function:

class Solution {
public:
    vector solution(vector& B);
};

    that, given an array B consisting of N strings of length M each, returns an array R of three Integers, such that:

    R[0] represents the number of Patrol Boats.
    R[1] represents the number of Submarines.
    R[2] represents the number of Destroyers.
    In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

    Examples

Example 1:
    Input: B = [".,##.,.", "#.,#.#", ".##.#." ]
    Output: [2, 1, 2]
    Explanation: As explained above, this board contains two Patrol Boats, one Submarine, and two Destroyers.

Example 2:
    Input: B = ["...", "#.#", "#.#"]
    Output: [1, 1, 1]

Example 3:
    Input: B = [".##", "...", ".##"]
    Output: [0, 0, 2]

Example 4:
    Input: B = ["...", "...", "..."]
    Output: [0, 0, 0]

Constraints
    N is an integer within the range [1..100].
    All strings in B are of the same length M from the range [1..100].
*/

class Solution {
    void init(unordered_set<string> &hashSet1,unordered_set<string> &hashSet2,unordered_set<string> &hashSet3){
        hashSet1.insert("S");
        hashSet2.insert({"SR","SD"});
        hashSet3.insert({"SRR","SDD","SRD","SDR","SDL"});
    }

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void DFS(vector<string>& board,int i,int j,int n,int m,string &path){
        vector<int> di={0,1,0},dj={1,0,-1}; // Right,Down,Left, Up not needed
        string moves="RDL";
        board[i][j]='.';
        for(int k=0;k<3;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || board[i_][j_]=='.')
                continue;
            path.push_back(moves[k]);
            DFS(board,i_,j_,n,m,path);
        }
    }
public:
    vector<int> findShips(vector<string>& board){
        unordered_set<string> hashSet1,hashSet2,hashSet3;
        init(hashSet1,hashSet2,hashSet3);
        int n=board.size(),m=board[0].length();

        int patrol=0,submarine=0,destroyer=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    string path="S";
                    DFS(board,i,j,n,m,path);
                    if(path.length()==1 && hashSet1.count(path))
                        patrol++;
                    else if(path.length()==2 && hashSet2.count(path))
                        submarine++;
                    else if(path.length()==3 && hashSet3.count(path))
                        destroyer++;
                }
            }
        }
        return {patrol,submarine,destroyer};
    };
};

void print(vector<int> arr){
    for(int &e:arr)
        cout<<e<<" ";
    cout<<endl;
}

int main(){
    Solution s;
    vector<string> board1 ={"...", "#.#", "#.#"};
    
    vector<string> board2 = {".##", "...", ".##"};
   
    vector<string> board3 = {"...", "...", "..."};

    vector<string> board4 = {
    "#..##",
    ".#...",
    ".#...",
    "...##",
    "...#."
    };

    print(s.findShips(board1));
    print(s.findShips(board2));
    print(s.findShips(board3));
    print(s.findShips(board4));
return 0;
}