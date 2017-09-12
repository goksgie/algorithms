/*
ID:goksgie2
PROG: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int V;
int G;
vector<int> vitReq;

void testUtil(vector<int>&target, int reqElem, int current,  int range, vector<int> solution, bool& flag);
vector<int> test(vector<int>& target);

void findSolutionUtil(vector<vector<int>>& scoops, int reqElem, int current, int range, bool& flag, vector<int> solution,ofstream& f_out){
	if(reqElem == 1){
		solution.push_back(current);
		bool temp=true;
		for(int vi = 0; vi<V; vi++){
			int vit=0;
			for(int i =0; i<solution.size(); i++){
				vit+=scoops[vi][solution[i]];
			}
			if(vit < vitReq[vi]){
				temp = false;
				break;
			}
		}
		if(temp){
			f_out<<solution.size()<<" ";
			for(int i =0; i<solution.size(); i++){
				f_out<<solution[i]+1;
				if(i != solution.size()-1) f_out<<" ";
				else f_out<<endl;
			}
			flag = false;
		}
		return;
	}
	if(current < G){
		solution.push_back(current);
		for(int i=1; i+current<G; i++){
			if(flag)
				findSolutionUtil(scoops,reqElem-1, current+i, i, flag, solution,f_out);
		}
	}

}

void findSolution(vector<vector<int>>& scoops, ofstream& f_out){
	int reqElem = 1;
	int size = scoops.size();
	bool flag = true;
	do{
		for(int i =0; i< G; i++){
			findSolutionUtil(scoops,reqElem, i,1,flag,vector<int>{}, f_out);
			if(!flag) return;
		}
		reqElem++;
	}while(reqElem<=size);
	return;
}

int main(){
	ifstream f_in("holstein.in");
	ofstream f_out("holstein.out");
	f_in>>V;
	vitReq.resize(V);
	for(int i =0; i<V; i++){
		f_in>>vitReq[i];
	}
	f_in>>G;
	vector<vector<int>> scoops(V,vector<int>(G));
	for(int gi =0; gi<G; gi++){
		for(int vi =0; vi<V; vi++){
			int temp;
			f_in>>scoops[vi][gi];
		}
	}
	/*
	for(int vi = 0; vi<V; vi++){
		cout<<"#####\n";
		for(int gi = 0; gi<G; gi++){
			cout<<scoops[vi][gi]<<endl;
		}
	}
	*/
	vector<int> testArray =  {5,6,7,12,13};
	//test(testArray);
	findSolution(scoops,f_out);
	return 0;
}

void testUtil(vector<int>&target, int reqElem, int current,  int range, vector<int> solution, bool& flag){
	/*
	for(int i =0; i<solution.size(); i++){
		cout<<solution[i]<<" ";
		if(i == solution.size()-1) cout<<"j:"<<range<<endl;
	}
	*/	
	if(reqElem == 1){
		solution.push_back(current);	
		for(int i =0; i<solution.size(); i++){
			cout<<solution[i]<<" ";
		}
		cout<<endl;
		flag = false;
		return;
	}
	if(current<target.size()){
		solution.push_back(current);
		for(int j = 1; j+current<target.size(); j++)
			if(flag)
				testUtil(target,reqElem-1, current+j, j, solution,flag);
	}

}

vector<int> test(vector<int>& target){
	int reqElem = 1;
	int size = target.size();
	bool flag = true;
	do{
		for(int i =0; i<target.size(); i++){
			testUtil(target,reqElem,i, 1,vector<int>{},flag);
		}
		reqElem++;
	}while(reqElem<=size);
	return vector<int>{};
}