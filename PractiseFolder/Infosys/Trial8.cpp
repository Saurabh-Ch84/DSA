#include<bits/stdc++.h>
#include<string_view>
using namespace std;

using vint=vector<int>;
using vstr=vector<string>;
using vvstr=vector<vstr>;
using vll=vector<long long>;
using vvint=vector<vint>;

/*
    While playing an RPG game, you were assigned to complete one of the hardest quests in this game. There are n monsters you'll need to 
    defeat in this quest. Each monster i is described with two integer numbers - poweri and bonusi. To defeat this monster, you'll need at 
    least poweri experience points. If you try fighting this monster without having enough experience points, you lose immediately. You will 
    also gain bonusi experience points if you defeat this monster. You can defeat monsters in any order. The quest turned out to be very 
    hard - you try to defeat the monsters but keep losing repeatedly. Your friend told you that this quest is impossible to complete. 
    Knowing that, you're interested, what is the maximum possible number of monsters you can defeat?

    Input: The first line contains an integer, n, denoting the number of monsters. The next line contains an integer, e, denoting your 
    initial experience. Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, poweri, which represents power of the
    corresponding monster. Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, bonusi, which represents bonus for 
    defeating the corresponding monster.

    2
    123
    78
    130
    10
    0

    Output: 2
*/

/*
    Given a number M in its decimal representation, your task is find the minimum base B such that in the representation 
    of M at base B all digits are the same.

    Input Format
        - The first line contains an integer, M, denoting the number given

    Constraints
        - 1 <= M = 10^12

    Sample Input 1 :
        41
    Sample Output 1 :
        40

    Explanation :
        Here 41 in base 40. will be 11 so it has all digits the same, and there is no smaller base satisfying the requirements

    1. M = 41, Base B = 40
        - In base 40, digits allowed: 0 to 39
        - Representation: 11 -> meaning
*/

/*
    Given an array of T length each index contains array of two binary strings, your task is to return their maximum sum(Also a binary string).
    First Line contains T array Length, next n lines contain two string which shows binary space separated m,n. Find the sum of m and n 
    in binary and print the maximum binary sum from the array elements.

    Input
    3
    101  100
    110  10
    1000  11

    output: 1011
*/

/*
    You are given a string S of size N you have to perform a particular type of query multiple times on this string. 
    The query is : for any string T, find the length of a lexicographically smallest suffix string of S start with T, 
    if there is no suffix return 0

    After performing all the queries you have to return the sum of all queries. Since the answer can be very large return it in 
    modulo 10^9+7

    I/P:    
        13
        1
        mzadpoghyykht
        yk
    O/p: 4

    I/p:
        12
        2
        ktmrgjswhwxu
        z
        w
    O/P: 5

    I/p:
        15
        1
        tvtrpudosnlydgi
        do
    O/P: 9
*/

struct SuffixComp{
    const string &str;
    SuffixComp(const string &str) :str(str){}
    bool operator()(int aIndx,int bIndx)const{
        return string_view(str).substr(aIndx)<string_view(str).substr(bIndx);
    }
};

struct QueryComp{
    const string &str;
    QueryComp(const string &str): str(str){}
    bool operator()(int idx,const string &target) const{
        return string_view(str).substr(idx)<string_view(target);
    }
};


class Solution{
    int mod=1e9+7;
    bool check(long long base,long long num){
        long long number=-1;
        while(num){
            long long rem=num%base;
            if(number!=-1 && number!=rem)
                return 0;
            number=rem;
            num=num/base;
        }
        return 1;
    }
    string add(string s1,string s2){
        string res;
        int i=s1.size()-1, j=s2.size()-1;
        bool carry=0;
        while(i>=0 || j>=0 || carry){
            int bit1=(i>=0? s1[i--]-'0':0), bit2=(j>=0? s2[j--]-'0':0);
            int sum=bit1+bit2+carry;
            res.push_back(sum%2+'0');
            carry=sum/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
        public:
    int maxNumberOfMonstersDefeated(int n,int e,vint power,vint bonus){
        vvint arr(n);
        for(int i=0;i<n;i++)
            arr[i]={power[i],bonus[i]};
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i][0]>e) break;
            e+=arr[i][1];
            count++;
        }
        return count;
    }
    long long findTheMinimumBase(long long num){
        if (num < 3) return num + 1;
        int bound1=min(1e6,(double)num);
        for(int base=2;base<=bound1;base++){
            if(check(base,num))
                return base;
        }
        int bound2=min(1e6,(double)num-1);
        // num=d*B+d.
        for(int digits=bound2;digits>=1;digits--){
            if(num%digits==0){
                long long B=(num/digits)-1;
                if(B>=2 && digits<B){
                    return B;
                }
            }
        }
        return num-1;
    }
    string maxSumBinaryString(vvstr binaryStrings){
        string maxi;
        for(auto &p: binaryStrings){
            string temp=add(p[0],p[1]);
            if(maxi.empty() || temp.length()>maxi.length() || temp>maxi)
                maxi=temp;
        }
        return maxi; 
    }
    long long suffixQuerySums(string S,vstr T){
        int n=S.size();
        vector<int> suffixIdxArr(n,-1);
        for(int i=0;i<n;i++)
            suffixIdxArr[i]=i;
        sort(suffixIdxArr.begin(),suffixIdxArr.end(),SuffixComp(S));
        long long total=0;
        for(auto &target: T){
            auto it=lower_bound(suffixIdxArr.begin(),suffixIdxArr.end(),target,QueryComp(S));
            if(it!=suffixIdxArr.end()){
                int idx=*it;
                string_view suffix=string_view(S).substr(idx);
                int n=target.size(), m=suffix.size();
                if(m>=n && suffix.substr(0,n)==target)
                    total=(total+m)%mod;
            }
        }
        return total;
    }
};

int main(){
    Solution s;
    cout<<s.maxNumberOfMonstersDefeated(2,123,{78,130},{10,1})<<endl;
    cout<<s.findTheMinimumBase(41)<<endl;
    cout<<s.findTheMinimumBase(63)<<endl;
    cout<<s.maxSumBinaryString({{"101","100"},{"110","10"},{"1000","11"}})<<endl;
    cout<<s.suffixQuerySums("sauraubshaury",{"av","a","sh","aur"})<<endl;
return 0;
}