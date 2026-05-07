#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using pintint=pair<int,int>;
    using memo_t=set<pintint>;
    
    class Robot{
        int x,y,z;
        string directions="NWSE";
            public:
        Robot(): x(0), y(0), z(0){}
        void turnLeft(){
            z=(z+1)%4;
        }
        void turnRight(){
            z=(z-1+4)%4;
        }
        pintint tryMove(){
            int x_=x, y_=y;
            if(z==0) y_=y_+1;
            else if(z==1) x_=x_-1;
            else if(z==2) y_=y_-1;
            else x_=x_+1;
            return {x_,y_};
        }
        int setCurrentPosition(pintint &pos){
            x=pos.first;
            y=pos.second;
            return x*x+y*y;
        }
    };
public:
    int robotSim(vint &commands,vvint &obstacles) {
        memo_t hashSet;
        for(vint &obstacle: obstacles)
            hashSet.insert({obstacle[0],obstacle[1]});
        
        Robot r;
        int maxi=0;
        for(int &command: commands){
            if(command==-1) r.turnRight();
            else if(command==-2) r.turnLeft();
            while(command>0){
                pintint pos=r.tryMove();
                if(hashSet.count(pos)) break;
                maxi=max(maxi,r.setCurrentPosition(pos));
                command--;
            }
        }
        return maxi;
    }
};

class Solution {
    class Node{
            public:
        Node *left,*right;
        int freq, id;
        char val;
        Node(int f,int i,char v='#'){
            freq=f, id=i, val=v;
            left=nullptr;
            right=nullptr;
        }
    };
    
    struct Comp{
        bool operator()(Node* a,Node *b) const{
            if(a->freq==b->freq)
                return a->id > b->id;
            return a->freq > b->freq;
        }
    };
    
    using vint=vector<int>;
    using vstr=vector<string>;
    using minHeap=priority_queue<Node*,vector<Node*>,Comp>;
    
    void DFS(Node* root,string &code,vstr &codes){
        if(!root->left && !root->right){
            codes.push_back(code);
            return ;
        }
        code.push_back('0');
        DFS(root->left,code,codes);
        code.pop_back();
        code.push_back('1');
        DFS(root->right,code,codes);
        code.pop_back();
    }
    
  public:
    vstr huffmanCodes(string &s,vint f) {
        // Code here
        int n=s.size();
        if(n==1) return {"0"};
        minHeap pq;
        for(int i=0;i<n;i++)
            pq.push(new Node(f[i],i,s[i]));
        
        while(pq.size()>1){
            Node* u=pq.top(); pq.pop();
            Node* v=pq.top(); pq.pop();
            Node* w=new Node(u->freq+v->freq,min(u->id,v->id));
            w->left=u;
            w->right=v;
            pq.push(w);
        }
        
        Node* root=pq.top();
        vstr codes;
        string code;
        DFS(root,code,codes);
        
        return codes;
    }
};

int main(){

return 0;
}