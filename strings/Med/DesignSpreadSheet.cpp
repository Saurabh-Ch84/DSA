#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Not so optimal
class Spreadsheet1 {
    vector<vector<int>> spreadsheet;

    int evaluate(string exp){
        int n=exp.length(),x=0,i=0;
        if(exp[i]=='=') i++;
        if(exp[i]>='0' && exp[i]<='9')
        {
            for(int j=i;j<n;j++)
                x=x*10+(exp[j]-'0');
        }
        else
        {
            int col=exp[i]-'A',row=0;
            for(int j=i+1;j<n;j++)
                row=row*10+(exp[j]-'0');
            x=spreadsheet[--row][col];
        }
        return x;
    }
    
public:
    Spreadsheet1(int rows) {
        vector<vector<int>> temp(rows,vector<int>(26,0));
        spreadsheet=temp;
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=0,n=cell.length();
        for(int i=1;i<n;i++)
            row=row*10+(cell[i]-'0');
        spreadsheet[--row][col]=value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    
    int getValue(string formula) {
        string token;
        stringstream ssf(formula);
        int result=0;
        while (getline(ssf, token, '+'))
            result+= evaluate(token);
        return result;
    }
};

//More efficient 
class Spreadsheet2 {
    unordered_map<string,int> spreadsheet;

    int eval(string exp){
        int x=0,n=exp.length(),i=0;
        if(exp[i]>='0' && exp[i]<='9'){
            for(int j=i;j<n;j++)
                x=x*10+(exp[j]-'0');
        }
        else{
            string key;
            for(int j=i;j<n;j++)
                key.push_back(exp[j]);
            x=(spreadsheet.count(key))?spreadsheet[key]:0;
        }
        return x;
    }

public:
    Spreadsheet2(int rows) { 
        spreadsheet.clear();
    }
    
    void setCell(string cell, int value) {
        spreadsheet[cell]=value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    
    int getValue(string formula) {
        if(formula[0]=='=')
            formula=formula.substr(1);
        string token;
        stringstream ssf(formula);
        int result=0;
        while(getline(ssf,token,'+')){
            result+=eval(token);
        }
        return result;
    }
};

int main(){
    Spreadsheet2 sd2(4);
    sd2.setCell("A1",20);
    sd2.setCell("B3",10);
    sd2.setCell("C2",30);
    sd2.setCell("D1",20);

    cout<<sd2.getValue("=A1+B3")<<endl;
    sd2.resetCell("A1");
    cout<<sd2.getValue("=A1+B3")<<endl;
return 0;
}