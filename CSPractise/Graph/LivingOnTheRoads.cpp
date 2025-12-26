#include<iostream>
#include<vector>
using namespace std;
using vb = vector<bool> ;
using vvb = vector<vb> ;

// In a kingdom far, far away, there lives a king Byteasar IX. The history of the kingdom
// is rich with events and actions, most of which has something to do with the cities
// of that kingdom. King Byteasar doesn't want to go down in history, and, most of all,
// he doesn't want to have anything to do with the cities of the kingdom. Cities are lame!
// Instead, king Byteasar wants to focus on the roads, which is why he issued a new decree:
// from now on, all roads are considered to be cities, and all cities are considered
// to be roads.Now his gratefuller subjects pack their livings and move out from the cities
// to the roads, and the cartographers are busy with building a new roadRegister of the kingdom.
// All roads of the kingdom are to be named by the cities they connect
// (i.e. [city1, city2], city1<city2), sorted lexicographically and enumerated starting from 0.
// A new road register for such a system should be created.
// Your task is to help the cartographers with building the new road register.
// Handle the challenge, and the glorious kingdom of Byteasar IX will never have to deal
// with the tasks related to cities ever again!
// Example:
//          For
//          roadRegister = [
//          [false, true, true, false, false, false],
//          [true,  false, false, true,  false, false],
//          [true,  false, false, false, false, false],
//          [false, true,  false, false, false, false],
//          [false, false, false, false, false, true ],
//          [false, false, false, false, true,  false]
//          ]
//          the output should be
//          livingOnTheRoads(roadRegister) = [
//            [false, true,  true,  false],
//            [true,  false, false, false],
//            [true,  false, false, false],
//            [false, false, false, false]
//          ]
//          Here's how the new register can be obtained:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/livingOnTheRoads/img/example.jpg?_tm=1490636290807

void printMatrix(const vvb& matrix) {
    cout << "[" << endl;
    for(const auto& row : matrix) {
        cout << "  [";
        for(size_t k = 0; k < row.size(); k++) {
            cout << (row[k] ? "true" : "false");
            if(k < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}


vvb livingOnTheRoads(vvb &roadRegister){
    int n=roadRegister.size();
    vector<pair<int,int>> roads;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!roadRegister[i][j]) continue;
            roads.push_back({i,j});
        }
    }
    int m=roads.size();
    vvb newRoadRegister(m,vb(m,false));
    for(int i=0;i<m;i++){
        pair<int,int> road1=roads[i];
        for(int j=i+1;j<m;j++){
            pair<int,int> road2=roads[j];
            bool connected=(road1.first==road2.first || road1.second==road2.second 
                            || road1.first==road2.second || road1.second==road2.first) ;
            if(connected){
                newRoadRegister[i][j]=true;
                newRoadRegister[j][i]=true;
            }
        }
    }
    return newRoadRegister;
}

int main(){
    vvb roadRegister = {
         {false, true, true, false, false, false},
         {true,  false, false, true,  false, false},
         {true,  false, false, false, false, false},
         {false, true,  false, false, false, false},
         {false, false, false, false, false, true },
         {false, false, false, false, true,  false}
         };
    printMatrix(roadRegister);
    printMatrix(livingOnTheRoads(roadRegister));
return 0;
}