/*
ID:goksgie2
PROG: transform
LANG: C++11
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

bool compare(vector<string>& first, vector<string>& second, int type, int N){
	int flag = 0;
	switch(type){
		case 1:
			for(int i =0; i<N; i++){
				for(int j=0; j< N; j++){
					if(first[i][j] != second[j][N-1-i]){
						return false;
					}
				}
			}
			return true;
		case 2:
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if(first[i][j] != second[N-1-i][N-1-j]) return false;
				}
			}
			return true;
		case 3:
			for(int i =0; i<N; i++){
				for(int j=0; j<N; j++){
					if(first[i][j] != second[N-1-j][i]) return false;
				}
			}
			return true;
		case 4:
			for(int i =0; i<N; i++){
				for(int j=0; j<N; j++){
					if(first[i][j] != second[i][N-1-j]) return false;
				}
			}
			return true;
		case 5:
			//4+1
			
			for(int i=0; i<N; i++){
				for(int j=0; j< N; j++){
					if(first[i][j] != second[N-1-j][N-1-i]){flag = 1; break;}
				}
			}
			//4+2
			if(flag == 1)
				for(int i=0; i<N; i++){
					for(int j=0; j< N; j++){
						if(first[i][j] != second[N-1-i][j]) {flag = 2; break;}
					}
				}
			//4+3
			if(flag == 2)
				for(int i=0; i<N; i++){
					for(int j=0; j< N; j++){
						if(first[i][j] != second[j][i]) return false;
					}
				}
			return true;
		case 6:
			for(int i=0; i<N; i++){
				for(int j =0; j<N; j++){
					if(first[i][j]!=second[i][j]) return false;
				}
			}
			return true;
	}
	return false;
}

int main(){
	ifstream cix("transform.in");
	ofstream cox("transform.out");
	int N;
	vector<string> first;
	vector<string> second;
	string helper;
	cix>> N;
	cix.ignore();
	for(int i =0; i<N; i++){
		getline(cix, helper);
		first.push_back(helper);
	}
	for(int i =0; i< N; i++){
		getline(cix, helper);
		second.push_back(helper);
	}
	for(int i =0; i<7; i++){
		if(compare(first,second, i, N)){
			cox<<i<<endl;
			return 0;
		}
	}
	cox<<7<<endl;
	return 0;
}