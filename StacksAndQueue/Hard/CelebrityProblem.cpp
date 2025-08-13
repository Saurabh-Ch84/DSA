#include<iostream>
#include<vector>
using namespace std;

//optimal solution
class Solution2 {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int top=0,bottom=n-1;
        while(top<bottom){
            if(mat[top][bottom]) top++;
            else if(mat[bottom][top]) bottom--;
            else top++,bottom--;
        }
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(mat[top][i]!=0 || mat[i][top]!=1) return -1;
        }
        return top;
    }
};

//Brute force solution
class Solution1 {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        vector<int> celebrity;
        for(int i=0;i<n;i++){
            int knowCount=0;
            for(int &person:mat[i]){
                if(person) knowCount++;
                if(knowCount>1) break;
            }
            if(knowCount==1) celebrity.push_back(i);
        }
        for(int &person:celebrity){
            int knownCount=0;
            for(vector<int> &know:mat)
                if(know[person]) knownCount++;
            if(knownCount==n) return person;
        }
        
        return -1;
    }
};

int main(){

return 0;
}