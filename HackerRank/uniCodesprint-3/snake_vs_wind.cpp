#include <iostream>
#include <vector>
#define MAX 60

using namespace std;
int square[MAX][MAX];
char direction;
int n;
pair<int,int> wind;
pair<int,int> getWind(){
    pair<int,int> windy;
    switch(direction){
        case 'n':
            windy = make_pair(-1,0);
            break;
        case 's':
            windy = make_pair(1,0);
            break;
        case 'e':
            windy = make_pair(0,1);
            break;
        case 'w':
            windy = make_pair(0,-1);
            break;
    }
    return windy;
}

bool canMoveAbove(int x, int y){
    if((x-1) < 0) return false;
    if(square[x-1][y] != 0) return false;
    return true;
}

bool canMoveBelow(int x, int y){
    if((x+1) >= n) return false;
    if(square[x+1][y] != 0) return false;
    return true;
}

bool canMoveRight(int x, int y){
    if((y+1) >= n) return false;
    if(square[x][y+1] != 0) return false;
    return true;
}

bool canMoveLeft(int x, int y){
    if((y-1) < 0) return false;
    if(square[x][y-1] != 0) return false;
    return true;
}

bool canMoveWith(int x, int y){
    int wx = wind.first;
    int wy = wind.second;
    int ce1 = wx+x;
    int ce2 = wy+y;
    if((ce1 < 0) || (ce2 < 0) || (ce1 >= n) || (ce2 >=n)) return false;
    if(square[ce1][ce2] != 0) return false;
    return true;
}

bool canMovePerp(int x, int y){
    int wx = wind.first;
    int wy = wind.second;
    if(wx == 0){
        return (canMoveAbove(x,y) || canMoveBelow(x,y));
    }
    else return (canMoveRight(x,y) || canMoveLeft(x,y));
}

bool canMoveOpo(int x, int y){
    int wx = wind.first;
    int wy = wind.second;
    int ce1 = x-wx;
    int ce2 = y-wy;
    if((ce1 < 0) || (ce2 < 0) || (ce1 >= n) || (ce2 >=n)) return false;
    if(square[ce1][ce2] != 0) return false;
    return true;
}

void moveWith(int& x, int& y){
    x+=wind.first;
    y+=wind.second;
}
void moveOpo(int& x, int& y){
    x-=wind.first;
    y-=wind.second;
}

void movePerp(int& x, int& y){
    int wx = wind.first;
    int wy = wind.second;
    if(wx == 0){
        if(canMoveAbove(x,y)){
            x-=1;
        }
        else if(canMoveBelow(x,y)){
            x+=1;
        }
    }
    else{
        if(canMoveRight(x,y)){
            y+=1;
        }
        else if(canMoveLeft(x,y)){
            y-=1;
        }
    }
}

void solve(int x, int y){
    wind = getWind();
    int traversed = 1;
    int goal = n*n;
    square[x][y] = traversed;
    while(traversed != goal){
        if(canMoveWith(x,y)){
            moveWith(x,y);
        }
        else if(canMovePerp(x,y)){
            movePerp(x,y);
        }
        else if(canMoveOpo(x,y)){
            moveOpo(x,y);
        }
        else break;
        traversed++;
        //cout<<x<<" ? "<<y<<endl;
        square[x][y] = traversed;
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<square[i][j];
            if(j!=(n-1)) cout<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int x, y;
    cin>>n>>direction>>x>>y;
    solve(x,y);
    return 0;
}