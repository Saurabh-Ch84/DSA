#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int> minX,maxX;
        unordered_map<int,int> minY, maxY;
        
        for(vector<int> &building: buildings){
        	int x=building[0],y=building[1];
        	minX[y]=min((minX[y])? minX[y]: INT_MAX,x);
        	maxX[y]=max((maxX[y])? maxX[y]: INT_MIN,x);
            
        	minY[x]=min((minY[x])? minY[x]:INT_MAX,y);
        	maxY[x]=max((maxY[x])? maxY[x]:INT_MIN,y);
        }
        int count=0;
		for(vector<int> &building: buildings){
    	    int x=building[0],y=building[1];
     		if(minX[y]<x && maxX[y]>x && minY[x]<y && maxY[x]>y)
    		   	count++;
	    }  		  
	    return count;    
    }
};

int main(){

return 0;
}