#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

class Tweet{
        public:
    int timeStamp,tweetId;
    Tweet(int timeStamp,int tweetId){
        this->timeStamp=timeStamp;
        this->tweetId=tweetId;
    }
};

using box=pair<const vector<Tweet>*,int>;

class Twitter{
    unordered_map<int,unordered_set<int>> followMap;
    unordered_map<int,vector<Tweet>> tweetMap;
    int timeStamp;

    struct Comp{
        bool operator()(const box &a, const box &b) const{
            return (*a.first)[a.second].timeStamp < (*b.first)[b.second].timeStamp;
        }
    };

public:
    Twitter() {
        timeStamp=0;
        followMap.clear();
        tweetMap.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        timeStamp++;
        Tweet tweet(timeStamp,tweetId);
        tweetMap[userId].push_back(tweet);
    }
    
    vector<int> getNewsFeed(int userId){
        vector<int> newsFeed;
        unordered_set<int> followSet=followMap[userId];
        followSet.insert(userId);
        priority_queue<box,vector<box>,Comp> pq;

        for(int followee:followSet){
            vector<Tweet> &v=tweetMap[followee];
            int sz=v.size()-1;
            if(sz>=0) pq.push({&v,sz});
        }
        while(!pq.empty() && newsFeed.size()<10){
            box p=pq.top();
            pq.pop();
            const vector<Tweet> *temp=p.first;
            int tweetId=(*temp)[p.second].tweetId;
            newsFeed.push_back(tweetId);
            if(p.second>0) pq.push({p.first,p.second-1});
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(){

return 0;
}