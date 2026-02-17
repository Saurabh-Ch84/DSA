#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

using vs=vector<string>;
using vi=vector<int>;
class Solution1 {
    unordered_set<string> visited;
	vi hours={1,2,4,8}, mins={1,2,4,8,16,32};
	int h=hours.size(), m=mins.size();

    string getTime(int hour,int min){
        return to_string(hour)+":"+(min>9 ? "":"0")+to_string(min);
    }

	void recursion(int i,int j,int hour,int min,vs &result,int t){
        if(t>(h-i)+(m-j)) return ;
		if(i>=h && j>=m){
            string time=getTime(hour,min);
            if(t || visited.count(time)) return ;
            result.push_back(time);
            visited.insert(time);
            return ;
        }
        //take
        if(j<m && min+mins[j]<60) 
            recursion(i,j+1,hour,min+mins[j],result,t-1);
        if(i<h && hour+hours[i]<12) 
            recursion(i+1,j,hour+hours[i],min,result,t-1);
        //skip
        if(j<m) recursion(i,j+1,hour,min,result,t);
        if(i<h) recursion(i+1,j,hour,min,result,t);
	}
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vs result;
        int hour=0, min=0;
        recursion(0,0,hour,min,result,turnedOn);
        return result;
    }
};

using vs=vector<string>;
using vi=vector<int>;
using vb=vector<bool>;
using vvb=vector<vb>;

class Solution2 {
	vi hours={1,2,4,8}, mins={1,2,4,8,16,32};
	int h=hours.size(), m=mins.size();

    string getTime(int hour,int min){
        return to_string(hour)+":"+(min>9 ? "":"0")+to_string(min);
    }

	void recursion(int i,int j,int hour,int min,vs &result,int t,vvb &visited){
        if(t>(h-i)+(m-j)) return ;
		if(i>=h && j>=m){
            if(t || visited[hour][min]) return ;
            string time=getTime(hour,min);
            result.push_back(time);
            visited[hour][min]=true;
            return ;
        }
        //take
        if(j<m && min+mins[j]<60) 
            recursion(i,j+1,hour,min+mins[j],result,t-1,visited);
        if(i<h && hour+hours[i]<12) 
            recursion(i+1,j,hour+hours[i],min,result,t-1,visited);
        //skip
        if(j<m) recursion(i,j+1,hour,min,result,t,visited);
        if(i<h) recursion(i+1,j,hour,min,result,t,visited);
	}
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vs result;
        int hour=0, min=0;
        vvb visited(12,vb(60,false));
        recursion(0,0,hour,min,result,turnedOn,visited);
        return result;
    }
};

using vs=vector<string>;
class Solution3 {
    string getTime(int hour,int min){
        return to_string(hour)+":"+(min>9 ? "":"0")+to_string(min);
    }

    int setBitsCount(int n){
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vs result;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(setBitsCount(i)+setBitsCount(j)==turnedOn){
                    result.push_back(getTime(i,j));
                }
            }
        }
        return result;
    }
};

class Solution4 {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        
        vi start(n), end(n);
        for(int i=0;i<n;i++){
            start[i]=arr[i][0];
            end[i]=arr[i][1];
        }
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int maxi=0, cumSum=0;
        int i=0, j=0;
        while(i<n){
            if(start[i]<=end[j]){
                cumSum++;
                maxi=max(maxi,cumSum);
                i++;
            }
            else{
                cumSum--;
                j++;
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}