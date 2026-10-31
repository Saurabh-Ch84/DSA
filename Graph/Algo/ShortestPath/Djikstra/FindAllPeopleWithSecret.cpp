#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vi> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;

// most optimal
class Solution {
	void Dijkstra(int src,vector<vector<vector<int>>> &adjList,vector<int> &knowTime){
		knowTime[src]=0;
		priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
		pq.push({0,src});
		while(!pq.empty()){
			vector<int> entry=pq.top(); pq.pop();
			int t=entry[0], person=entry[1];
			if(knowTime[person]<t) continue;
			for(auto &info: adjList[person]){
				int t_=info[0], person_=info[1];
				if(t_<t || knowTime[person_]<=t)
					continue;
				pq.push({t_,person_});
				knowTime[person_]=t_;
			}
		}
	}
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		vector<vector<vector<int>>> adjList(n);
		for(auto &meeting: meetings){
			int x=meeting[0], y=meeting[1], t=meeting[2];
			adjList[x].push_back({t,y});
			adjList[y].push_back({t,x});
		}
		
		adjList[0].push_back({0,firstPerson});
		vector<int> knowTime(n,1e9);
		Dijkstra(0,adjList,knowTime);
		
		vector<int> peopleKnows;
		for(int i=0;i<n;i++){
			if(knowTime[i]!=1e9)
				peopleKnows.push_back(i);
		}
		return peopleKnows;
    }
};

// optimal
class Solution {
    void BFS(vvpii &adjList,vi &knows,queue<pii> &q){
        while(!q.empty()){
            pii personU=q.front(); q.pop();
            int u=personU.first, t=personU.second;
            for(pii &personV: adjList[u]){
                int v=personV.first, t_=personV.second;
                if(t_<t || knows[v]<=t_) continue;
                knows[v]=t_;
                q.push({v,t_});
            }
        }
    }
    struct Comp{
        bool operator()(const vi &a,const vi &b){
            return a[2]<b[2];
        }
    };
public:
    vi findAllPeople(int n, vvi & meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),Comp());
        vvpii adjList(n);
        for(vi &meeting: meetings){
            int x=meeting[0];
            int y=meeting[1];
            int t=meeting[2];
            adjList[x].push_back({y,t});
            adjList[y].push_back({x,t});
        }

        vi knows(n,INT_MAX);
        knows[0]=0;
        knows[firstPerson]=0;

        queue<pii> q;
        q.push({0,0});
        q.push({firstPerson,0});
        BFS(adjList,knows,q);

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(knows[i]!=INT_MAX) ans.push_back(i) ;
        }
        return ans;
    }
};

// better
class Solution {
    void BFS(unordered_map<int,vi> &adjMap,vb &knows,queue<int> &q,unordered_set<int> &visited){
        while(!q.empty()){
            int personU=q.front();
            q.pop();
            for(int &personV: adjMap[personU]){
                if(knows[personV]) continue;
                if(visited.count(personV)) continue;
                knows[personV]=true;
                q.push(personV);
                visited.insert(personV);
            }
        }
    }
public:
    vi findAllPeople(int n, vvi & meetings, int firstPerson) {
        map<int,vpii> timeMeetingMap;
        for(vi &meeting: meetings){
            int x=meeting[0];
            int y=meeting[1];
            int t=meeting[2];
            timeMeetingMap[t].push_back({x,y});
        }
        vb knows(n,false);
        knows[0]=true;
        knows[firstPerson]=true;

        for(auto &time: timeMeetingMap){
            vpii &meeting=time.second;
            unordered_map<int,vi> adjMap;
            unordered_set<int> visited;
            queue<int> q;
            for(pii &meet: meeting){
                int personU=meet.first;
                int personV=meet.second;
                adjMap[personU].push_back(personV);
                adjMap[personV].push_back(personU);
                if(knows[personU] && !visited.count(personU)){
                    q.push(personU);
                    visited.insert(personU);
                }
                if(knows[personV] && !visited.count(personV)){
                    q.push(personV);
                    visited.insert(personV);
                }
            }
            BFS(adjMap,knows,q,visited);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(knows[i]) ans.push_back(i) ;
        }
        return ans;
    }
};

int main(){

return 0;
}