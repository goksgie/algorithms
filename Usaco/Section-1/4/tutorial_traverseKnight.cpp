#include <iostream>

using namespace std;

int moveSet_x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int moveSet_y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool isValid(int n,int pos_x, int pos_y, int move_x, int move_y){
	int cond1 = pos_x + move_x;
	int cond2 = pos_y + move_y;
	if(cond1 >= n || cond2 >= n || cond1 <0 || cond2 < 0) return false;
	return true;
}

void printBoard(int n, int** board){
	for(int i =0; i< n; i++){
		for(int j=0; j<n; j++) cout<<board[i][j]<<" ";
		cout<<endl;
	}
}

void traverseOne(int n, int** board, int pos_x,int pos_y,int occupied){
	if(occupied == n*n){
		printBoard(n,board);
		return;
	}
	for(int i =0; i< 8; i++){
		int move_x = moveSet_x[i];
		int move_y = moveSet_y[i];
		if(isValid(n,pos_x,pos_y,move_x,move_y)){
			if(board[pos_x+move_x][pos_y+move_y] == 0){
				pos_x+=move_x; 
				pos_y+=move_y;
				board[pos_x][pos_y] = occupied+1;
				traverseOne(n,board,pos_x,pos_y,occupied+1);
				board[pos_x][pos_y] = 0;
			}
		}
	}
}

void TraverseAll(int n){
	int *board[n];
	for(int i = 0; i< n; i++){
		board[i] = new int[n];
		for(int j = 0; j<n; j++){
			cout<<board[i][j];
		}
	}
	int pos_initial = 0; int pos_x,pos_y;
	int limit = n*n;
	while(pos_initial < limit){
		pos_x = pos_initial/n;
		pos_y = pos_initial%n;
		board[pos_x][pos_y] = 1;
		traverseOne(n,board,pos_x,pos_y,1);
		board[pos_x][pos_y] = 0;
		pos_initial++;
	}
	for(int i = 0; i<n ;i ++){
		delete[] board[i];
	}
}

int main(){
	int N;
	cin>>N;
	TraverseAll(N);
}