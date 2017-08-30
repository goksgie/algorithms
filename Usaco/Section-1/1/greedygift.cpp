/*
ID:goksgie2
PROG: gift1
LANG: C++11
*/
#include <fstream>
#include <map>
#include <utility>
using namespace std;

int main()
{
	ofstream oc;
	ifstream mc;
	mc.open("gift1.in");
	oc.open("gift1.out");
	

	map<string, int> storage;
	int NP, money, giftos, plusy;
	string name;
	

	mc>>NP;
	
	string ar[NP];
	for(int i=0; i!=NP; i++){
		mc>>ar[i];
		storage[ar[i]]=0;
	}

	while(!mc.eof()){
		mc>>name;
		mc>>money>>giftos;
		if(giftos!=0){
			plusy = money/giftos;
			storage[name]-= plusy*giftos;
		}
		else{
			plusy = 0;
		}
		for(int i=0; i!=giftos;i++){
			mc>>name;
			storage[name]+=plusy;
		}
	}

	for(int i=0; i!= NP; i++){
		oc<<ar[i]<<" "<<storage[ar[i]]<<endl;
	}
	return 0;

}
