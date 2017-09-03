/*
ID:goksgie2
PROG: sprime
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

map<int,int> seenPrimes;
int tempArray[6] = {1,2,3,5,7,9};
bool isPrime(long  object){
	long  boundary = sqrt(object);
	if(object == 1) return false;
	for(long  i=2; i<=boundary; i++){
		if(object % i == 0) return false;
	}
	return true;
}

void findSprimes(long currentNumber,int currentLayer,int& maxLayer, ofstream& f_out){
	if(currentLayer > maxLayer) return;
	for(long i =0; i<6; i++){
		long temp = currentNumber*10+tempArray[i];
		if(isPrime(temp)){
			if(currentLayer == maxLayer) f_out<<temp<<endl;
			else
				findSprimes(temp,currentLayer+1,maxLayer,f_out);
		}
	}
}
int main(){
	ifstream f_in("sprime.in");
	ofstream f_out("sprime.out");
	int n;
	f_in>>n;
	findSprimes(0,1,n,f_out);
	return 0;
}