#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define PI 3.14159265

vector<int> solutions;
long long getDotPro(vector<int>& point1,vector<int>& point2){
	long long result = 0;
	for(int i=0; i<5;i++){
		result+=point1[i]*point2[i];
	}
	return result;
}

int getAngle(vector<int>& point1, vector<int>& point2){
	long long len1 = sqrt(getDotPro(point1,point1));
	long long len2 = sqrt(getDotPro(point2,point2));
	if(len1 == 0 || len2 == 0) return 90;
	long long pro = getDotPro(point1,point2);
	return acos((double)pro/(len1*len2))*((int)180.0/PI);
}

vector<int> getVector(vector<int>& point1, vector<int>& point2){
	vector<int> temp;
	for(int i =0; i<5; i++){
		temp.push_back(point2[i]-point1[i]);
	}
	return temp;
}

void generateVectors(vector<vector<int>>& input){
	for(int i =0; i<input.size(); i++){
		bool flag = true;
		vector<vector<int>> temp;
		for(int j = 0; j<input.size(); j++){
			if(j == i) continue;
			temp.push_back(getVector(input[i],input[j]));
		}
		for(int j=0; j<temp.size(); j++){
			for(int m = j+1; m<temp.size(); m++){
				int angle = getAngle(temp[j],temp[m]);
				if(angle < 90){
					flag = false;
					break;
				}
			}
			if(flag == false) break;
		}
		if(flag) solutions.push_back(i+1);
	}
}

int main(){
	ifstream f_in("input.txt");
	int n;
	cin>>n;
	vector<vector<int>> input;
	for(int i =0; i<n; i++){
		vector<int> row;
		for(int j =0; j<5; j++){
			int temp;
			cin>>temp;
			row.push_back(temp);
		}
		input.push_back(row);
	}
	generateVectors(input);
	cout<<solutions.size()<<endl;
	for(int i =0; i<solutions.size();i++){
		cout<<solutions[i]<<endl;
	}
}