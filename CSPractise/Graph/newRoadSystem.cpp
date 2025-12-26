#include<iostream>
#include<vector>

using namespace std;
using vb = vector<bool> ;
using vi = vector<int> ;
using vvb = vector<vb> ;

// Once upon a time, in a kingdom far, far away, there lived a king Byteasar I. As a kind and wise ruler,
// he did everything in his (unlimited) power to make life of his subjects comfortable and pleasant.
// One cold evening a messenger arrived to the king's castle with the latest news:
// all kings in the Kingdoms Union started to enforce traffic laws! In order not to lose his membership
// in the Union, king Byteasar had to do the same in his kingdom. But what would the citizens think of it?
// The king decided to start introducing the changes with something more or less simple:
// change all the roads in the kingdom from two-directional to one-directional.
// He personally prepared the roadRegister of the new roads, and now he needs to make sure
// that the road system is convenient and there will be no traffic jams, i.e.each city has
// the same number of incoming and outgoing roads.As the Hand of the King,
// you're the one who should check it.
// Example:
//          For
//          roadRegister = [[false, true,  false, false],
//                          [false, false, true,  false],
//                          [true,  false, false, true ],
//                          [false, false, true,  false]]
//          the output should be
//          newRoadSystem(roadRegister) = true.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example1.jpg?_tm=1490636388679
//          Cities 0, 1 and 3 (0-based) have one incoming and one outgoing roads,
//          and city 2 has two incoming and two outgoing roads.Thus, the output should be true.
//
//          For
//          roadRegister = [[false, true, false, false, false, false, false],
//                          [true, false, false, false, false, false, false],
//                          [false, false, false, true, false, false, false],
//                          [false, false, true, false, false, false, false],
//                          [false, false, false, false, false, false, true],
//                          [false, false, false, false, true, false, false],
//                          [false, false, false, false, false, true, false]]
//          the output should be
//          newRoadSystem(roadRegister) = true.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example2.jpg?_tm=1490636388818
//          Each city has one incoming and one outgoing road.
//
//          For
//          roadRegister = [[false, true, false],
//                          [false, false, false],
//                          [true, false, false]]
//          the output should be
//          newRoadSystem(roadRegister) = false.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example3.jpg?_tm=1490636388947
//          City 1 has one incoming and none outgoing roads,
//          and city 2 has one outgoing and no incoming roads.

#include<iostream>
#include<vector>

using namespace std;
using vb = vector<bool> ;
using vi = vector<int> ;
using vvb = vector<vb> ;

// Once upon a time, in a kingdom far, far away, there lived a king Byteasar I. As a kind and wise ruler,
// he did everything in his (unlimited) power to make life of his subjects comfortable and pleasant.
// One cold evening a messenger arrived to the king's castle with the latest news:
// all kings in the Kingdoms Union started to enforce traffic laws! In order not to lose his membership
// in the Union, king Byteasar had to do the same in his kingdom. But what would the citizens think of it?
// The king decided to start introducing the changes with something more or less simple:
// change all the roads in the kingdom from two-directional to one-directional.
// He personally prepared the roadRegister of the new roads, and now he needs to make sure
// that the road system is convenient and there will be no traffic jams, i.e.each city has
// the same number of incoming and outgoing roads.As the Hand of the King,
// you're the one who should check it.
// Example:
//          For
//          roadRegister = [[false, true,  false, false],
//                          [false, false, true,  false],
//                          [true,  false, false, true ],
//                          [false, false, true,  false]]
//          the output should be
//          newRoadSystem(roadRegister) = true.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example1.jpg?_tm=1490636388679
//          Cities 0, 1 and 3 (0-based) have one incoming and one outgoing roads,
//          and city 2 has two incoming and two outgoing roads.Thus, the output should be true.
//
//          For
//          roadRegister = [[false, true, false, false, false, false, false],
//                          [true, false, false, false, false, false, false],
//                          [false, false, false, true, false, false, false],
//                          [false, false, true, false, false, false, false],
//                          [false, false, false, false, false, false, true],
//                          [false, false, false, false, true, false, false],
//                          [false, false, false, false, false, true, false]]
//          the output should be
//          newRoadSystem(roadRegister) = true.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example2.jpg?_tm=1490636388818
//          Each city has one incoming and one outgoing road.
//
//          For
//          roadRegister = [[false, true, false],
//                          [false, false, false],
//                          [true, false, false]]
//          the output should be
//          newRoadSystem(roadRegister) = false.
//          The cities will be connected as follows:
//          https://codefightsuserpics.s3.amazonaws.com/tasks/newRoadSystem/img/example3.jpg?_tm=1490636388947
//          City 1 has one incoming and none outgoing roads,
//          and city 2 has one outgoing and no incoming roads.

bool newRoadSystem(vvb &roadRegister){
    int n=roadRegister.size();
    vi indegree(n,0);
    vi outdegree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(roadRegister[i][j]){
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]!=outdegree[i]) 
            return false;
    }
    return true;
}


int main() {
    // KILLER TEST CASE: 0->1, 0->2, 1->2
    vvb roads = {
        {false, true,  true}, 
        {false, false, true},
        {false, false, false}
    };

    bool correctResult = newRoadSystem(roads);
    cout << "Correct Logic (In == Out): " << (correctResult ? "TRUE" : "FALSE (Correct)") << endl;

    return 0;
}