#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

// As a good secret agent, you know that you can't be communicating with other agents using a common alphabet
// or any kind of simple messaging system. Because of that, you and the other secret agents are using a
// small code alphabet to send minimal messages to each other, in order to coordinate your secret meetings.
// You've received an encoded message in the form of a string incomingMessage, which represents an inquiry
// from another secret agent, proposing a day, time, and location for your next secret meeting.
// Your task is to decode the message, and give a response indicating whether the meeting is possible or not.
// How to decipher the message:
//          This process can be quite complicated, so the following description would probably be tough
//          to follow for an average person, but the agency knows that you possess the exceptional skill
//          and patience to make it through easily!
//          Your alphabet consists of 20 symbols, and you can use the following key for encoding and decoding
//          (but don't tell anyone!)
//          "0" = "a"
//          "9" = "e"
//          "8" = "i"
//          "7" = "o"
//          "6" = "u"
//          "5" = "y"
//          "4" = "w"
//          "10" = "t"
//          "11" = "d"
//          "12" = "s"
//          "13" = "n"
//          "14" = "m"
//          "15" = "r"
//          "16" = "b"
//          "17" = "k"
//          "18" = "p"
//          "*" = "morning"
//          "@" = "afternoon"
//          "#" = "night"
//          "?" = "-"
// Each encoded message is made up of a series of these symbols, separated by "." characters.The decoded message
// should be in the form day-time-location.
// For an extra layer of security, the "_" symbol is used to augment the code of all the numbers that follow it.
// More specifically, the codes should all be increased by codeNumberDiff, from that point onward.
// These modifiers are cumulative, so the codes can be augmented more than once.
//
// Being an Agent means that you need to be cautious about your movements, so there are only a few combinations
// of days, times, and locations that will work:
//
// If the day is "today", you can only meet in the park (regardless of the time).
// If the day is "tomorrow", then you can either meet at the "bar" at "night", or in the "park" during the "afternoon".
// If the day is "twodays" (the day after tomorrow), then you can only meet at the "restaurant" in the "morning".
// No other combinations are possible.
// To answer the other agent, you must send an encrypted message with a "yes" or "no" (remember to send it encrypted).
// Return a 2-element array, containing the decrypted message and your encrypted response!

// Example: For incomingMessage = "10.7.11.0.5.?.#.?._.15.-1.14" and codeNumberDiff = 1,
//          the output should be["today-night-bar", "13.7"]
//          The first parts can be decoded using the key above("10.7.11.0.5" translates to "today" and "#"
//          translates to "night"), but since there's a "_" symbol in the last part, all of the following codes
//          should be augmented by 1 (since codeNumberDiff is 1). So the message goes from "15.-1.14" to "16.0.15",
//          which translates to "bar".
//          The answer for the message is "no", because for today you can only meet in the park(not the bar).
//          So after encrypting your response, the result is "13.7".

//          For incomingMessage = "10.4.7.11.0.5._.10.?.*.?._.11.5.8.6.-4.2.11.-4.9.6" and codeNumberDiff = 2,
//          the output should be["twodays-morning-restaurant", "5.9.12"]
//          There are two "_" symbols in the message, so after the first one appears, all codes should be
//          increased by 2; after the second one, all codes should be increased by 4.
//          Decrypting the message, it shows that the meeting will be in two days, in the morning at the restaurant,
//          which is a valid combination, so you answer with a encrypted "yes" ("5.9.12").

unordered_map<string,string> init(){
    unordered_map<string,string> converter={
        {"0","a"},{"9","e"},{"8","i"},{"7","o"},{"6","u"},{"5","y"},{"4","w"},{"10","t"},{"11","d"},
        {"12","s"},{"13","n"},{"14","m"},{"15","r"},{"16","b"},{"17","k"},{"18","p"},
        {"*","morning"},{"@","afternoon"},{"#","night"},{"?","-"},{"yes","5.9.12"},{"no","13.7"}
    };
    return converter;
}


vector<string> decrypt(string incomingMsg, int codeNumDiff){
    int n=incomingMsg.size();
    unordered_map<string,string> converter=init();

    stringstream ss(incomingMsg);
    string token, temp;
    
    string day, time, venue;
    int count=0;
    while(getline(ss,token,'.')){
        if(token=="_"){
            count++;
        }
        else if(token=="?"){
            if(day.empty()) day=temp;
            temp.clear();
        }
        else{
            if(token=="*" || token=="@" || token=="#"){
                temp.clear();
                time=converter[token];
                continue;
            }
            int num=stoi(token)+codeNumDiff*count;
            string actualVal=to_string(num);
            temp+=converter[actualVal];
        }
    }
    venue=temp;
    string decryptedMsg=day+'-'+time+'-'+venue;
    vector<string> response;
    response.push_back(decryptedMsg);
    if(day=="today"){
        if(venue=="park") response.push_back(converter["yes"]);
        else response.push_back(converter["no"]);
    }
    else if(day=="twodays"){
        if(venue=="restaurant" && time=="morning") response.push_back(converter["yes"]);
        else response.push_back(converter["no"]);
    }
    else{
        if(venue=="bar" && time=="night") response.push_back(converter["yes"]);
        else if(venue=="park" && time=="afternoon") response.push_back(converter["yes"]);
        else response.push_back(converter["no"]);
    }
    return response;
}

int main(){
    string incomingMessage1 = "10.7.11.0.5.?.#.?._.15.-1.14";
    string incomingMessage2 = "10.4.7.11.0.5._.10.?.*.?._.11.5.8.6.-4.2.11.-4.9.6";

    vector<string> resp1=decrypt(incomingMessage1,1);
    cout<<resp1[0]<<" "<<resp1[1]<<endl;
    vector<string> resp2=decrypt(incomingMessage2,2);
    cout<<resp2[0]<<" "<<resp2[1]<<endl;

return 0;
}