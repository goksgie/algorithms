/*
ID:goksgie2
PROG: wormhole
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
#define n_max 12
int n;

vector<pair<int,int>> data(n_max+1);
vector<int> pairs(n_max+1,0);
vector<int> next_on_right(n_max+1, 0);

bool solve(void){
	int pos;
	for(int start = 1; start<=n; start++){
		pos = start;
		for(int count = 0; count<n; count++){
			pos = next_on_right[pairs[pos]];
		}
		if(pos != 0) return true;
	}
	return false;
}

int generate(void){
	int i; int total =0;
	for(i=1; i<=n; i++)
		if(pairs[i] == 0) break;

	if(i>n){
		if(solve()) return 1;
		else return 0;
	}

	for(int j=i+1; j<=n; j++){
		if(pairs[j] == 0){
			pairs[i]=j;
			pairs[j]=i;
			total+=generate();
			pairs[i] = pairs[j] = 0;
		}
	}
	return total;
}

int main(){
	ifstream cix("wormhole.in");
	ofstream cox("wormhole.out");
	int x,y;
	int count=0;
	
	cix>>n;
	
	for(int i =1; i<=n; i++){
		cix>>x>>y;
		data[i]=make_pair(x,y);
	}
	cix.close();
	for(int i =1; i<=n; i++){
		for(int j= 1; j<=n; j++){
			if(data[j].first > data[i].first && data[j].second == data[i].second)
				if(next_on_right[i] == 0 || data[j].first-data[i].first < data[next_on_right[i]].first - data[i].first)
					next_on_right[i] = j;
		}
	}
	cox<<generate()<<endl;
	cox.close();
}