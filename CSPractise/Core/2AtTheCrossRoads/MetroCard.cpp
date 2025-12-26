#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;

// You just bought a public transit card that allows you to ride the Metro for a certain number of days.
// Here is how it works: upon first receiving the card, the system allocates you a 31-day pass,
// which equals the number of days in January.The second time you pay for the card, your pass is extended by 28 days,
// i.e.the number of days in February(note that leap years are not considered), and so on.
// The 13th time you extend the pass, you get 31 days again.
// You just ran out of days on the card, and unfortunately you've forgotten how many times
// your pass has been extended so far. However, you do remember the number of days you were able
// to ride the Metro during this most recent month. Figure out the number of days
// by which your pass will now be extended, and return all the options as an array sorted in increasing order.

// Example: For lastNumberOfDays = 30, the output should be
//          metroCard(lastNumberOfDays) = [31].
//          There are 30 days in April, June, September and November, so the next months to consider are
//          May, July, October or December.All of them have exactly 31 days, which means that you will definitely get
//          a 31-days pass the next time you extend your card.

vi metroCard(int lastNumberOfDays){
    if(lastNumberOfDays==28) return {31};
    else if(lastNumberOfDays==30) return {31};
    return {28,30,31};
}

// You are playing an RPG game. Currently your experience points (XP) total is equal to experience.
// To reach the next level your XP should be at least at threshold. If you kill the monster in front of you,
// you will gain more experience points in the amount of the reward.

// PROBLEM: Given values experience, threshold and reward, check if you reach the next level after killing the monster.

bool reachNextLevel(int experience, int threshold, int reward){
    return (experience+reward >= threshold);
}

// In tennis, a set is finished when one of the players wins 6 games and the other one wins less than 5,
// or, if both players win at least 5 games, until one of the players wins 7 games.

// PROBLEM: Determine if it is possible for a tennis set to be finished with the score score1 : score2.

bool tennisSet(int score1,int score2){
    if(score1==6 && score2<5) return true;
    else if(score1<5 && score2==6) return true;
    else if((score1==5 || score1==6) && score2==7) return true;
    else if(score1==7 && (score2==5 || score2==6)) return true;
    return false;
}

// Once Mary heard a famous song, and a line from it stuck in her head. That line was
// "Will you still love me when I'm no longer young and beautiful?". Mary believes that
// a person is loved if and only if he/she is both young and beautiful, but this is
// quite a depressing thought, so she wants to put her belief to the test.

// PROBLEM: Knowing whether a person is young, beautiful and loved, find out if they contradict Mary's belief.

// A person contradicts Mary's belief if one of the following statements is true:

// they are young and beautiful but not loved;
// they are loved but not young or not beautiful.

bool willYou(bool young,bool beautiful,bool loved){
    // returns true for contradiction.
    if(loved){
        if(!young || !beautiful) return true;
        return false;
    }
    else{
        if(young && beautiful) return true;
        return false;
    }
}

int main(){

return 0;
}