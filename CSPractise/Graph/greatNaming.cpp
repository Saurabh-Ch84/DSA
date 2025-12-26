#include<iostream>
#include<vector>

using namespace std;
using vb = vector<bool> ;
using vvb = vector<vb> ;

// Once upon a time, in a kingdom far, far away, there lived a king Byteasar VI.
// As any king with such a magnificent name, he was destined to leave a trace in history.
// Unfortunately imagination wasn't one of king Byteasar's strong suits, so the reform
// he came up with was quite simple: the king ordered to rename all the cities.
// He didn't want to come up with new names (as a king, he'd have to remember them all!),
// so he ordered the cities to swap their names in such manner that the ith city would have
// the name of the city number (i + 1)th. The last city in the Byteasar's kingdom would,
// naturally, get the name of the very first city.
// The cartographers were not happy with this reform, since they had to redraw all the maps
// of the kingdom.Before the reform, information about all the roads between the cities
// were stored in the roadRegister. Prior to drawing maps, they had to start with updating
// the register. Your task is to find out what the updated register looked like.
// Example:
//          For
//          roadRegister = [[false, true, true, false],
//                          [true,  false, true,  false],
//                          [true,  true,  false, true ],
//                          [false, false, true,  false]]
//          the output should be
//          greatRenaming(roadRegister) = [[false, false, false, true ],
//                                         [false, false, true,  true ],
//                                         [false, true,  false, true ],
//                                         [true,  true,  true,  false]]
//          Here's how the catalog can be represented before and after the Great Renaming
//          https://codefightsuserpics.s3.amazonaws.com/tasks/greatRenaming/img/example.jpg?_tm=1490626015511


vvb greatRenaming(vvb &roadRegister){
    int n = roadRegister.size();
    vvb newRoadRegsiter(n, vb(n, false));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // Calculate the new indices for city i and city j
            int i_ = (i + 1) % n;
            int j_ = (j + 1) % n;
            
            // Move the connection to the new coordinates
            newRoadRegsiter[i_][j_] = roadRegister[i][j];
        }
    }
    return newRoadRegsiter;
}

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

int main() {
    vvb roadRegister = {
        {false, true,  true,  false},
        {true,  false, true,  false},
        {true,  true,  false, true },
        {false, false, true,  false}
    };

    vvb result = greatRenaming(roadRegister);
    printMatrix(result);
    
    return 0;
}