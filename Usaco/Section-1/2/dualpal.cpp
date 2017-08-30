/*
ID:goksgie2
PROG: dualpal
LANG: C++11
*/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

bool check_pal(string& tobe){
	if(tobe[0] == '0') return false;
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
	/*if(k >= 10){
		k-=10;
		char c = 'A'+k;
		result+=c;
	}
	else*/
	result.append(to_string(k));
}

int main(){
	ifstream cix("dualpal.in");
	ofstream cox("dualpal.out");
	int n,s;
	int count;
	cix>>n>>s;
	string result;
	int i = s+1;
	while(n>0){
		count = 0;
		for(int j=2; j<=10; j++){
			if(i < j){
				count++;
				if(count >=2){
					cox<<i<<endl;
					count = 0;
					n--;
					break;
				}
			}
			else{
				result.clear();
				base_converter(i,j,result);
				if(check_pal(result)){
					count++;
					if(count>=2){
						cox<<i<<endl;
						count =0;
						n--;
						break;
					}
				}
			}
			
		}
		i++;
	}
}