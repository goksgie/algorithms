/*
ID:goksgie2
PROG: palsquare
LANG: C++11
*/
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

bool check_pal(string& tobe){
	int size_over = tobe.size()/2;
	int size = tobe.size();
	for(int i =0; i<size_over; i++){
		if(tobe[i]!=tobe[size-1-i]) return false;
	}
	return true;
}
void base_converter(int n, int b, string& result){
	if(n == 0){
		return;
	}
	base_converter(n/b,b,result);
	int k = n%b;
	if(k >= 10){
		k-=10;
		char c = 'A'+k;
		result+=c;
	}
	else
		result.append(to_string(k));
}

int main(){
	ifstream cix("palsquare.in");
	ofstream cox("palsquare.out");
	int b;
	int temp;
	cix>>b;
	string result;
	string toko;
	for(int i=1; i<=300; i++){
		temp = pow(i,2);
		base_converter(temp,b,result);
		//base_converter(i,b,toko);
		//cox<<"power of i:"<<i<<"="<<toko<<"="<<temp<<" in base b:"<<b<<" "<<result<<endl;
		if(check_pal(result)){
			//cox<<"found one:"<<endl;
			base_converter(i,b,toko);
			cox<<toko<<" "<<result<<endl;
			
		}
		toko.clear();
		result.clear();
	}
}