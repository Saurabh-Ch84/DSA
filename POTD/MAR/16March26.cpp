#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        set<int> hashSet;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sz=0;
                while(j-sz>=0 && j+sz<n && i+2*sz<m){
                    int sum=0, j1=j, j2=j, dir=1;
                    for(int r=i;r<=i+2*sz;r++){
                        sum+=grid[r][j1];
                        if(j1!=j2) sum+=grid[r][j2];
                        if(r==i+sz) dir=0;
                        if(dir){
                            j1++;
                            j2--;
                        } 
                        else{
                            j1--;
                            j2++;
                        }
                    }
                    hashSet.insert(sum);
                    // If the set grows larger than 3, kick out the smallest element!
                    if (hashSet.size() > 3)
                        hashSet.erase(hashSet.begin());
                    sz++;          
                }
            }
        }

        vector<int> result;
        set<int>::reverse_iterator itr=hashSet.rbegin();
        while(result.size()<3 && itr!=hashSet.rend()){
            result.push_back(*itr);
            itr++;
        }
        return result;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution_PathSum {
private:
    int count = 0;
    int target;
    unordered_map<long long, int> prefixSumMap;

    void dfs(TreeNode* node, long long currentPathSum) {
        if (!node) return;
        // 1. Update current path sum
        currentPathSum += node->val;
        // 2. Check if a valid path ends at this node
        if(prefixSumMap.count(currentPathSum - target))
            count += prefixSumMap[currentPathSum - target];
        // 3. Add current path sum to map for descendants
        prefixSumMap[currentPathSum]++;
        // 4. Recurse for children
        dfs(node->left, currentPathSum);
        dfs(node->right, currentPathSum);
        // 5. Backtrack: remove current path sum from map
        prefixSumMap[currentPathSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        prefixSumMap[0] = 1; // Base case for paths starting at the root
        dfs(root, 0);
        return count;
    }
};

int main(){

return 0;
}