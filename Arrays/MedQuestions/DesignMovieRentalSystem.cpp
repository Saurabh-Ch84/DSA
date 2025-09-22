#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    unordered_map<int,set<pair<int,int>>> movieMap;
    unordered_map<long long,int> priceMap;
    set<vector<int>> rentedSet;

    long long hash(int shop,int movie){
        return (long long)shop*1e10+movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // n is of no use here
        for(vector<int> &entry:entries){
            int shop=entry[0],movie=entry[1],price=entry[2];
            long long key=hash(shop,movie);
            priceMap[key]=price;
            movieMap[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        for(auto &p:movieMap[movie]){
            int shop=p.second;
            result.push_back(shop);
            if(result.size()==5)
                break;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        long long key=hash(shop,movie);
        int price=priceMap[key];
        auto &shopSet=movieMap[movie];
        shopSet.erase({price,shop});
        rentedSet.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        long long key=hash(shop,movie);
        int price=priceMap[key];
        auto &shopSet=movieMap[movie];
        shopSet.insert({price,shop});
        rentedSet.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        for(vector<int> rented:rentedSet){
            int shop=rented[1],movie=rented[2];
            vector<int> entry={shop,movie};
            result.push_back(entry);
            if(result.size()==5)    
                break;
        }
        return result;
    }
};


int main(){
    int n=3;
    vector<vector<int>> entries={{1,2,100},{0,3,150},{2,1,200},{2,2,50},{1,3,200},{0,2,250}};
    MovieRentingSystem mrs(n,entries);
return 0;
}