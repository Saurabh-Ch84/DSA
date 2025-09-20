#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class FoodRatings1 {
private:
    struct Comp{
        bool operator()(const pair<int,string> &a,const pair<int,string> &b) const {
            if(a.first==b.first)
                return a.second<b.second;
            return a.first>b.first;
        }
    };

    unordered_map<string,set<pair<int,string>,Comp>> cuisineMap;
    unordered_map<string,pair<int,string>> foodMap;

public:
    FoodRatings1(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            cuisineMap[cuisines[i]].insert({ratings[i],foods[i]});
            foodMap[foods[i]]={ratings[i],cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& value=foodMap[food];
        int oldRating=value.first;
        string cuisine=value.second;

        auto &foodSet=cuisineMap[cuisine];
        auto itr=foodSet.find({oldRating,food});
        if(itr!=foodSet.end()){
            foodSet.erase(itr);
            foodSet.insert({newRating,food});
        }
        value.first=newRating;
    }
    
    string highestRated(string cuisine) {
        auto p=*cuisineMap[cuisine].begin();
        string food=p.second;
        return food;
    }
};

class FoodRatings2 {
    unordered_map<string,set<pair<int,string>>> cuisineMap;
    unordered_map<string,pair<int,string>> foodMap;
public:
    FoodRatings2(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodMap[foods[i]]={ratings[i],cuisines[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& value=foodMap[food];
        int oldRating=value.first;
        string cuisine=value.second;

        auto &foodSet=cuisineMap[cuisine];
        foodSet.erase({-oldRating,food});
        foodSet.insert({-newRating,food});
        
        value.first=newRating;
    }
    
    string highestRated(string cuisine){
        return cuisineMap[cuisine].begin()->second;
    }
};


int main(){
    vector<string> foods={"pasta","eggcurry","chowmein","friedfish","rosogulla"};
    vector<string> cuisines={"Italian","Indian","Chinese","Indian","Indian"};
    // 1 to 10
    vector<int> ratings={7,8,6,9,8};
    FoodRatings1 frs(foods,cuisines,ratings);
    cout<<frs.highestRated("Indian")<<endl;
    cout<<frs.highestRated("Chinese")<<endl;
    frs.changeRating("pasta",6);
    frs.changeRating("friedfish",8);
    cout<<frs.highestRated("Indian")<<endl;
return 0;
}