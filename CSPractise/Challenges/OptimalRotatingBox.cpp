#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pii= pair<int,int>;
using vpi = vector<pii> ;
using vs = vector<string> ;

// You're moving another large rectangular box over a rough, hazardous surface. Just like last time,
// your only movement option is to perform a series of 90 degree rotations (basically just repeatedly
// pushing the box over onto its side).

// Again, every time you rotate the box, it hits the ground and some damage is done, depending on the
// fragility of the side of the box that it landed on, as well as the roughness of the ground in the region
// where it was dropped.But this time, the box can be customized - so long as the original dimensions
// are maintained, each part of the box can be rearranged, so that the more fragile areas are less exposed
// to the rough parts of the surface.

// Given boxWeakness representing the original state of the box, and surfaceRoughness representing how
// damaging the surface is, your task is to find the minimum possible total damage the box can receive
// after being rotated across the entire surface.

// Notes:
//          All parts of the box must be used; no parts can be duplicated or destroyed.
//          The length of the surface might not perfectly fit the box; if there's some overhang on the last step,
//          that part won't be damaged.
//          Once the box has been customized, it can't be rearranged again throughout its rotation.
//
// Example:
//          For
//          boxWeakness = ["01",
//                         "21",
//                         "10"]
//          and surfaceRoughness = "39513695380152438476", the output should be
//          optimalRotatingBox(boxWeakness, surfaceRoughness) = 49.
//          In its original orientation, the box will take 56 units of damage, but it can be rearranged
//          in such a way that the total damage is as low as 49.
//          1*3 + 0*9 + 0*5 + 2*1 + 1*3 + 1*6 + 0*9 + 0*5 + 1*3 + 1*8 + 1*0 + 0*1 + 0*5 + 2*2 + 1*4 +
//                                                                      1*3 + 0*8 + 0*4 + 1*7 + 1*6 = 49

int optimalRotatingBox(vs &boxWeakness, string surfaceRoughness){
    int r = boxWeakness.size();
    int c = boxWeakness[0].size();
    
    // 1. Precompute Coordinates instead of String Values
    // We need to know WHICH cell is touching the ground to add up exposure
    vector<vpi> sides(4);
    for(int i=0; i<4; i++){
        if(i%2==0){
            // Horizontal sides (Rows)
            int rowIdx = (i==0) ? r-1 : 0;
            for(int j=0; j<c; j++) 
                sides[i].push_back({rowIdx, j});
            
            // Top side runs Right->Left
            if(i==2) reverse(sides[i].begin(), sides[i].end());
        }
        else{
            // Vertical sides (Cols)
            int colIdx = (i==1) ? c-1 : 0;
            for(int j=0; j<r; j++) 
                sides[i].push_back({j, colIdx});
            
            // Right side runs Bottom->Top
            if(i==1) reverse(sides[i].begin(), sides[i].end());
        }
    }

    // 2. Calculate Exposure (The "Where")
    vvi exposure(r, vi(c, 0));
    int n = surfaceRoughness.size();
    int ptr = 0, turn = 0;

    while(ptr < n){
        vpi &currentSide = sides[turn];
        int k = currentSide.size();
        for(int i=0; i<k; i++){
            if(ptr >= n) break; // Overhang check
            int sR = surfaceRoughness[ptr] - '0';
            pii p = currentSide[i];
            // Accumulate roughness on this specific cell
            exposure[p.first][p.second] += sR;
            ptr++;
        }
        turn = (turn + 1) % 4;
    }

    // 3. Flatten, Sort and Match (The "What")
    vi weakVals, expVals;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            weakVals.push_back(boxWeakness[i][j] - '0');
            expVals.push_back(exposure[i][j]);
        }
    }

    // Greedy Logic: Smallest Weakness * Largest Exposure
    sort(weakVals.begin(), weakVals.end());
    sort(expVals.rbegin(), expVals.rend());

    int minDamage = 0;
    for(int i=0; i<weakVals.size(); i++){
        minDamage += weakVals[i] * expVals[i];
    }
    
    return minDamage;
}

int main(){
    vs box = {"01", "21", "10"};
    string surface = "39513695380152438476";
    // Expected: 49
    cout << optimalRotatingBox(box, surface) << endl;
    return 0;
}