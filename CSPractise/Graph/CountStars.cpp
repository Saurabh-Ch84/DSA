#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vi> ;
using vvb = vector<vb> ;

// You decided to create an automatic image recognizer that will determine the object
// in the image based on its contours. The main recognition system is already implemented,
// and now you need to start the teaching process.
// Today you want to teach your program to recognize star patterns in the image of the night sky,
// which means that you need to implement a function that, given the adjacency matrix
// representing a number of contours in the sky, will find the number of stars in it.
// The graph representing some contour is cosidered to be a star if it is a tree
// of size 2 or if it is a tree of size k > 2 with one internal node(which is a tree root
// at the same time) and k - 1 leaves.
// Here is an example of some stars:
// https://codefightsuserpics.s3.amazonaws.com/tasks/countStars/img/stars.png?_tm=1490625770330
// Given the sky objects' contours as an undirected graph represented by its adjacency matrix adj,
// calculate the number of stars in it.
// Example:
//          For
//          adj = [[false, true, false, false, false],
//                 [true, false, false, false, false],
//                 [false, false, false, true, false],
//                 [false, false, true, false, false],
//                 [false, false, false, false, false]]
//          the output should be
//          countStars(adj) = 2.
//          Here's what the given graph looks like:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/countStars/img/example1.png?_tm=1490625770504

int countStars(vvb &adj){
    int n=adj.size(), count=0;
    vvi adjList(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adj[i][j]){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(!adjList[i].empty()) continue;
        int k=0;
        for(int &j: adjList[i]){    
            if(adjList[j].size()!=1 || adjList[j][0]!=i) 
                break;
            // prevents 2x counting.
            adjList[j].pop_back();
            k++;
        }
        if(adjList[i].size()==k) count++;
    }

    return count;
}

int main(){

return 0;
}