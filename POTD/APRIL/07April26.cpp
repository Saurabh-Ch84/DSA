#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Robot {
    vector<string> directions;
    int x,y,z,h,w,p;

    int nearestBoundaryDistance(){
        if(z==0) return w-1-x;
        else if(z==1) return y;
        else if(z==2) return x;
        return h-1-y;
    }

    void move(int k){
        if(z==0) x=x+k;
        else if(z==1) y=y-k;
        else if(z==2) x=x-k;
        else y=y+k;
    }

    void rotateAnticlockwise(){
        z=(z+1)%4;
    }
public:
    Robot(int width, int height) {
        directions={"East","North","West","South"};
        w=width, h=height, z=0, x=0, y=h-1;
        p=2*(w + h)-4;
    }

    void step(int num) {
        num = num % p;
        // THE FIX:
        if (num == 0) {
            // If we did a full loop and ended up at the starting corner, 
            // we must have traveled down the left wall, so we face South.
            if (x == 0 && y == h - 1) {
                z = 3; 
            }
            return; 
        }
        int d=nearestBoundaryDistance();
        while(num>d){
            move(d);
            rotateAnticlockwise();
            num-=d;
            d=nearestBoundaryDistance();
        }
        move(num);
    }
    
    vector<int> getPos() {
        return {x,h-1-y};
    }
    
    string getDir() {
        return directions[z];
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vint stableMarriage(vvint &men,vvint &women) {
        // code here
        int n=men.size();
        vvint womenRank(n,vint(n,n));
        queue<int> freeMenQ;
        
        for(int i=0;i<n;i++){
            freeMenQ.push(i);
            vint &preference=women[i];
            int w=i, k=preference.size();
            for(int j=0;j<k;j++)
                womenRank[w][preference[j]]=j;
        }
        
        vint womenDecide(n,-1), menPropose(n,0);

        while(!freeMenQ.empty()){
            int m=freeMenQ.front();
            int w=men[m][menPropose[m]];
            if(womenDecide[w]==-1){
                womenDecide[w]=m;
                freeMenQ.pop();
            }
            else if(womenRank[w][m]<womenRank[w][womenDecide[w]]){
                freeMenQ.push(womenDecide[w]);
                womenDecide[w]=m;
                freeMenQ.pop();
            }
            menPropose[m]++;
        }
        
        vint menPerspective(n,-1);
        for(int i=0;i<n;i++){
            int m=womenDecide[i];
            menPerspective[m]=i;
        }
        
        return menPerspective;
    }
};

int main(){

return 0;
}