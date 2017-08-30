/*
ID:goksgie2
PROG: milk2
LANG: C++11
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;



struct cowgirl{
	int start;
	int finish;
	int worktime;
	cowgirl(int a, int b): start(a), finish(b) {
		worktime = b - a;
	}
};

bool compare(cowgirl a, cowgirl b){
	return a.start < b.start;
}
int main(){
	int N, first, second;
	int max_work=-1; int max_rest = 0;
	int max_finish = 0;
	int work=0; int rest=0;
	vector<cowgirl> list;
	ifstream cix("milk2.in");
	ofstream cox("milk2.out");
	cix>>N;
	for(int i =0; i<N;i++){
		cix>>first>>second;
		cowgirl x(first,second);
		list.push_back(x);
	}
	sort(list.begin(),list.end(), compare);
	max_work = list[0].worktime;
	work = list[0].worktime;
	max_finish = list[0].finish;
	for(int i =0; i<N-1;i++){
		
		if(max_finish >= list[i+1].start){
			
			if(max_finish < list[i+1].finish){
				work+=(list[i+1].finish-max_finish);
				max_finish = list[i+1].finish;
			}
			if(max_work < work){
				max_work = work;	
			}
		}
		else if(max_finish < list[i+1].start){
			if(max_work < work){
				max_work = work;	
			}
			work = list[i+1].worktime;
			rest = list[i+1].start - max_finish;

			if(max_rest < rest && max_finish < list[i+1].start){
				max_rest = rest;
				rest = 0;
			}
			max_finish = list[i+1].finish;
		}
		
	}
	cox<<max_work<<" "<<max_rest<<endl;
}