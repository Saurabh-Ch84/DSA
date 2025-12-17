#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class Solution {
    struct Comp{
        bool operator()(const vector<string> &a, const vector<string> &b){
            if(a[1]!=b[1]){
                // needed to convert to int for correct comparison.
                int tA=stoi(a[1]);
                int tB=stoi(b[1]);
                return tA<tB;
            }
            return a[0]>b[0];
        }
    };
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),Comp());
        vector<int> mentions(numberOfUsers,0);

        int allCount=0;
        // id -> timestamp
        vector<int> onlineArr(numberOfUsers,0);

        for(vector<string> &event: events){

            string type=event[0],timeStamp=event[1];

            if(type=="OFFLINE"){
                int id=stoi(event[2]);
                onlineArr[id]=stoi(timeStamp)+60;
                continue;
            }

            string ids=event[2];
            stringstream ss(ids);
            string token;

            while(getline(ss,token,' ')){
                if(token=="ALL") allCount++;
                else if(token=="HERE"){
                    int currTime=stoi(timeStamp);
                    for(int i=0;i<numberOfUsers;i++){
                        int onlineTime=onlineArr[i];
                        if(onlineTime<=currTime) mentions[i]++;
                    }
                }
                else{
                    int id=stoi(token.substr(2));
                    mentions[id]++;
                }
            }
        }
        // All contributes to each of them.
        for(int i=0;i<numberOfUsers;i++)
            mentions[i]+=allCount;

        return mentions;
    }
};

int main(){

return 0;
}