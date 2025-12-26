#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

// You and your friends are planning out your Halloween night experience! You all have your costumes ready to go,
// and you've decided on a rendezvous point where you'll all meet, then go trick-or-treating.
// You'd all like to meet up as soon as possible, but you're also all interested in picking up
// some candy along the way.So you decide on the following plan:

// Each of you will visit at least one house on your way toward the rendezvous point.
// Eventually each of you will stop visiting houses, but until then no houses will be skipped.
// You decide that fairness is most important, so the goal will be for everyone to visit houses
// in such a way that the total candy spread is minimized (ie: the maximum amount of candy collected
// by any friend minus the minimum amount of candy collected by any friend is the smallest possible).
// From extensive research and prior encounters, you're all aware of how much candy will be given out at each house.
// Since each of you will be walking different routes before meeting up, the amounts given by each house,
// on each friend's path, are represented by friendsRoutes, where friendsRoutes[i][j] is the amount of candy
// given by the jth house that the ith friend will encounter.

// Your task is to find how many houses each friend should visit before going directly to the rendezvous point.

// If there are multiple ways to minimize the spread, choose the option that involves visiting fewer houses
// (so that you can meet up earlier). friendsRoutes is not necessarily a rectangular matrix.
// Example: For

//              friendsRoutes = [[1,2,1,1,1,1], 
//                               [5,4,7,4,5,9], 
//                               [3,3,3,3,3,3,3,3,3]]
//          the output should be equitableMeetup(friendsRoutes) = [4, 1, 2].

// Since each friend must visit at least one house each, the friends will collect 1, 5, and 3 respectively,
// so the initial spread is 5 - 1 = 4.
// The best spread the friends can obtain is 1, and the way to achieve it while visiting the fewest number of houses,
// is for the friends to visit 4, 1, and 2 houses, respectively:
//      Friend 0 collects 1 + 2 + 1 + 1 = 5
//      Friend 1 collects 5
//      Friend 2 collects 3 + 3 = 6
//      Thus the spread is 6 - 5 = 1, which is the minimum possible.

vi equitableMeetup(vvi &friendsRoutes){
    int n = friendsRoutes.size();
    
    // Set stores: {Current Total Candy, House Index, Friend Index}
    set<vi> houseSet;   
    
    for(int i = 0; i < n; i++){
        // Init with: Value, HouseIdx (0), FriendID (i)
        vi temp = {friendsRoutes[i][0], 0, i};
        houseSet.insert(temp);
    }

    vi res(n, 1);
    int spread = INT_MAX;

    // Use while(true) because we stop only when the SMALLEST friend 
    // runs out of houses. (ptr < sz is not sufficient).
    while(true){
        vi smallest = *houseSet.begin();
        vi largest = *houseSet.rbegin();
        
        int currSpread = largest[0] - smallest[0];

        // 1. Check for new record
        if(currSpread < spread){
            spread = currSpread;
            // FIX: Snapshot EVERYONE'S position into the result
            for(const vi& entry: houseSet){
                int j=entry[1], i=entry[2];
                res[i]=j+1;
            }
        }
        int smallVal = smallest[0];
        int smallJ = smallest[1]; // House Index
        int smallI = smallest[2]; // Friend ID
        int bound = friendsRoutes[smallI].size();
        // 2. ALWAYS try to move the smallest friend forward
        // (This logic must be OUTSIDE the 'if' block)
        if(smallJ + 1 < bound){
            houseSet.erase(smallest);
            smallJ++; 
            // Your Rolling Sum Logic: Previous Total + Next House Value
            int nextTotal = smallVal + friendsRoutes[smallI][smallJ];
            houseSet.insert({nextTotal, smallJ, smallI});
        }
        else {
            // If the smallest element cannot grow, the spread can never decrease.
            break;
        }
    }
    return res;
}

int main(){
    vvi routes = {
        {1, 2, 1, 1, 1, 1}, 
        {5, 4, 7, 4, 5, 9}, 
        {3, 3, 3, 3, 3, 3, 3, 3, 3}
    };
    // Expected Output: 4 1 2
    vi r = equitableMeetup(routes);
    for(int x : r) cout << x << " ";
    return 0;
}