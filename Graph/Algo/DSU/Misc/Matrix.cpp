#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY roads
 *  2. INTEGER_ARRAY machines
 */

class DSU{
    vector<int> parent, size;
    vector<bool> isMachineCity;
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
        public:
    DSU(int n,vector<int> &machines){
        parent.resize(n,-1);
        size.resize(n,1);
        isMachineCity.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        int m=machines.size();
        for(int i=0;i<m;i++){
            int j=machines[i];
            isMachineCity[j]=1;
        }
    }
    bool unionBySize(int u,int v){
        int U=find(u), V=find(v);
        if(isMachineCity[U] && isMachineCity[V]) return 0;
        if(size[U]>=size[V]){
            size[U]+=size[V];
            parent[V]=U;
            isMachineCity[U]=(isMachineCity[U]||isMachineCity[V]);
        }
        else{
            size[V]+=size[U];
            parent[U]=V;
            isMachineCity[V]=(isMachineCity[V]||isMachineCity[U]);
        }
        return 1;
    }
};

struct Comp{
    bool operator()(const vector<int> &a,const vector<int> &b){
        int timeA=a[2], timeB=b[2];
        if(timeA==timeB){
            if(a[0]<b[0]) return 1;
            return 0;
        }
        if(timeA>timeB) return 1;
        return 0;
    }
};

long long minTime(int n,vector<vector<int>> roads, vector<int> machines) { 
    DSU ds(n,machines);
    sort(roads.begin(),roads.end(),Comp());
    long long totalTime=0;
    for(auto &road: roads){
        int city1=road[0], city2=road[1], time=road[2];
        if(!ds.unionBySize(city1,city2)) totalTime+=time;
    }
    return totalTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> roads(n - 1);

    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        string machines_item_temp;
        getline(cin, machines_item_temp);

        int machines_item = stoi(ltrim(rtrim(machines_item_temp)));

        machines[i] = machines_item;
    }

    long long result = minTime(n,roads, machines);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
