#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q1.Sorting of the vector of pairs using compare function: Given different strings consists of two substrings 
one consisting of a name and the other consisting of a Roman number from 1-50. 
You have to sort the strings first by their name and then by the value represented by the Roman string. 
The implementation requires to design a function to convert a Roman string into a corresponding integer value.

Q2.Given n, the number of lanes numbered from 1 to n. m cars are standing in lanes where the start and 
finish of each car is given. Find the longest gap in the lanes which are empty. Give me 2 test cases only

Q3.Given two binary matrices of the same dimension, return the number of identical islands in both the binary matrices.
*/

class Solution{
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }

    void DFS(vector<vector<int>> &grid,int i,int j,int n,int m,string &island,
            vector<int> &di,vector<int> &dj,vector<char> &moves)
    {
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int newI=i+di[k],newJ=j+dj[k];
            if(isValid(newI,newJ,n,m) && grid[newI][newJ]==1){
                island+=moves[k];
                DFS(grid,newI,newJ,n,m,island,di,dj,moves);
            }
        }
    }

    static int romanToDec(string &num){
        int n=num.size();
        int number=0;
        char curr,prev='#';
        
        unordered_map<char,int> hashMap={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(int i=n-1;i>=0;i--){
            curr=num[i];
            if(prev=='#' || hashMap[curr]>=hashMap[prev])
                number+=hashMap[curr];
            else number-=hashMap[curr];
            prev=curr;
        }
        return number;
    }

    static bool comp(const string &a,const string &b){
        stringstream ssA(a);
        string wordA,romanA;
        ssA>>wordA>>romanA;
        
        stringstream ssB(b);
        string wordB,romanB;
        ssB>>wordB>>romanB;
        
        if(wordA==wordB){
            int decA=romanToDec(romanA);
            int decB=romanToDec(romanB);
            return decA<decB;
        }
        return wordA<wordB;
    }
        public:
    void customSort(vector<string> &list){
        sort(list.begin(),list.end(),comp);
    }

    int findMaxGap(vector<vector<int>> &cars,int n){
        if(cars.empty()) return n;
        sort(cars.begin(),cars.end());
        int maxGap=INT_MIN,prevEnd=0;
        for(vector<int> &car:cars){
            int start=car[0],end=car[1];
            maxGap=max(maxGap,start-prevEnd-1);
            prevEnd=max(prevEnd,end);
        }
        return max(maxGap,n-prevEnd);
    }

    int findIdenticalIslandsCount(vector<vector<int>> &a,vector<vector<int>> &b){
        int n=a.size(),m=a[0].size();
        int count=0;
        vector<int> di={-1,0,1,0},dj={0,1,0,-1};
        vector<char> moves={'U','R','D','L'};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && b[i][j]){
                    string islandA="S",islandB="S";
                    DFS(a,i,j,n,m,islandA,di,dj,moves);
                    DFS(b,i,j,n,m,islandB,di,dj,moves);
                    if(islandA==islandB) count++;
                }
            }
        }
        return count;
    }
};

void print(vector<string> &list){
    for(string &l:list)
        cout<<l<<" ";
    cout<<endl;
}

