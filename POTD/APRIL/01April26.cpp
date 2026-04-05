#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int countStrings(int n) {
        // code here
        int a=1, b=2;
        for(int i=1;i<=n;i++){
            int t=b;
            b=b+a;
            a=t;
        }
        return a;
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vint survivedRobotsHealths(vint &positions,vint &healths,string directions){
        int n=healths.size();
        vvint arr;
        for(int i=0;i<n;i++){
            int pos=positions[i], health=healths[i], dir=(directions[i]=='R');
            arr.push_back({pos,health,dir,i});
        }

        sort(arr.begin(),arr.end());
        stack<vint> st;
        for(vint &entry: arr){
            bool flag=true;
            while(!st.empty() && st.top()[2] && !entry[2]){
                int diff=entry[1]-st.top()[1];
                if(!diff){
                    st.pop();
                    flag=false;
                    break;
                }
                else if(diff>0){
                    st.pop();
                    entry[1]--;
                }
                else{
                    st.top()[1]--;
                    flag=false;
                    break;
                }
            }
            if(flag) st.push(entry);
        }

        vvint brr;
        while(!st.empty()){
            vint robo=st.top();
            st.pop();
            brr.push_back({robo[3],robo[1]});
        } 

        sort(brr.begin(),brr.end());

        vint res;
        for(vint &robo: brr)
            res.push_back(robo[1]);

        return res;
    }
};

int main(){

return 0;
}