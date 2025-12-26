#include<iostream>
#include<unordered_set>
using namespace std;

// You're spending the night at your aunt's 300-year-old mansion which you're convinced is haunted.
// While in bed, the sibilant and shrill noises from around the house keep you awake.
// Are they really ghosts or just the wind?
// You recorded the sounds you had heard as a sequence of low-pitched noises(represented by o)
// and high-pitched ones(represented by u).
// The wind blows wildly and randomly, but ghosts' boos and wails follow a predictable pattern:
// They begin with a non-zero length of low-pitched os, then a non-zero length of high-pitched us,
// and finally another length of low-pitched os that are of the same length as the initial sequence of os.

// For example:

//              "ouo" = ghost
//              "oouuuuuoo" = ghost
//              "ouuooo" = ghost at first, then wind
//              "uo" = wind

// PROBLEM:     Given an uninterrupted sequence of sounds, your task is to determine whether it can be divided
//              into non-overlapping, contiguous subsequences that all follow the pattern of ghosts' wails.
//              If so, return true; otherwise, return false.

bool wailingGhost(string &seq){
    int n=seq.length();
    int i=0;
    while(i<n){
        int leftOs=0;
        for(int j=i;j<n;j++){
            if(seq[j]!='o') break;
            leftOs++;
        }
        if(!leftOs) return false;
        int midUs=0;
        for(int j=i+leftOs;j<n;j++){
            if(seq[j]!='u') break;
            midUs++;
        }
        if(!midUs) return false;
        int rightOs=0;
        for(int j=i+leftOs+midUs;j<n;j++){
            if(seq[j]!='o' || leftOs==rightOs) break;
            rightOs++;
        }
        if(!rightOs) return false;
        if(leftOs!=rightOs) return false;
        i=i+leftOs+midUs+rightOs;
    }
    return true;
}


int main(){
    string s1= "ouo", s2= "oouuuuuoo", s3= "ouuooo", s4= "uo";
    cout<<wailingGhost(s1)<<endl;
    cout<<wailingGhost(s2)<<endl;
    cout<<wailingGhost(s3)<<endl;
    cout<<wailingGhost(s4)<<endl;
return 0;
}