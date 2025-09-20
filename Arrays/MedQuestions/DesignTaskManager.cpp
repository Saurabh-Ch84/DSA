#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TaskManager{
private:
    struct Comp{
        bool operator()(const vector<int>&a,const vector<int>&b) const{
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        }
    };
    set<vector<int>,Comp> hashSet;
    unordered_map<int,pair<int,int>> hashMap;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int> &task:tasks){
            int userId=task[0],taskId=task[1],priority=task[2];
            hashMap[taskId]={priority,userId};
            hashSet.insert({priority,taskId,userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        hashSet.insert({priority,taskId,userId});
        hashMap[taskId]={priority,userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto &taskInfo=hashMap[taskId];
        int oldPriority=taskInfo.first;
        int userId=taskInfo.second;
        hashSet.erase({oldPriority,taskId,userId});
        hashSet.insert({newPriority,taskId,userId});
        taskInfo.first=newPriority;
    }
    
    void rmv(int taskId) {
        auto &taskInfo=hashMap[taskId];
        int priority=taskInfo.first;
        int userId=taskInfo.second;
        hashMap.erase(taskId);
        hashSet.erase({priority,taskId,userId});
    }
    
    int execTop(){
        if(hashSet.empty()) return -1;
        auto &entry=*hashSet.rbegin();
        int priority=entry[0],taskId=entry[1],userId=entry[2];
        hashSet.erase(entry);
        hashMap.erase(taskId);
        return userId;
    }
};

int main(){
    vector<vector<int>> tasks={{1,100,7},{4,103,2},{1,200,6},{2,300,4},{9,202,8},{3,400,10}};
    TaskManager *ts=new TaskManager(tasks);
    cout<<ts->execTop()<<endl;
    ts->edit(200,9);
    cout<<ts->execTop()<<endl;
    ts->rmv(202);
    cout<<ts->execTop()<<endl;
    ts->add(5,104,5);
    cout<<ts->execTop()<<endl;
    
    delete ts;
return 0;
}