#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.

vector<int> PSE(vector<long> &arr,int n){
    vector<int> pse(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) pse[i]=st.top();
        st.push(i);
    }
    return pse;
}

vector<int> NSE(vector<long> &arr,int n){
    vector<int> nse(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    return nse;
}

vector<long> riddle(vector<long> arr) {
    // complete this function
    int n=arr.size();
    vector<long> ans(n,0);
    vector<int> pse=PSE(arr,n), nse=NSE(arr,n);
    for(int i=0;i<n;i++){
        int sz=nse[i]-pse[i]-1;
        ans[sz-1]=max(ans[sz-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
