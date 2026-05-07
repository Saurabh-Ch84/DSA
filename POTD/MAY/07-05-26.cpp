#include<bits/stdc++.h>
using namespace std;

// Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};


class Solution {
    void inorder(Node *root,string &str){
        if(!root) return ;
        str=str+to_string(root->data)+",";
        inorder(root->left,str);
        inorder(root->right,str);
    }
    
    bool KMP(string &s,string &p){
        int m=p.size();
        vector<int> lps(m,0);
        int len=0, i=1;
        while(i<m){
            if(p[i]==p[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len) len=lps[len-1];
                else i++;
            }
        }
        int n=s.size(),j=0,k=0;
        while(k<n){
            if(s[k]==p[j]){
                k++;
                j++;
                if(j==m) return true;
            }
            else{
                if(j) j=lps[j-1];
                else k++;
            }
        }
        return false;
    }
  public:
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        string str1, str2;
        inorder(root1,str1);
        inorder(root2,str2);
        return KMP(str1,str2);
    }
};

class Solution {
    using vint=vector<int>;
    class DSU{
            public:
        vint size, parent, maxim;
        DSU(int n,vint &nums){
            maxim.resize(n);
            size.resize(n,1);
            parent.resize(n,-1);
            for(int i=0;i<n;i++){
                parent[i]=i;
                maxim[i]=nums[i];
            }
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
        void unionBySize(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return;
            if(size[U]>size[V]){
                parent[V]=U;
                maxim[U]=max(maxim[U],maxim[V]);
                size[U]+=size[V];
            }
            else{
                parent[U]=V;
                maxim[V]=max(maxim[V],maxim[U]);
                size[V]+=size[U];
            }
        }
    };
public:
    vector<int> maxValue(vector<int>& nums){
        int n=nums.size();
        DSU ds(n,nums);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ds.maxim[ds.find(st.top())]>nums[i]){
                ds.unionBySize(st.top(),i);
                st.pop();
            }
            st.push(i);
        }

        vint res;
        for(int i=0;i<n;i++){
            int r=ds.find(i);
            res.push_back(ds.maxim[r]);
        }
        return res;
    }
};

int main(){

return 0;
}