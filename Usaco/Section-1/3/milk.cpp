/*
ID:goksgie2
PROG: milk
LANG: C++11
*/
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

bool funsort(pair<int,int> x, pair<int,int> y){
	return x.first<y.first;
}

int main(){
	ifstream cix("milk.in");
	ofstream cox("milk.out");
	vector<pair<int,int>> choices;
	int goal, farmers;
	int punit, tunit;
	int i;
	pair<int,int> temp;
	int cost = 0;
	cix>>goal>>farmers;
	for(i=0; i<farmers; i++){
		cix>>punit>>tunit;
		choices.push_back(make_pair(punit, tunit));
	}
	sort(choices.begin(),choices.end(), funsort);
	for(i=0; i<farmers; i++){
		temp = choices[i];
		if(temp.second < goal){
			cost+=temp.first*temp.second;
			goal-=temp.second;
		}
		else if(temp.second == goal){
			cost+=temp.first*temp.second;
			break;
		}
		else{
			cost+=temp.first*goal;
			break;
		}
	}
	cox<<cost<<endl;
}