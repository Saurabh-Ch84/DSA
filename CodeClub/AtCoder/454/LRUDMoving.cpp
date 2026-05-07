#include<iostream>
#include<vector>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
class Solution{
    vvint matrix;
    int N, A, B;
    bool isValid(int i,int j){
        return (i<N && j<N && i>=0 && j>=0 && !(i==A && j==B));
    }

    bool DFS(int i,int j,int m,vint &di,vint &dj,string &dir,string &temp,vvint &visited){
        if(i==N-1 && j==N-1) return (!m);
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_) || visited[i_][j_])
                continue;
            temp.push_back(dir[k]);
            bool nextAns=DFS(i_,j_,m-1,di,dj,dir,temp,visited);
            if(nextAns) return nextAns;
            temp.pop_back();
        }
        visited[i][j]=0;
        return false;
    }
        public:
    Solution(int N,int A,int B): N(N),A(A-1),B(B-1){
        matrix.resize(N);
        for(int j=0;j<N;j++){
            matrix[j].resize(N);
        }
    }
    string findAns(){
        vvint visited(N,vint(N,0));
        int m=N*N-2;
        vint di={0,0,-1,1}, dj={-1,1,0,0};
        string dir="LRUD", temp;
        return (DFS(0,0,m,di,dj,dir,temp,visited)? temp: "No");
    }
};

int main(){
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N, A, B;
        cin >> N >> A >> B;
        Solution s(N,A,B);
        cout<<s.findAns()<<endl;
    }
return 0;
}