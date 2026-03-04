#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution1 {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int xorAns=0, left=0, right=0;
        int maxi=0;
        while(right<n){
            xorAns=xorAns^arr[right];
            if(right-left+1==k){
                maxi=max(maxi,xorAns);
                xorAns=xorAns^arr[left++];
            }
            right++;
        }
        
        return maxi;
    }
};

class Solution2 {
public:
    int numSpecial(vector<vector<int>>& mat) {
    	int n=mat.size(), m=mat[0].size(), r=0, count=0;
    	unordered_set<int> rowSet, colSet;
    	
    	while(r<n){
    		if(rowSet.count(r)){
    			r++;
    			continue;
    		}
    		
    		int c=0;
    		while(c<m){
    			if(!mat[r][c] || colSet.count(c)){
    				c++;
    				continue;
    			}
    			
    			rowSet.insert(r);
    			colSet.insert(c);
    			
        		int ones=0;
    			for(int i=0;i<n;i++){
    				if(mat[i][c]){
    					ones++;
    					rowSet.insert(i);
    				}		
    			}
    			
    			for(int j=0;j<m;j++){
    				if(mat[r][j]){
    					ones++;
    					colSet.insert(j);
    				}		
    			}
    			
    			if(ones==2) count++;
    			break;			
    		}
    		r++;
    	}
    	return count;
    }
};

int main(){

return 0;
}