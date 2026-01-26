#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n=s.length();
        if(k>=n) return "0";
        string str;
        
        for(int i=0;i<n;i++){
            while(!str.empty() && str.back()>s[i] && k){
                str.pop_back();
                k--;
            }
            str.push_back(s[i]);
        }
        
        while(k && !str.empty()){
            str.pop_back();
            k--;
        }
        
        if(str[0]=='0'){
            string temp=str;
            reverse(temp.begin(),temp.end());
            while(temp.size()>1 && temp.back()=='0') 
                temp.pop_back();
            reverse(temp.begin(),temp.end());
            str=temp;
        }
        return str;
    }
};

using vi=vector<int>;
using vvi=vector<vi>;

class Solution {
    void compute(int n,int m,vvi &mat,vvi &prefix){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j]=mat[i][j] + (i? prefix[i-1][j]:0)+
                            (j? prefix[i][j-1]:0)-(i && j ? prefix[i-1][j-1]:0);
                
            }
        }
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m=mat[0].size();
        vvi prefix(n,vi(m,0));
        compute(n,m,mat,prefix);

        int maxi=0, offset=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int w=m-j, h=n-i;
                for(int k=offset;k<min(w,h);k++){
                    int i_=i+k, j_=j+k;
                    int sum=prefix[i_][j_]-(j? prefix[i_][j-1]:0)-
                            (i? prefix[i-1][j_]:0)+(i && j ? prefix[i-1][j-1]:0);
                    if(sum<=threshold){
                        offset=max(offset,k);
                        maxi=max(maxi,k+1);
                    }
                    else break;
                }
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}