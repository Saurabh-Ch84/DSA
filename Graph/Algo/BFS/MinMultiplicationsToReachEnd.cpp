#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// User function Template for C++

class Solution {
    int fun(vector<int> &arr,int start,int end){
        vector<int> distance(1e5,1e9);
        distance[start]=0;
        queue<int> q;
        q.push(start);
        int step=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                if(node==end) return step;
                for(int &ele:arr){
                    int num=ele*node%100000;
                    if(distance[num]>step+1){
                        distance[num]=step+1;
                        q.push(num);
                    }
                }
            }
            step++;
        }
        return (distance[end]==1e9)?-1:distance[end];
    }
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        return fun(arr,start,end);
    }
};


int main(){

return 0;
}