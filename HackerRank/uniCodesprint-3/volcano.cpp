#include <vector>
#include <iostream>
#define MAX 300
int landscape[MAX][MAX];
int n;
int maxImpact = -1;
using namespace std;


void explodeAbove(int x, int y, int w, int level){
    int count = 0;
    while(x >= 0 && w !=0){
        landscape[x][y]+=w;
        maxImpact = max(maxImpact, landscape[x][y]);
        if(level == count) w--;
        else count++;
        x--;
    }
}

void explodeBelow(int x, int y, int w, int level){
    int count = 1;
    while(x < n && w!=0){
        landscape[x][y]+=w;
        maxImpact = max(maxImpact, landscape[x][y]);
        if(level <= count) w--;
        else count++;
        x++;
    }
}

void explodeRight(int x, int y, int w){
    int level = 0;
    while(y < (n-1) && w != 0){
        w--;
        level++;
        y++;
        explodeAbove(x,y,w,level);
        explodeBelow(x+1,y,w,level);
    }
}

void explodeLeft(int x, int y, int w){
    int level = 0;
    while(y>0 && w!=0){
        level++;
        w--;
        y--;
        explodeAbove(x,y,w,level);
        explodeBelow(x+1,y,w,level);
    }
}

void explode(int x, int y, int w){
    explodeAbove(x,y,w,0);
    explodeBelow(x+1,y,w-1,0);
    explodeRight(x,y,w);
    explodeLeft(x,y,w);
}

int main() {
    int m,x,y,w;
    cin>>n>>m;
    for(int i =0; i<m; i++){
        cin>>x>>y>>w;
        explode(x,y,w);
        /*
        for(int j = 0; j< n; j++){
            for(int k = 0; k<n; k++){
                cout<<landscape[j][k]<<" ";
            }
            cout<<endl;
        }
        */
    }
    cout<<maxImpact<<endl;
    return 0;
}