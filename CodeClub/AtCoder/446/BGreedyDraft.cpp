#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;

vi greedyDraft(int n,int m,vvi wishLists){
    vi juices(m,1), result(n,0);
    for(int i=0;i<n;i++){
        int k=wishLists[i].size();
        for(int j=0;j<k;j++){
            int juice=wishLists[i][j];
            if(juice<=m && juices[juice-1]){
                //1-based
                result[i]=juice;
                juices[juice-1]=0;
                break;
            }
        }
    }
    return result;
}

int main(){

return 0;
}