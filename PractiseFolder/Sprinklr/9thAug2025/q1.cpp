#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

/*
Problem Statement:
    You are given a total of n courses, labeled from 0 to n-1. Some courses may require other courses to be completed first; these requirements are given as a list of prerequisite pairs [a, b], meaning you must complete course b before course a.
    You are also given a list of mandatory courses that you must complete.

Your task:
    Determine the minimum number of distinct courses you need to take (including prerequisites, direct or indirect) to be able to finish all the mandatory courses. If it is impossible to complete them due to cyclic dependencies in the prerequisites, return -1.

Input:
    An integer n — the total number of courses (0 to n-1).
    A list of prerequisite pairs, where each pair [a, b] means b must be taken before a.
    A list of courses that are mandatory to complete.

Output:
    The minimum number of courses you need to take, or -1 if impossible.
*/

class Solution{
    bool isCyclic(vector<vector<int>> &adjM,int V,vector<int> &inOrder){
        queue<int> q;
        for(int i=0;i<V;i++)
            if(inOrder[i]==0) q.push(i);
        vector<int> topoSort;
        while(!q.empty()){
            int nodeU=q.front();
            topoSort.push_back(nodeU);
            q.pop();
            for(int &nodeV:adjM[nodeU]){
                inOrder[nodeV]--;
                if(inOrder[nodeV]==0)
                    q.push(nodeV);
            }
        }
        return topoSort.size()!=V;
    }

    void DFS(vector<vector<int>> &adjM,int nodeU,unordered_set<int> &hashSet){
        hashSet.insert(nodeU);
        for(int &nodeV:adjM[nodeU]){
            if(hashSet.count(nodeV)==false)
                DFS(adjM,nodeV,hashSet);
        }
    }
        public:
    int findMinCourseToComplete(int &V,vector<vector<int>> &edges,vector<int> &arr){
        vector<vector<int>> adjM(V);
        vector<int> inOrder(V,0);
        for(vector<int> &edge:edges){
            adjM[edge[0]].push_back(edge[1]);
            inOrder[edge[1]]++;
        }
        if(isCyclic(adjM,V,inOrder)) return -1;
        unordered_set<int> hashSet;
        for(int &vertice:arr){
            if(hashSet.count(vertice)==false)
                DFS(adjM,vertice,hashSet);
        }
        int numberOfMandatoryCourses=hashSet.size();
        return numberOfMandatoryCourses;
    }
};

int main(){
    Solution s;
    int n1 = 4 ;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}} ; 
    vector<int> mandatory1 = {3};
    /*
    Explanation:
        To take 3, need 2; for 2, need 1; for 1, need 0.
    Courses needed: 
        {0,1,2,3}
    Expected Output:
        4
    */
    int n2 = 6 ;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 1}, {3, 1}, {4, 3}}  ; 
    vector<int> mandatory2 = {2,4};
    /*
    Explanation:
        To do 2: 0 → 1 → 2
        To do 4: 0 → 1 → 3 → 4
    Union of all courses: 
    {0,1,2,3,4}
    Expected Output:
    5
    */
    int n3 = 6 ;
    vector<vector<int>> prerequisites3 = {{1, 0},{5,4}} ; 
    vector<int> mandatory3 = {1,4};
    /*
    Explanation:
        To do 1: 0 → 1
        To do 4: just 4
    Courses:
        {0,1,4}
    Expected Output:
    3
    */
    int n4 = 3 ;
    vector<vector<int>> prerequisites4 = {{0, 1}, {1, 2}, {2, 0}} ; 
    vector<int> mandatory4 = {0};
    /*
        Explanation:
            There is a cycle: 
                0 → 1 → 2 → 0, so cannot complete course 0.
        Expected Output:
        -1
    */

    int n5 = 3 ;
    vector<vector<int>> prerequisites5 = {{1, 0}, {2, 0}} ; 
    vector<int> mandatory5 = {2};
    /*
    Explanation:
        To do 2, only prerequisite is 0.
    Courses: {0,2}
    Expected Output:
        2
    */

    int n6 = 8;
    vector<vector<int>> prerequisites6 = {
    {1, 0},    // 0 -> 1
    {2, 1},    // 1 -> 2
    {3, 1},    // 1 -> 3
    {4, 2},    // 2 -> 4
    {5, 3},    // 3 -> 5
    {6, 4},    // 4 -> 6
    {6, 5},    // 5 -> 6
    {7, 0},    // 0 -> 7
    {7, 5},    // 5 -> 7
};
vector<int> mandatory6 = {6, 7};

int n7 = 10;
vector<vector<int>> prerequisites7 = {
    {1, 0},   // 0 → 1
    {2, 1},   // 1 → 2
    {3, 1},   // 1 → 3
    {4, 2},   // 2 → 4
    {5, 3},   // 3 → 5
    {6, 4},   // 4 → 6
    {7, 5},   // 5 → 7
    {8, 6},   // 6 → 8   (deep chain branch 1)
    {8, 7},   // 7 → 8   (deep chain branch 2 merge)
    {9, 8},   // 8 → 9   (final target)
    {3, 6}    // **extra back edge to create cycle**: 6 → 3
};
vector<int> mandatory7 = {9};
   cout<<"Min Courses To Complete: "<<s.findMinCourseToComplete(n6,prerequisites6,mandatory6)<<endl;
return 0;
}