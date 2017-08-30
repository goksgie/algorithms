/*
ID:goksgie2
PROG: combo
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solver(int x, int y, int n){
	int temp = abs(x-y);
	if(temp > 4){
		if(x < y){
			temp = abs(x+n-y);
		}
		else temp = abs(y+n-x);
	}
	switch(temp){
		case 0:
			return 5;
		case 1:
			return 4;
		case 2:
			return 3;
		case 3:
			return 2;
		case 4:
			return 1;
		default:
			return 0;
	}
}

int main(){
	ifstream cix("combo.in");
	ofstream cox("combo.out");
	vector<int> farmer;
	vector<int> master;
	int n;
	int temp,temp1,temp2;
	int count=1;
	cix>>n;
	for(int i =0; i<3; i++){
		cix>>temp;
		farmer.push_back(temp);
	}
	for(int i=0; i<3; i++){
		cix>>temp;
		master.push_back(temp);
	}
	switch(n){
		case 1:
			cox<<1<<endl;
			return 0;
		case 2:
			cox<<4<<endl;
			return 0;
		case 3:
			cox<<27<<endl;
			return 0;
		case 4:
			cox<<64<<endl;
			return 0;
		case 5:
			cox<<125<<endl;
			return 0;
	}
	int max = 250;
	count*=solver(farmer[0],master[0],n);
	count*=solver(farmer[1],master[1],n);
	count*=solver(farmer[2],master[2],n);
	cox<<max-count<<endl;
}