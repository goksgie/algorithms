/*
ID:goksgie2
PROG: crypt1
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void set2(vector<int>& set,vector<int>& first,int& count){
	int size = set.size();
	int p1,p2;
	int total;
	for(int i=0; i<size; i++){
		
		if(set[i]!=0 && i!=0){
			p1 = i*first[2] + 10*i*first[1] + 100*i*first[0];
			
			if(p1/1000!=0)continue;
			if(set[p1%10]==0) continue;
			if(set[(p1%100-p1%10)/10]==0)continue;
			if(set[p1/100]==0)continue;
			for(int j =0; j<size; j++){
				if(set[j]!=0){
					p2 = j*first[2] + 10*j*first[1] + 100*j*first[0];
					
					if(p2/1000!=0)continue;
					if(set[p2%10]==0) continue;
					if(set[(p2%100-p2%10)/10]==0)continue;
					if(set[p2/100]==0)continue;
					total = p2+ 10*p1;
					
					if(total/10000!=0 && set[total/10000]==0)continue;
					if(set[(total%100 - total%10)/10]==0)continue;
					if(set[(total%1000 - total%100)/100]==0)continue;
					if(set[(total%10000 - total%1000)/1000]==0) continue;
					count++;
					/*cout<<"total "<<total<<endl;
					cout<<"p2 "<<p2<<endl;
					cout<<"p1 "<<p1<<endl;*/
				}
			}
		}
	}
}

void set3(vector<int>& set, int& count){
	int size = set.size();
	vector<int> setx(3,0);
	for(int i=0; i<size; i++){
		if(set[i]!=0 && i!=0)
			setx[0]=i;
		else continue;
		for(int j =0; j<size; j++){
			if(set[j]!=0)
				setx[1]=j;
			else continue;
			for(int k = 0; k<size; k++){
				if(set[k]!=0)
					setx[2]=k;
				else continue;
				//cout<<setx[0]<<setx[1]<<setx[2]<<endl;
				set2(set,setx, count);
			}
		}
	}
}



int main(){
	ifstream cix("crypt1.in");
	ofstream cox("crypt1.out");
	
	int n; int temp;
	cix>>n;
	vector<int> set(10,0);
	for(int i =0; i<n;i++){
		cix>>temp;
		set[temp]=1;
		
	}
	temp =0;
	set3(set,temp);
	cox<<temp<<endl;
}