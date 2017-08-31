#include <iostream>
using namespace std;

int countOnes(int number){
	int count=0;
	while(number > 0){
		if( number & 1 ) count++;
		number = number >> 1;
	}
	return count;
}

int countFriends(int* array, int m, int k){
	int friends = 0;
	int temp;
	for(int i = 0; i<m; i++){
		temp = array[i] ^ array[m];
		if(countOnes(temp) <= k) friends++;
	}
	return friends;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int players[m+1];
	for(int i =0; i<=m; i++){
		cin>>players[i];
	}
	cout<<countFriends(players,m,k);
}