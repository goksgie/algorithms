/*
ID:goksgie2
PROG: numtri
LANG: C++11
*/
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

vector<pair<int,int>> nodes;

int findMaxPath(int current, int layer){
	if(current+layer > nodes.size()) return nodes[current].first;
	pair<int,int>* currentNode = &nodes[current];
	if(currentNode->second == -1){
		int next = current+layer;
		int temp = max(findMaxPath(next,layer+1),findMaxPath(next+1,layer+1));
		currentNode->second=temp+currentNode->first;
		return currentNode->second;
	}
	else return currentNode->second;
}

int main(){
	ifstream f_in("numtri.in");
	ofstream f_out("numtri.out");
	int R;
	int temp;
	f_in>>R;
	int i=1;
	while(i<=R){
		for(int j =0; j<i; j++){
			f_in>>temp;
			nodes.push_back(make_pair(temp,-1));
		}
		i++;
	}
	f_out<<findMaxPath(0,1)<<endl;
}