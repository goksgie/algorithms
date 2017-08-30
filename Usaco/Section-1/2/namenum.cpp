/*
ID:goksgie2
PROG: namenum
LANG: C++11
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
//useful items:
map<string, int> valid_list;
vector<string> results;
vector<string> phonetab {"", "", "ABC", "DEF", "GHI","JKL","MNO","PRS","TUV","WXY"};
//

void checkin(string result){
	map<string,int>::iterator it = valid_list.find(result);
	if(it != valid_list.end()){
		if(it->second==0){
			results.push_back(result);
			it->second =1;
		}
			
	}
}

void generate(string& numbers, int size, int point, string& result){
	int kyoto=numbers[point] - '0';
	if(size == point){
		result[point] = phonetab[kyoto][0];
		checkin(result);
		result[point] = phonetab[kyoto][1];
		checkin(result);
		result[point] = phonetab[kyoto][2];
		checkin(result);
		return;
	}
	result[point] = phonetab[kyoto][0];
	checkin(result);
	generate(numbers, size,point+1,result);
	
	result[point] = phonetab[kyoto][1];
	checkin(result);
	generate(numbers, size,point+1,result);

	result[point] = phonetab[kyoto][2];
	checkin(result);
	generate(numbers, size,point+1,result);


	
}

int main(){
	ifstream dict("dict.txt");
	ifstream cix("namenum.in");
	ofstream cox("namenum.out");
	string valids;
	int point = 0;
	int n;
	while(getline(dict,valids)){
		valid_list[valids] = 0;
	}
	getline(cix, valids);
	n = valids.size();
	string inputs(n, 'q');
	generate(valids, n-1, point,inputs);
	if(results.empty()){
		cox<<"NONE"<<endl;
	}
	sort(results.begin(),results.end());
	n = results.size();
	for(int i =0; i<n; i++){
		cox<<results[i]<<endl;
	}
}
