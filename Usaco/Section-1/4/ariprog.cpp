/*
ID:goksgie2
PROG: ariprog
LANG: C++11
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<int> bisquares;
vector<int> numbers;

bool customCompare(pair<int,int>& prev, pair<int,int>& next){
	if(prev.second > next.second) return false;
	if(prev.second < next.second) return true;
	if(prev.second == next.second){
		return (prev.first < next.first) ? true:false;
	}
}

void constructBisquares(int m){
	int number;
	for(int i =0; i<=m; i++){
		for(int j=i; j<=m; j++){
			number = i*i+j*j;
			if(numbers[number] == 0){
				bisquares.push_back(number);
				numbers[number] = 1;
			}
		}
	}
}

bool ifSequence(int& n,int len, int next,int& distance){
	if(len == n) return true;
	if(next >= numbers.size()) return false;
	if(numbers[next] == 0) return false;
	
	ifSequence(n,len+1,next+distance,distance);
}

void findSequence(int& n,int& m, vector<pair<int,int>>& foundSequences){
	int i=0;
	int distance;
	int upper = 2*m*m;
	int temp;
	while(i <= bisquares.size()){
		distance=1;
		temp = i+distance;
		while(temp<=bisquares.size()){
			if(ifSequence(n,0,bisquares[i],distance)){
				foundSequences.push_back(make_pair(bisquares[i],distance));
			}
			distance++;
			temp++;
		}
		i++;
	}
}

int main(){
	ifstream f_in("ariprog.in");
	ofstream f_out("ariprog.out");
	int N, M;
	f_in>>N>>M;
	numbers.resize(2*M*M+1);
	constructBisquares(M);
	vector<pair<int,int>> foundSequences;
	findSequence(N,M,foundSequences);
	sort(foundSequences.begin(),foundSequences.end(),customCompare);
	if(foundSequences.size() == 0) {
		f_out<<"NONE"<<endl;
		return 0;
	}
	for(int i =0; i<foundSequences.size(); i++){
		f_out<<foundSequences[i].first<<" "<<foundSequences[i].second<<endl;
	}
	return 0;
}