#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

using pii = pair<int,int> ;
using plli = pair<long long,int> ;
using vi = vector<int> ;
using vplli = vector<plli> ;
using vll = vector<long long> ;


// Optimal
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<plli,vplli,greater<plli>> pq;
        for(int i=0;i<n;i++)
            pq.push({0,i});
        
        vi meetingCount(n,0);
        for(vi &meeting: meetings){
            int start=meeting[0], end=meeting[1];

            vplli freeRooms;
            while(!pq.empty() && pq.top().first<=start){
                freeRooms.push_back(pq.top());
                pq.pop();
            }
            int roomIdx; 
            long long endTime;
            if(!freeRooms.empty()){
                roomIdx=freeRooms[0].second;
                for(plli &entry: freeRooms){
                    if(entry.second<roomIdx) roomIdx=entry.second;
                }
                endTime=end;
                for(plli &entry: freeRooms){
                    if(entry.second!=roomIdx) pq.push(entry);
                }
            }else{
                plli entry=pq.top(); pq.pop();
                roomIdx=entry.second;
                long long duration=end-start;
                endTime=entry.first+duration;
            }
            meetingCount[roomIdx]++;
            pq.push({endTime,roomIdx});
        }

        int maxMeetingCount=0, maxMeetingRoom=-1;
        for(int i=0;i<n;i++){
            if(meetingCount[i]>maxMeetingCount){
                maxMeetingCount=meetingCount[i];
                maxMeetingRoom=i;
            }
        }
        return maxMeetingRoom;
    }
};

//Brute
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        sort(meetings.begin(),meetings.end());
        vll lastAvailable(n,0);
        vi roomsUsedCount(n,0);

        for(vi &meet: meetings){
            int start=meet[0], end=meet[1];
            long long earliestFreeTime=LONG_LONG_MAX;
            int earliestFreeRoom=-1;
            bool flag=false;
            for(int i=0;i<n;i++){
                if(lastAvailable[i]>start){
                    if(earliestFreeTime>lastAvailable[i]){
                        earliestFreeTime=lastAvailable[i];
                        earliestFreeRoom=i;
                    }
                    continue;
                }
                lastAvailable[i]=1LL*end;
                roomsUsedCount[i]++;
                flag=true;
                break;
            }
            if(!flag){
                lastAvailable[earliestFreeRoom]+=1LL*(end-start);
                roomsUsedCount[earliestFreeRoom]++;
            }
        }

        int maxi=0, mostUsedRoom=-1;
        for(int i=0;i<n;i++){
            if(roomsUsedCount[i]>maxi){
                maxi=roomsUsedCount[i];
                mostUsedRoom=i;
            }
        }

        return mostUsedRoom;
    }
};

int main(){

return 0;
}