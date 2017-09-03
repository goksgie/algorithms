/*
ID:goksgie2
PROG: pprime
LANG: C++11
*/
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

long long lower,upper;

bool isPrime(long long object){
	long long boundary = sqrt(object);
	for(long long i=2; i<=boundary; i++){
		if(object % i == 0) return false;
	}
	return true;
}

void generatePalindromes(int number, bool odd, ofstream& f_out){
	long long palin = number;
	long long temp = number;
	if(odd) temp/=10;
	while(temp>0){
		palin = palin*10+temp%10;
		temp/=10;
	}
	if(palin <= upper && palin >= lower){
		if(isPrime(palin)) f_out<<palin<<endl;
	}
}

void gen(int li, int hi, ofstream& f_out){
	for(int i =li; i<=hi; i++)
		generatePalindromes(i,true,f_out);
	for(int i =li; i<=hi; i++)
		generatePalindromes(i,false,f_out);
}

void findPalindromes(){
	ofstream f_out("pprime.out");
	gen(1,9,f_out);
	gen(10,99,f_out);
	gen(100,999,f_out);
	gen(1000,9999,f_out);
}

int main(){
	ifstream f_in("pprime.in");
	f_in>>lower>>upper;
	//findPrimes(lower,upper);
	findPalindromes();
}