void printMatrix(vector<vector<int>> &matrix, string name) {
    cout << name << ":\n";
    for(auto &row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void testIdenticalIslands() {
    Solution s;
    cout << "\n=== TESTING IDENTICAL ISLANDS ===\n\n";
    
    // Test Case 1: Perfect Match - All islands identical
    cout << "TEST CASE 1: Perfect Match\n";
    vector<vector<int>> a1 = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };
    
    vector<vector<int>> b1 = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };
    
    printMatrix(a1, "Matrix A1");
    printMatrix(b1, "Matrix B1");
    
    // Create copies since DFS modifies the matrices
    vector<vector<int>> a1_copy = a1, b1_copy = b1;
    int result1 = s.findIdenticalIslandsCount(a1_copy, b1_copy);
    cout << "Expected: 3, Got: " << result1 << "\n";
    cout << "Analysis: L-shaped island at (0,0), vertical island at (1,3), horizontal island at (3,1)\n\n";
    
    // Test Case 2: Partial Match
    cout << "TEST CASE 2: Partial Match\n";
    vector<vector<int>> a2 = {
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
    };
    
    vector<vector<int>> b2 = {
        {1, 1, 0, 0},  // Different: no island at (0,3)
        {1, 0, 0, 0},
        {0, 0, 1, 1},  // Same: L-shaped island
        {0, 0, 1, 0}
    };
    
    printMatrix(a2, "Matrix A2");
    printMatrix(b2, "Matrix B2");
    
    vector<vector<int>> a2_copy = a2, b2_copy = b2;
    int result2 = s.findIdenticalIslandsCount(a2_copy, b2_copy);
    cout << "Expected: 2, Got: " << result2 << "\n";
    cout << "Analysis: L-shaped at (0,0) matches, L-shaped at (2,2) matches, single cell at (0,3) doesn't match\n\n";
    
    // Test Case 3: Same shapes, different positions
    cout << "TEST CASE 3: Same Shapes, Different Positions\n";
    vector<vector<int>> a3 = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 1}
    };
    
    vector<vector<int>> b3 = {
        {0, 0, 1, 1},  // L-shape moved to different position
        {0, 0, 0, 1},
        {1, 1, 0, 0},  // L-shape moved to different position
        {1, 0, 0, 0}
    };
    
    printMatrix(a3, "Matrix A3");
    printMatrix(b3, "Matrix B3");
    
    vector<vector<int>> a3_copy = a3, b3_copy = b3;
    int result3 = s.findIdenticalIslandsCount(a3_copy, b3_copy);
    cout << "Expected: 0, Got: " << result3 << "\n";
    cout << "Analysis: Same shapes but no islands at identical positions\n\n";
    
    // Test Case 4: Complex shapes
    cout << "TEST CASE 4: Complex Shapes\n";
    vector<vector<int>> a4 = {
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };
    
    vector<vector<int>> b4 = {
        {1, 1, 1, 0, 0},  // Same T-shaped island
        {0, 1, 0, 0, 1},  // Same vertical islands
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}   // Different: missing one cell
    };
    
    printMatrix(a4, "Matrix A4");
    printMatrix(b4, "Matrix B4");
    
    vector<vector<int>> a4_copy = a4, b4_copy = b4;
    int result4 = s.findIdenticalIslandsCount(a4_copy, b4_copy);
    cout << "Expected: 1, Got: " << result4 << "\n";
    cout << "Analysis: T-shaped island matches, vertical island at (1,4) matches, horizontal island at (3,3) doesn't match\n\n";
    
    // Test Case 5: Single cells
    cout << "TEST CASE 5: Single Cell Islands\n";
    vector<vector<int>> a5 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    
    vector<vector<int>> b5 = {
        {1, 0, 0},  // Different
        {0, 1, 0},  // Same
        {0, 0, 1}   // Different position
    };
    
    printMatrix(a5, "Matrix A5");
    printMatrix(b5, "Matrix B5");
    
    vector<vector<int>> a5_copy = a5, b5_copy = b5;
    int result5 = s.findIdenticalIslandsCount(a5_copy, b5_copy);
    cout << "Expected: 3, Got: " << result5 << "\n";
    cout << "Analysis: Single cells at (0,0) and (1,1) match\n\n";
}

int main(){
    Solution s;
    
    // Test Roman Sorting
    cout << "=== TESTING ROMAN SORTING ===\n";
    vector<string> list1={"John XV", "Alice III", "John V", "Bob X", "Alice XX", "Bob I"};
    cout << "Before sorting: ";
    print(list1);
    s.customSort(list1);
    cout << "After sorting: ";
    print(list1);

    // Test Max Gap
    cout << "\n=== TESTING MAX GAP ===\n";
    vector<vector<int>> cars1={{3,4},{5,7},{8,10}};
    cout << "Cars: [(3,4), (5,7), (8,10)], n=12\n";
    cout << "Max gap: " << s.findMaxGap(cars1,12) << endl;
    
    vector<vector<int>> cars2={{2,3},{5,6},{8,9}};
    cout << "Cars: [(2,3), (5,6), (8,9)], n=10\n";
    cout << "Max gap: " << s.findMaxGap(cars2,10) << endl;

    // Test Identical Islands
    testIdenticalIslands();

    return 0;
}