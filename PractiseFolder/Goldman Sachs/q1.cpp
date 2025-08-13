#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> &field){
    for(string &row:field){
        for(char &ch:row)
            cout<<ch<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int countPairsOfRectangularLand(vector<string> &field){
    int result=-1;
    return result;
}

int main(){
    int n;
    cout<<"Enter the size of square field:- ";
    cin>>n;
    vector<string> field(n);
    cout<<"Remember 'C' represents agricultural and 'B' represents barren Land in the field:- "<<endl;
    cin.ignore(); //Removes '\n' character from input buffer
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"th row of the field:-";
        string temp;
        getline(cin,temp);
        field[i]=temp;
    }
    print(field);
    cout<<"The Number of distinct rectangular field pairs is "<<countPairsOfRectangularLand(field)<<endl;
return 0;
}