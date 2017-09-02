/*
ID:goksgie2
PROG: milk3
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<int> solutions;
vector<int> bucketSizes;
map<string,int> visitedNodes;

string make_string(int a, int b, int c){
	return string(to_string(a)+to_string(b)+to_string(c));
}
void printSolution(ofstream& f_out){
	sort(solutions.begin(),solutions.end());
	solutions.resize(unique(solutions.begin(),solutions.end())-solutions.begin());
	for(int i =0; i<solutions.size(); i++){
		f_out<<solutions[i];
		if(i!=solutions.size()-1) f_out<<" ";
	}
	f_out<<endl;
}

int transferMilk(int target, int& targetCurrent, int& fromCurrent){
	//int arr[2];
	int x = fromCurrent;
	int spaceTarget = bucketSizes[target] - targetCurrent;
	if(spaceTarget >= fromCurrent) {
		targetCurrent+=fromCurrent;
		fromCurrent = 0;
	}
	else if(spaceTarget < fromCurrent){
		targetCurrent = bucketSizes[target];
		fromCurrent -= spaceTarget;
	}
	return x - fromCurrent;
	//return arr;
}
void solve(int a, int b, int c){
	if(a == 0) solutions.push_back(c);
	int tmp;
	string temp = make_string(a,b,c);
	auto iterator = visitedNodes.find(temp);
	if(iterator == visitedNodes.end()){
		visitedNodes.insert(make_pair(temp,1));
		if(c != 0){
			if(b!=bucketSizes[1]){
				tmp = transferMilk(1,b,c);
				solve(a,b,c);
				b-=tmp;
				c+=tmp;
			}
			if(a!=bucketSizes[0]){
				tmp=transferMilk(0,a,c);
				solve(a,b,c);
				a-=tmp;
				c+=tmp;
			}
		}
		if(b != 0){
			if(c!=bucketSizes[2]){
				tmp=transferMilk(2,c,b);
				solve(a,b,c);
				c-=tmp;
				b+=tmp;
			}
			if(a!=bucketSizes[0]){
				tmp=transferMilk(0,a,b);
				solve(a,b,c);
				a-=tmp;
				b+=tmp;
			}
		}
		if(a != 0){
			if(b!=bucketSizes[1]){
				tmp=transferMilk(1,b,a);
				solve(a,b,c);
				b-=tmp;
				a+=tmp;
			}
			if(c!=bucketSizes[2]){
				tmp=transferMilk(2,c,a);
				solve(a,b,c);
				c-=tmp;
				a+=tmp;
			}
		}
	}
	else return;
}

int main(){
	ifstream f_in("milk3.in");
	ofstream f_out("milk3.out");
	int A,B,C;
	bool flag;
	f_in>>A>>B>>C;
	bucketSizes.push_back(A);
	bucketSizes.push_back(B);
	bucketSizes.push_back(C);
	if(A < B ) flag = false;
	else flag = true;
	int a =0; int b = 0;
	solve(a,b,C);
	printSolution(f_out);
}