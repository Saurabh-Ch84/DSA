#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<set<char>> parseWorkflow(const string& workflowStr) {
        if (workflowStr.empty()) return {};
        vector<string> tokens = tokenize(workflowStr);
        vector<string> postfix = infixToPostfix(tokens);
        return evaluatePostfix(postfix);
    }
private:
    vector<string> tokenize(const string& s) {
        vector<string> tokens;
        for (int i = 0; i < s.length(); ++i) {
            if (isspace(s[i])) continue;
            if (isupper(s[i])) {
                tokens.push_back(string(1, s[i]));
            } else if (s[i] == '-' && i + 1 < s.length() && s[i+1] == '>') {
                tokens.push_back("->");
                i++;
            } else if (s[i] == '|' || s[i] == '(' || s[i] == ')') {
                tokens.push_back(string(1, s[i]));
            }
        }
        return tokens;
    }

    vector<string> infixToPostfix(const vector<string>& tokens) {
        unordered_map<string, int> pre = {{ "->", 2 }, { "|", 1 }};
        vector<string> postfix;
        stack<string> opStack;

        for (const string& token : tokens) {
            if (isupper(token[0])) {
                postfix.push_back(token);
            } else if (token == "(") {
                opStack.push(token);
            } else if (token == ")") {
                while (!opStack.empty() && opStack.top() != "(") {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            } else {
                while (!opStack.empty() && opStack.top() != "(" && pre[opStack.top()] >= pre[token]) {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(token);
            }
        }
        while (!opStack.empty()) {
            postfix.push_back(opStack.top());
            opStack.pop();
        }
        return postfix;
    }

    vector<set<char>> evaluatePostfix(const vector<string>& postfix) {
        stack<vector<set<char>>> pathStack;

        for (const string& token : postfix) {
            if (isupper(token[0]))
                pathStack.push({{token[0]}});
            else{
                vector<set<char>> path2 = pathStack.top(); pathStack.pop();
                vector<set<char>> path1 = pathStack.top(); pathStack.pop();
                if(token == "->")
                    pathStack.push(combineSequential(path1, path2));
                else
                    pathStack.push(combineParallel(path1, path2));
            }
        }
        return pathStack.empty() ? vector<set<char>>{} : pathStack.top();
    }

    vector<set<char>> combineSequential(vector<set<char>> path1, vector<set<char>> path2) {
        path1.insert(path1.end(), path2.begin(), path2.end());
        return path1;
    }

    vector<set<char>> combineParallel(vector<set<char>> path1, vector<set<char>> path2) {
        if(path2.size() > path1.size())
            swap(path1, path2);
        for(int i = 0; i < path2.size(); ++i)
            path1[i].insert(path2[i].begin(), path2[i].end());
        return path1;
    }   
};

void printResult(const vector<set<char>>& path) {
    for(set<char> p:path){
        for(char val:p) cout<<val;
        cout<<" ";
    }
    cout<<endl;
}

int main() {
    Solution s;

    string workflow1 = "A->(B|C)->D";
    cout << "Input: \"" << workflow1 << "\"" << endl;
    vector<set<char>> result1 = s.parseWorkflow(workflow1);
    cout << "Output: ";
    printResult(result1);

    string workflow2 = "(A|B)->((C->D)|E)";
    cout << "Input: \"" << workflow2 << "\"" << endl;
    vector<set<char>> result2 = s.parseWorkflow(workflow2);
    cout << "Output: ";
    printResult(result2);

    return 0;
}