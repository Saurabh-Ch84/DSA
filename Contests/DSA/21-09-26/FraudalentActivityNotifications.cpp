#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

class MedianFinder{
    int d;
    set<pair<int,int>> st1,st2;
    void balance(){
        int n1=st1.size(), n2=st2.size();
        if(n1>n2+1){
            auto itr=st1.end();
            itr--;
            st2.insert({itr->first,itr->second});
            st1.erase(itr);
        }
        else if(n2>n1){
            auto itr=st2.begin();
            st1.insert({itr->first,itr->second});
            st2.erase(itr);
        }
    }
        public:    
    MedianFinder(int d):d(d){}
    int query(){
        // Returns 2*median.
        int n1=st1.size(), n2=st2.size();
        if(n1+n2<d) return -1;
        auto itr1=st1.rbegin();
        if(d%2==1) return itr1->first*2;
        auto itr2=st2.begin();
        return itr1->first+itr2->first;
    }
    void shrink(int val,int idx){
        if(st1.count({val,idx})) st1.erase({val,idx});
        else st2.erase({val,idx});
        balance();
    }
    void expand(int val,int idx){
        auto itr=st2.begin();
        if(itr!=st2.end() && val>itr->first) st2.insert({val,idx});
        else st1.insert({val,idx});
        balance();
    }
};

int activityNotifications(vector<int> expenditure, int d) {
    int count=0, n=expenditure.size();
    MedianFinder mf(d);
    for(int i=0;i<n;i++){
        if(i>=d){
            int medianInto2=mf.query();
            if(expenditure[i]>=medianInto2) count++;
            int j=i-d;
            mf.shrink(expenditure[j],j);
        }
        mf.expand(expenditure[i],i);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
