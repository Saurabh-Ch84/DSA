#include<iostream>
#include<vector>
using namespace std;
using vb= vector<bool> ;
using vi= vector<int> ;
using vvb = vector<vb> ;

// Once upon a time, in a kingdom far, far away, there lived a king Byteasar VIII.
// The king came down in history as a great warrior, since he managed to defeat the enemy
// that has been capturing the cities of the kingdom over more than a century.
// When the war was over, most of the cities were almost completely destroyed,
// and there was no way to raise them from the debris. Byteasar decided to start cities
// renovation by merging them.
// The king decided to merge each pair of cities cityi, cityi+1 for i = 0, 2, 4, ...
// if they were connected by one of the two-way roads running through the kingdom.
// Initially, all information about the roads were stored in the roadRegister.
// Your task is to return the roadRegister after the merging was performed, assuming
// that after merging the cities reindexation is done in such way that city formed
// out of cities a and b (where a < b) receives index a, and all the cities
// with numbers i(where i > b) get numbers i - 1.
// Example:
//          For
//          roadRegister =
//          [
//            [false, true,  true,  false, false, false, true ],
//            [true,  false, true,  false, true,  false, false],
//            [true,  true,  false, true,  false, false, true ],
//            [false, false, true,  false, false, true,  true ],
//            [false, true,  false, false, false, false, false],
//            [false, false, false, true,  false, false, false],
//            [true,  false, true,  true,  false, false, false]
//          ]
//          the output should be 
//          mergingCities(roadRegister) = [
//            [false, true,  true,  false, true ],
//            [true,  false, false, true,  true ],
//            [true,  false, false, false, false],
//            [false, true,  false, false, false],
//            [true,  true,  false, false, false]
//          ]
//          Here's how the cities were merged:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/mergingCities/img/example.jpg?_tm=1490636345938

vvb mergingCities(vvb &roadRegister){
    int n=roadRegister.size();
    int currentId=0;
    vi newId(n);
    for(int i=0;i<n;i++){
        if(i%2==0 && i+1<n && roadRegister[i][i+1]){
            newId[i]=currentId;
            newId[i+1]=currentId;
            i++;
        }
        else newId[i]=currentId;
        currentId++;
    }
    int m=currentId;
    vvb newRoadRegister(m,vb(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(roadRegister[i][j]){
                int u=newId[i];
                int v=newId[j];
                if(u==v) continue;
                newRoadRegister[u][v]=true;
                newRoadRegister[v][u]=true;
            }
        }
    }
    return newRoadRegister;
}

int main(){

return 0;
}