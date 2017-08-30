/*
ID:goksgie2
PROG: barn1
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int m,s,c;
	int temp, max;
	int i;
	ifstream cix("barn1.in");
	ofstream cox("barn1.out");
	vector<int> cows;
	vector<int> gaps;
	cix>>m>>s>>c;
	for(i =0; i<c; i++){
		cix>>temp;
		cows.push_back(temp);
	}
	sort(cows.begin(),cows.end());
	for(i =0;i<c-1;i++){
		gaps.push_back(cows[i+1]-cows[i]-1);
	}
	sort(gaps.begin(),gaps.end());
	temp = c;
	max = c;
	i = 0;
	while(temp>m){
		max+=gaps[i];
		i++;
		temp--;
	}
	cox<<max<<endl;
}