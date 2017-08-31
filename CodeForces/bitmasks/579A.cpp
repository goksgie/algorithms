#include <iostream>

using namespace std;

int solve(int n){
	int count = 0;
	while(n > 0){
		if ( n & 1 ) count++;
		n = n>>1;
	}
	return count;
}

int main(){
	int SUM;
	cin>>SUM;
	cout<<solve(SUM)<<endl;
}