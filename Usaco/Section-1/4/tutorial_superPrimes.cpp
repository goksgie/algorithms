#include <cmath>
#include <iostream>

using namespace std;

bool solver(int& number){
	int bound = sqrt(number);
	if(number == 1) return false;
	for(int i=2; i<=bound; i++){
		if(number%i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	int low = pow(10,n-1);
	int high = pow(10,n);
	int tmp;
	while(low<high){
		bool flag = true;
		tmp = low;
		while(tmp>0){
			if(!solver(tmp)){
				flag = false;
				break;
			}
			tmp = tmp/10;
		}
		if(flag) cout<<low<<endl;
		low++;
	}
	return 0;
}