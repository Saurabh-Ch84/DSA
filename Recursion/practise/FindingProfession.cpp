#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        if(level==1) return "Engineer" ;
        string nextAns=profession(level-1,(pos+1)/2);
        if(pos%2) return nextAns;
        return (nextAns=="Engineer"? "Doctor":"Engineer");
    }
};

class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int setBits=0;
        pos--;
        while(pos){
            pos=pos&(pos-1);
            setBits++;
        }
        return (setBits%2? "Doctor":"Engineer");
    }
};

int main(){

return 0;
}
