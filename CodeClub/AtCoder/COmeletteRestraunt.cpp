#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using vi=vector<int>;

int leftOverEggs(int n,int d,vi A,vi B){
    queue<int> q;
    for(int i=0;i<n;i++){
        //Action-A
        q.push(A[i]);
        //Action-B
        int b=B[i];
        while(b && !q.empty()){
            if(q.front()>b){
                q.front()-=b;
                b=0;
            }
            else{
                b-=q.front();
                q.pop();
            }
        }
        //Action-C
        while(q.size()>d) q.pop();
    }

    int eggsLeft=0;
    while(!q.empty()){
        eggsLeft+=q.front();
        q.pop();
    }
    return eggsLeft;
}

int main(){
    cout<<leftOverEggs(3,1,{7,2,3},{1,3,2})<<endl;
    cout<<leftOverEggs(3,2,{7,2,3},{1,3,2})<<endl;
    cout<<leftOverEggs(2,1,{2,1},{1,2})<<endl;
return 0;
}