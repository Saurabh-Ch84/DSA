#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
    string recursion(int i,int n,int &j,int k,string &temp){
        if(i==n){
            j=j+1;
            return (j==k ? temp: "");
        }
        for(char ch='a';ch<='c';ch++){
            if(temp.empty() || temp.back()!=ch){
                temp.push_back(ch);
                string next=recursion(i+1,n,j,k,temp);
                if(!next.empty()) return next;
                temp.pop_back();
            }
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        string temp;
        int j=0;
        return recursion(0,n,j,k,temp);
    }
};

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

using vint=vector<int>;
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        unordered_map<int,int> hashMap;
        hashMap[0]=root->data;
        int mini=INT_MAX;
        
        while(!q.empty()){
            pair<Node*,int> entry=q.front(); q.pop();
            mini=min(mini,entry.second);
            if(entry.first->left){
                q.push({entry.first->left,entry.second-1});
                if(!hashMap.count(entry.second-1))
                    hashMap[entry.second-1]=entry.first->left->data;
            }
            if(entry.first->right){
                q.push({entry.first->right,entry.second+1});
                if(!hashMap.count(entry.second+1)) 
                    hashMap[entry.second+1]=entry.first->right->data;
            }
        }
        
        int n=hashMap.size();
        vint result(n,-1);
        for(auto &p: hashMap){
            //normalize
            result[p.first-mini]=p.second;
        }
        return result;
    }
};

int main(){

return 0;
}