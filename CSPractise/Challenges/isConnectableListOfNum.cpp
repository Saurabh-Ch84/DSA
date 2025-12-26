#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using vs= vector<string> ;
// Halloween is coming up soon! Every year, Jan and her friends hold a special challenge, and this year
// is an especially scary one - they've decided to spend the night in a cemetery!
// For an additional fright, all of Jan's friends will be setting up camp separately, far away from each other.
// At midnight, the plan is to start searching for a secret treasure that Jan buried somewhere in the cemetery.
// To cover more ground, all the friends will be searching separately, so they each have a list of each other's numbers,
// so that they can call everyone in case one of them finds the treasure. However, her friends all use
// a quick-dialing app which starts calling a number as soon as it matches one of their contacts,
// so if one of the phone numbers is a prefix of another one of the numbers, then it'll start dialing
// the shorter number before the full number can be entered.For example, if you're trying to call 416321
// but 416 is also among the numbers, then it'll start dialing 416 before you can finish typing in 416321.

// Jan wants to make sure that everyone can be reached, so she needs for you to check if there are any numbers
// on the list that are prefixes of any other number on the list.Given an array of phone numbers(in the form of strings),
// return true if the list is error-free(contains no prefixes) and false otherwise.
// It is guaranteed that the list does not contain any duplicate numbers.

// Example:

//          For listOfNum = ["911", "97625999", "91125426"],
//          the output should be isConnectableListOfNum(listOfNum) = false.
//          Since 911 is a prefix of 91125426 the list of numbers is not error-free.

//          For listOfNum = ["113", "12340", "123440", "12345", "98346"],
//          the output should be isConnectableListOfNum(listOfNum) = true
//          Although some of these numbers start the same, none of them are prefixes of each other, so the list is error-free.

bool isConnectableListOfNum(vs &listOfNum){
    sort(listOfNum.begin(),listOfNum.end());
    int n=listOfNum.size();
    for(int i=0;i<n-1;i++){
        if(listOfNum[i].length()<=listOfNum[i+1].length()){
            string s1=listOfNum[i];
            string s2=listOfNum[i+1];
            if(s2.substr(0,s1.length())==s1)
                return false;
        }
    }
    return true;
}

int main(){

return 0;
}