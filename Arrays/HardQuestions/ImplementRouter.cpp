#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Optimal
class Router1{
    long long hashPacket(int source, int destination, int timestamp){
        return (long long)source*1e10+(long long)destination*1e5+timestamp;
    }

    vector<int> evictOne(){
        vector<int> packet=q.front();
        q.pop();
        long long key=hashPacket(packet[0],packet[1],packet[2]);
        hashSet.erase(key);
        int destination=packet[1],timestamp=packet[2];
        deleteMap[destination].push_back(timestamp);
        memory++;
        return packet;
    }

    int countTimeStamps(vector<int> &vec,int startTime,int endTime){
        auto lb=lower_bound(vec.begin(),vec.end(),startTime);
        auto ub=upper_bound(vec.begin(),vec.end(),endTime);
        return distance(lb,ub); 
    }

    int memory;
    unordered_set<long long> hashSet;
    queue<vector<int>> q;
    unordered_map<int,vector<int>> hashMap;
    unordered_map<int,vector<int>> deleteMap;

public:
    Router1(int memoryLimit) {
        memory=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key=hashPacket(source,destination,timestamp);
        if(hashSet.insert(key).second==false) 
            return false;
        if(memory==0) evictOne();
        q.push({source,destination,timestamp});
        hashMap[destination].push_back(timestamp);
        memory--;
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        return evictOne();
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(hashMap.count(destination)==0) return 0;
        auto &vec=hashMap[destination];
        int total=countTimeStamps(vec,startTime,endTime);
        auto &vec_=deleteMap[destination];
        int deleted=countTimeStamps(vec_,startTime,endTime);
        int count=total-deleted;
        return count;
    }   
};

// Less Efficient
class Router2 {
    long long hashPacket(int source, int destination, int timestamp){
        return (long long)source*1e10+(long long)destination*1e5+timestamp;
    }

    vector<int> evictOne(){
        vector<int> packet=q.front();
        q.pop();
        long long key=hashPacket(packet[0],packet[1],packet[2]);
        hashSet.erase(key);
        int destination=packet[1],timestamp=packet[2];
        auto &vec=hashMap[destination];
        auto posItr=lower_bound(vec.begin(),vec.end(),timestamp);
        if(posItr!=vec.end() && *posItr==timestamp)
            vec.erase(posItr);
        memory++;
        return packet;
    }

    int memory;
    unordered_set<long long> hashSet;
    queue<vector<int>> q;
    unordered_map<int,vector<int>> hashMap;
public:
    Router2(int memoryLimit){
        memory=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key=hashPacket(source,destination,timestamp);
        if(hashSet.insert(key).second==false) 
            return false;
        if(memory==0) evictOne();
        q.push({source,destination,timestamp});
        auto &vec=hashMap[destination];
        vec.push_back(timestamp);
        memory--;
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        return evictOne();
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(hashMap.count(destination)==0) return 0;
        auto &vec=hashMap[destination];
        auto lb=lower_bound(vec.begin(),vec.end(),startTime);
        auto ub=upper_bound(vec.begin(),vec.end(),endTime);
        return distance(lb,ub);
    }
};

int main(){
    Router1 r1(4);
    cout<<r1.getCount(2,2,5)<<endl;
    r1.addPacket(1,2,1);
    r1.addPacket(3,4,2);
    r1.addPacket(1,2,1);
    r1.addPacket(4,2,3);
    r1.addPacket(1,3,3);
    r1.addPacket(1,3,6);
    cout<<r1.getCount(2,1,2)<<endl;

    r1.forwardPacket();
    cout<<r1.getCount(3,1,5)<<endl;
    r1.forwardPacket();
    cout<<r1.getCount(4,2,5)<<endl;
    r1.forwardPacket();
    cout<<r1.getCount(1,1,7)<<endl;
return 0;
}