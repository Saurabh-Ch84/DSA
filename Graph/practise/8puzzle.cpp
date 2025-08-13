#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution {
    vector<vector<int>> adjMatrix;
    
    void createAdjMatrix(int n,int m){
        vector<int> di={0,1};
        vector<int> dj={1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=i*m+j;
                for(int k=0;k<2;k++){
                    int newI=i+di[k],newJ=j+dj[k];
                    if(newI<n && newJ<m){
                        int v=newI*m+newJ;
                        adjMatrix[u].push_back(v);
                        adjMatrix[v].push_back(u);
                    }
                }
            }
        }
    }

    string parser(vector<vector<int>>& board){
        string state="";
        for(vector<int> &row:board)
        for(int &num:row)
        state+=to_string(num);
        return state;
    }
    
    int BFS(vector<vector<int>>& board,vector<vector<int>> &goal){
        
        string initialState=parser(board);
        string finalState=parser(goal);
        unordered_set<string> visited;
        queue<string> q;
        visited.insert(initialState);
        q.push(initialState);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string state=q.front();
                q.pop();
                int zerosIndex=state.find('0');
                if(state==finalState) return moves;
                for(int &neighbor:adjMatrix[zerosIndex]){
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

    Solution(int n,int m){
        adjMatrix.resize(n*m);
        createAdjMatrix(n,m);
    }
    int slidingPuzzle(vector<vector<int>>& board,vector<vector<int>> &goal) {
        int minMoves=BFS(board,goal);
        cout<<"Minimum Moves required to solve this puzzle is: "<<endl;
        return minMoves;
    }
};

int main(){
    int n=3,m=3;
    Solution s(n,m);
    vector<vector<int>> board1={{1, 2, 3},
                                {4, 6, 8},
                                {7, 5, 0}};
    
    vector<vector<int>> goal1={{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    
    vector<vector<int>> board2={{1, 2, 3},
                                {4, 6, 8},
                                {7, 5, 0}};

    vector<vector<int>> goal2={{1, 2, 3},
                                {4, 5, 6},
                                {0, 7, 8}};

    vector<vector<int>> board3={{1, 2, 3},
                                {4, 6, 8},
                                {7, 5, 0}};

    vector<vector<int>> goal3={{1, 2, 3},
                                {4, 6, 8},
                                {5, 7, 0}};

    cout<<s.slidingPuzzle(board1,goal1)<<endl;
    cout<<s.slidingPuzzle(board2,goal2)<<endl;
    cout<<s.slidingPuzzle(board3,goal3)<<endl;
return 0;
}