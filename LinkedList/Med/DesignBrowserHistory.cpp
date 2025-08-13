#include<iostream>
using namespace std;

class BrowserHistory {
    class DLListNode{
            public:
        string data;
        DLListNode *prev,*next;
        DLListNode(string data=""){
            this->data=data;
            prev=nullptr;
            next=nullptr;
        }
    };
public:
    DLListNode *home,*currPage;
    BrowserHistory(string homepage) {
        home=new DLListNode(homepage);
        currPage=home;
    }
    
    void visit(string url) {
        DLListNode *newPage=new DLListNode(url);
        if(currPage->next){
            DLListNode *delNode=currPage->next;
            delNode->prev=nullptr;
            while(delNode){
                DLListNode *DelNode=delNode;
                delNode=delNode->next;
                delete DelNode;
            }
            currPage->next=nullptr;
        }
        currPage->next=newPage;
        newPage->prev=currPage;
        currPage=newPage;
    }
    
    string back(int steps) {
        DLListNode *mover=currPage;
        while(steps && mover!=home){
            steps--;
            mover=mover->prev;
        }
        currPage=mover;
        return currPage->data;
    }
    
    string forward(int steps) {
        DLListNode *mover=currPage;
        while(steps && mover->next){
            steps--;
            mover=mover->next;
        }
        currPage=mover;
        return currPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){

return 0;
}