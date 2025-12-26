#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vi> ;
using vvb = vector<vb> ;
using vusi = vector<unordered_set<int>> ;

// You decided to create an automatic image recognizer that will determine the object
// in the image based on its contours. The main recognition system is already implemented,
// and now you need to start the teaching process.
// Today you want to teach your program to recognize butterfly patterns, which means
// that you need to implement a function that, given the adjacency matrix representing
// the contour, will determine whether it's a butterfly or not.
// The butterfly contour looks like this:
// https://codefightsuserpics.s3.amazonaws.com/tasks/isButterfly/img/butterfly.png?_tm=1495120253756
// Given the object's contour as an undirected graph represented by adjacency matrix adj
// determine whether it's a butterfly or not.
// Example:
//          For
//          adj = [[false, true, true, false, false],
//                 [true, false, true, false, false],
//                 [true, true, false, true, true],
//                 [false, false, true, false, true],
//                 [false, false, true, true, false]]
//          the output should be
//          isButterfly(adj) = true.
//          Here's what the given graph looks like:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/isButterfly/img/example1.png?_tm=1495120253905

bool isButterfly(vvb &adj){
    int n=adj.size();
    vusi adjList(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adj[i][j]){
                adjList[i].insert(j);
                adjList[j].insert(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(adjList[i].size()!=4) continue;
        unordered_set<int> &hashSet=adjList[i];
        bool flag=true;
        for(const int &j: hashSet){
            unordered_set<int> &tempSet=adjList[j];
            if(tempSet.size()!=2){
                flag=false;
                break;
            }
            for(const int &k: tempSet){
                if(k==i) continue;
                if(!hashSet.count(k)){
                    flag=false; 
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return true;
    }
    return false;
}

int main(){

return 0;
}