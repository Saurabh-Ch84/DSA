#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Brute Force
class MedianFinder1{
    int n;
    vector<int> arr;
public:
    MedianFinder1():n(0){}
    
    void addNum(int num) {
        arr.push_back(num);
        n++;
        sort(begin(arr),end(arr));
    }
    
    double findMedian(){
        if(n%2==1) return (double)arr[n/2];
        return ((double)arr[n/2]+(double)arr[(n-1)/2])/2.0;
    }
};

//optimal
class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> pqMin;
    priority_queue<int> pqMax;

    void balance(){
        if(pqMax.size()>pqMin.size()+1){
            int temp=pqMax.top();
            pqMax.pop();
            pqMin.push(temp);
        }
        else if(pqMin.size()>pqMax.size()){
            int temp=pqMin.top();
            pqMin.pop();
            pqMax.push(temp);
        }
    }
public:
    MedianFinder(){}
    
    void addNum(int num) {
        if(pqMax.empty() || num<=pqMax.top()) pqMax.push(num);
        else pqMin.push(num);
        balance();
    }
    
    double findMedian(){
        if(pqMax.size()==pqMin.size()) return (double)(pqMax.top()+pqMin.top())/2.0;
        return (double)pqMax.top();
    }
};

int main(){
    MedianFinder m;
    m.addNum(-1);
    cout<<m.findMedian()<<endl;
    m.addNum(-2);
    cout<<m.findMedian()<<endl;
    m.addNum(1);
    m.addNum(8);
    cout<<m.findMedian()<<endl;
    m.addNum(11);
    cout<<m.findMedian()<<endl;
return 0;
}