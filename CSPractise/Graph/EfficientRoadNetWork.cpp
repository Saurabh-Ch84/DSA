#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vi> ;
using vvb = vector<vb> ;

// Once upon a time, in a kingdom far, far away, there lived a king Byteasar III.
// As a smart and educated ruler, he did everything in his (unlimited) power to make
// every single system of his kingdom efficient. The king went down in history
// as a great road builder: during his reign a great number of roads were built,
// and the road system he created was the most efficient for those dark times.
// When you started to learn about Byteasar's III deeds in your history classes,
// the creeping doubt crawled into the back of your mind: what if the famous king
// wasn't so great after all? According to the most recent studies, there were n cities
// in the Byteasar's kingdom, which were connected by the two-ways roads.
// You managed to get information about this roads from the university library,
// so now you can write a function that will determine whether the road system
// in Byteasar's kingdom was efficient or not.
// A road system is considered efficient if it is possible to travel from any city
// to any other city by traversing at most 2 roads.
// Example:
//          For n = 6 and
//          roads = [[3, 0], [0, 4], [5, 0], [2, 1], [1, 4], [2, 3], [5, 2]]
//          the output should be
//          efficientRoadNetwork(n, roads) = true.
//          Here's how the road system can be represented:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/efficientRoadNetwork/img/example1.jpg?_tm=1530798811119
//
//          For n = 6 and
//          roads = [[0, 4], [5, 0], [2, 1], [1, 4], [2, 3], [5, 2]]
//          the output should be
//          efficientRoadNetwork(n, roads) = false.
//          Here's how the road system can be represented:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/efficientRoadNetwork/img/example2.jpg?_tm=1530798811365
//          As you can see, it's only possible to travel from city 3 to city 4
//          by traversing at least 3 roads.

bool efficientRoadNetwork(int n, vvi &roads){
    vvi dist(n,vi(n,5000));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }

    for(vi &road: roads){
        int u=road[0];
        int v=road[1];
        dist[u][v]=1;
        dist[v][u]=1;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]>2) return false;
        }
    }
    return true;
}

int main(){

return 0;
}