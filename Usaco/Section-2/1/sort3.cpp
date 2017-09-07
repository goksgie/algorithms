/*
ID:goksgie2
PROG: sort3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	ifstream f_in("sort3.in");
	ofstream f_out("sort3.out");
	int N;
	f_in >> N;
	vector<int> sequence(N);
	int frequency[3] = {0,0,0};
	int i;
	int j,m;
	int ones_count=0; int twos_count = 0;
	int swap_count = 0;
	for(i =0; i< N; i++){
		f_in>>sequence[i];
		if(sequence[i] == 1) ones_count++;
		else if(sequence[i] == 2) twos_count++;
	}
	//swap ones with twos
	for(i = ones_count; i<N; i++){
		if(sequence[i] == 1){
			for(j = m = 0; j<ones_count; j++){
				//there is a 2 in range(0,ones_count) ready to be swapped with 1.
				if(sequence[j] == 2){
					m=j;
					break;
				} // if there is no 2s in range(0,ones_count) then swap last 3 with 1
				else if(sequence[j] == 3){
					m=j;
				}
			}
			swap(sequence[i],sequence[m]);
			swap_count++;
		}
	} // handle the last partition of array where 3s are supposed to be placed
	// since all the ones are replaced, seek for 2s at last partition and increase count on find

	for(i=ones_count+twos_count; i< N; i++){
		if(sequence[i] == 2) swap_count++;
	}
	f_out<<swap_count<<endl;
}