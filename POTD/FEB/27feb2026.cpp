#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<unordered_set>

using namespace std;
using vi=std::vector<int>;
using vvi=std::vector<vi>;

// Brute-force
class Solution1 {
public:
    int minOperations(string s, int k) {
        int n=s.length(), zero=0, moves=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
        }

        queue<int> q;
        unordered_set<int> visitedSet;
        q.push(zero);

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int z=q.front(); q.pop();
                if(visitedSet.count(z)) continue;
                if(!z) return moves;
                visitedSet.insert(z);
                int fMin=max(0,k+z-n), fMax=min(k,z);
                for(int i=fMin;i<=fMax;i++){
                    int z_=z+k-2*i;
                    q.push(z_);
                }
            }
            moves++;
        }

        return -1;
    }
};

// optimal
class Solution2 {
public:
    int minOperations(string s, int k) {
        int n=s.length(), zero=0, moves=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
        }

        set<int> evenSet, oddSet;
        for(int i=0;i<=n;i++){
            if(i%2==0) evenSet.insert(i);
            else oddSet.insert(i);
        }
        
        queue<int> q;
        q.push(zero);
        if (zero % 2 == 0) evenSet.erase(zero);
        else oddSet.erase(zero);

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int z=q.front(); q.pop();
                if(!z) return moves;
                int fMin=max(0,k+z-n), fMax=min(k,z);
                int zMax=z+k-2*fMin, zMin=z+k-2*fMax;
                set<int> &set_=(zMin%2==0? evenSet: oddSet);
                set<int>::iterator itr=set_.lower_bound(zMin);
                while(itr!=set_.end() && *itr<=zMax){
                    int z_=*itr;
                    q.push(z_);
                    itr=set_.erase(itr);
                }
            }
            moves++;
        }

        return -1;
    }
};


class Solution3 {
    void create(vvi &mat,vvi &prefix,int n,int m){
        prefix.resize(n+1,vi(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int top=prefix[i-1][j];
                int left=prefix[i][j-1];
                int topLeft=prefix[i-1][j-1];
                prefix[i][j]=top+left-topLeft+mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1,int c1,int r2,int c2,vvi &prefix){
        return prefix[r2][c2]-prefix[r1][c2]-prefix[r2][c1]+prefix[r1][c1];
    }
    
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n=mat.size(), m=mat[0].size(), count=0;
        vvi prefix;
        create(mat,prefix,n,m);
        for(int size=1;size<=min(n,m);size++){
            for(int i=0;i<=n-size;i++){
                for(int j=0;j<=m-size;j++){
                    if(sumRegion(i,j,i+size,j+size,prefix)==x)
                        count++;
                }
            }
        }
        return count;
    }
};

int main(){

return 0;
}