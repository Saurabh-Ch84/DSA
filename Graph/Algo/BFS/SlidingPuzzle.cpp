#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
    int BFS(vector<vector<int>>& board){
        unordered_map<int, vector<int>> adjMap = {
            {0, {1, 3}}, {1, {0, 2, 4}}, {2, {1, 5}},
            {3, {0, 4}}, {4, {1, 3, 5}}, {5, {2, 4}}
        };
        string goal="123450";
        string initialState="";
        unordered_set<string> visited;
        for(vector<int> &row:board){
            for(int &num:row)
                initialState+=to_string(num);
        }
        queue<string> q;
        q.push(initialState);
        visited.insert(initialState);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string state=q.front();
                q.pop();
                int zerosIndex=state.find('0');
                if(state==goal) return moves;
                for(int &neighbor:adjMap[zerosIndex]){
                    string newState=state;
                    swap(newState[neighbor],newState[zerosIndex]);
                    if(visited.count(newState)==0){
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int minMoves=BFS(board);
        return minMoves;
    }
};

int main(){

return 0;
}