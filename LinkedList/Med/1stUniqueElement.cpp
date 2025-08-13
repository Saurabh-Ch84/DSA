#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

/*You have a queue of integers, you need to retrieve the first unique integer in the queue.
Implement the FirstUnique class:
FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
The number of calls to showFirstUnique and add is at most 5000.
0 <= value <= 10^9
At most 50000 calls will be made to showFirstUnique and add.
The number of elements in the initial array nums is between 1 and 10^5.*/

class FirstUnique {
    
    list<int> uniqueList;
    unordered_map<int,list<int>::iterator> frequencyChecker;

    public:
        FirstUnique(vector<int>& nums)
        {
            for(auto itr: nums)
            {
                add(itr);
            }
        }
        
        int showFirstUnique()
        {
            if(uniqueList.size()!=0)
                return uniqueList.front();
            return -1;
        }
        
        void add(int value)
        {
                if(frequencyChecker.find(value)==frequencyChecker.end())
                {
                    uniqueList.push_back(value);
                    frequencyChecker[value]=--uniqueList.end();
                }
                else
                {
                    if(frequencyChecker[value]!=uniqueList.end())
                    {
                        uniqueList.erase(frequencyChecker[value]);
                        frequencyChecker[value]=uniqueList.end();
                    }
                }
        }

        void display()
        {
            for(auto itr:uniqueList)
                cout<<itr<<" ";
            cout<<endl;
        }
    };
    
    /**
     * Your FirstUnique object will be instantiated and called as such:
     * FirstUnique* obj = new FirstUnique(nums);
     * int param_1 = obj->showFirstUnique();
     * obj->add(value);
     */
    
int main(){
    int s;
    cout<<"Size:";
    cin>>s;
    vector<int> vec(s);
    for(int i=0;i<s;i++)
    {
        cin>>vec[i];
    }
    FirstUnique* obj = new FirstUnique(vec);
    int val;
    int choice=1;
    while(choice)
    {
        cout<<"\t MENU"<<endl;
        cout<<"Enter 1 to add a value:"<<endl;
        cout<<"Enter 2 to find first unique value:"<<endl;
        cout<<"Enter 3 to display the contents:"<<endl;
        cout<<"Enter 0 to quit."<<endl;
        cout<<"Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be added:";
            cin>>val;
            obj->add(val);
            break;
        case 2:
            cout<<"First Unique Value:";
            cout<<obj->showFirstUnique()<<endl;
            break;
        case 3:
            cout<<"Queue is :";
            obj->display();
            break;
        default:
            break;
        }
    }
return 0;
}