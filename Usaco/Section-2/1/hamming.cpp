/*
ID:goksgie2
PROG: hamming
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int countOnes(int test){
	int count = 0;
	while(test > 0){
		if((test & 1) == 1) count++;
		test = test >> 1;
	}
	return count;
}

int main(){
	ifstream f_in("hamming.in");
	ofstream f_out("hamming.out");
	int N,B,D;
	f_in >> N >> B >> D;
	int maxNumber = pow(2,B) - 1;
	vector<int> solution;
	bool flagAdd = true;
	bool flagStop = false;
	// brute force solution. generate solution starting from 0 to 2^B-1
	// and for each starting point, try adding every number between start point and end point
	// by checking its distance to every element that is added to the solution array
	// and checking distance can be done with simple operation XOR
	for(int i =0; i<maxNumber; i++){
		solution.push_back(i);
		for(int j = i+1; j<=maxNumber; j++){
			flagAdd = true;
			for(int m = 0; m<solution.size(); m++){
				int test = j ^ solution[m];
				if(countOnes(test) < D){
					flagAdd = false;
					break;
				}
			}
			if(flagAdd) solution.push_back(j);
			if(solution.size() == N){
				flagStop = true;
				break;
			}
		}
		if(flagStop) break;
		solution.clear();
	}
	int t;
	for( t =1; t<=solution.size(); t++){
		f_out<<solution[t-1];
		if(t%10 == 0) f_out<<endl;
		else if(t!=solution.size()) f_out<<" ";
	}
	if((t-1)%10 != 0) f_out<<endl;
}