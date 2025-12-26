#include<iostream>
#include<vector>

using namespace std;
using vs = vector<string> ;
// This Halloween, you want your costume to be so scary that onlookers will jump at the sight of you!
// You've almost got it all planned out, but you still need to find a scary mask.
// You've been told that facial symmetry is a sign of beauty, so you figure the more asymmetrical your mask is,
// the scarier it'll be!
// You're going mask shopping later today, so to make the process easier, you'd like to write an algorithm
// that can assess the scariness of a mask just by looking at a picture of it.More specifically,
// given an array of strings mask, representing what the mask looks like, your task is to return
// the number of pairs of cells that don't match up symmetrically.

// Example: For

//          mask = ["A    A",
//                  " O  O ",
//                  "= WW ="]
//          the output should be scariestMask(mask) = 0.

//          For

//          mask = ["@     ''' ",
//                  "' v**v  @'",
//                  "  A**A ' '"]
//          the output should be scariestMask(mask) = 12.

int scariestMask(vs &mask){
    int n=mask.size(), m=mask[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        int left=0, right=m-1;
        while(left<right){
            if(mask[i][left]!=mask[i][right]) count++;
            left++;
            right--;
        }
    }
    return count;
}

int main(){
    vs mask1 = {"A    A"," O  O ","= WW ="};
    cout<<scariestMask(mask1)<<endl;
    vs mask2 = {"@     ''' ","' v**v  @'","  A**A ' '"};
    cout<<scariestMask(mask2)<<endl;
return 0;
}