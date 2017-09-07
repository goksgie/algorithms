/*
ID:goksgie2
PROG: frac1
LANG: C++11
*/
#include <vector>
#include <fstream>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;

//priority queue is used
struct myComp{
	bool operator()(const pair<int,int>&f1, const pair<int,int>& f2){
		int u1 = f1.first*f2.second;
		int u2 = f2.first*f1.second;
		return (u1>u2);
	}
};

pair<int,int> normalize(int x, int y){
	for(int i = x; i>1; i--){
		if((y % i == 0) && (x%i == 0)){
			return make_pair(x/i,y/i);
		}
	}
	return make_pair(x,y);
}

bool isSeen(vector<pair<int,int>>& seens, const pair<int,int>& current){
	auto new_current = normalize(current.first, current.second);
	for(int i = 0; i<seens.size(); i++){
		if(seens[i].first == new_current.first && seens[i].second == new_current.second){
			return true;
		}
	}
	seens.push_back(new_current);
	return false;
}

int main(){
	ifstream f_in("frac1.in");
	ofstream f_out("frac1.out");
	int N;
	f_in>> N;
	vector<pair<int,int>> fractions(N);
	for(int i =1; i<=N; i++){
		fractions[i-1] = make_pair(1,i);
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> myQueue(fractions.begin(),fractions.end());
	f_out<<0<<"/"<<1<<endl;
	vector<pair<int,int>> seens;
	while(!myQueue.empty()){
		auto top = myQueue.top();
		myQueue.pop();
		if(top.first!=top.second){
			if(!isSeen(seens,top)){
				auto next = normalize(top.first, top.second);
				f_out<<next.first<<"/"<<next.second<<endl;
			}
			myQueue.push(make_pair(top.first+1,top.second));
		}
	}
	f_out<<1<<"/"<<1<<endl;
	return 0;
}