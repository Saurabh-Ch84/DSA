#include<bits/stdc++.h>
using namespace std;

class ThroneInheritance1 {
    // brute force cause of slow insertion in birth.
    class Member{
            public:
        string name;
        vector<Member*> children;
        Member(string name):name(name){
            children.clear();
        }
        ~Member(){
            int n=children.size();
            for(int i=0;i<n;i++)
                delete children[i];
        }
    };
    bool insertion(Member* curr,string &parentName,string &childName){
        if(curr->name==parentName){
            curr->children.push_back(new Member(childName));
            return true;
        }
        vector<Member*> &myChildren=curr->children;
        for(auto &child: myChildren){
            bool isInserted=insertion(child,parentName,childName);
            if(isInserted) return true;
        }
        return false;
    }
    void traversal(Member* curr,vector<string> &order){
        if(!deathRegister.count(curr->name))
            order.push_back(curr->name);
        vector<Member*> &myChildren=curr->children;
        for(auto &child: myChildren)
            traversal(child,order);
    }
    unordered_set<string> deathRegister;
    Member *root;
public:
    ThroneInheritance1(string kingName) {
        root=new Member(kingName);
    }
    void birth(string parentName, string childName) {
        // It will give TLE for 1e5 births at max given in the constraints.
        Member* curr=root;
        insertion(curr,parentName,childName);
    }
    void death(string name) {
        deathRegister.insert(name);
    }
    vector<string> getInheritanceOrder() {
        Member* curr=root;
        vector<string> order;
        traversal(curr,order);
        return order;
    }
};


class ThroneInheritance2 {
    // optimal code.
    class Member{
            public:
        string name;
        vector<Member*> children;
        Member(string &name):name(name){
            children.clear();
        }
        ~Member(){
            int n=children.size();
            for(int i=0;i<n;i++)
                delete children[i];
        }
    };
    void traversal(Member* curr,vector<string> &order){
        if(!deathRegister.count(curr->name))
            order.push_back(curr->name);
        vector<Member*> &myChildren=curr->children;
        for(auto &child: myChildren)
            traversal(child,order);
    }
    unordered_map<string,Member*> parentsMap;
    unordered_set<string> deathRegister;
    Member *root;
public:
    ThroneInheritance2(string kingName) {
        root=new Member(kingName);
        // important to note down king as the root.
        parentsMap[kingName]=root;
    }
    void birth(string parentName, string childName) {
        // this is always guaranteed that input will always be in the right order.
        vector<Member*> &myChild=parentsMap[parentName]->children;
        Member *m=new Member(childName);
        myChild.push_back(m);
        parentsMap[childName]=m;
    }
    void death(string name) {
        deathRegister.insert(name);
    }
    vector<string> getInheritanceOrder(){
        // it will not cause any problem since at max 10 calls is guaranteed.
        vector<string> order;
        traversal(root,order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(){

return 0;
}