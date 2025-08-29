#include<iostream>
using namespace std;

class Animal{
        public:
    void walking(){
        cout<<"I walk"<<endl;
    }

    void sound(){
        cout<<"I make sounds"<<endl;
    }

    virtual void eating()=0; //pure virtual function

    virtual ~Animal() {}
};

class Herbivore:public Animal{
        public:
    void eating(){
        cout<<"I eat veggies, grass and plants."<<endl;
    }
};

class Carnivore:public Animal{
        public:
    void eating(){
        cout<<"I eat meat and non-veg."<<endl;
    }
};

class Omnivore:public Animal{
        public:
    void eating(){
        cout<<"I eat meat as well as veggies, grass and plants."<<endl;
    }
};

int main(){
    Animal* a=new Carnivore();
    a->sound();
    a->eating(); //runtime polymorphism
    delete a;
    
    Omnivore o; 
    o.walking();
    o.eating(); 
return 0;
}