/*
ID:goksgie2
PROG: brokennecklace
LANG: C++11
*/
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream cix("brokennecklace.in");
	ofstream cox("brokennecklace.out");
	string input;
	int size;
	char current;
	int max=-1; int total;
	int left;
	int right;
	int r,l;
	int forbidden;
	cix>>size;
	cix.ignore();
	getline(cix, input);
	for(int i =0; i<size; i++){
		left =1; right =1; total = 0;
		current = input[i];
		for(r =(i+1)%size; r<size; r++){
			if(input[r]==current || input[r] == 'w') right++;
			else if(current == 'w'){
				current = input[r];
				right++;
			}
			else break;
		}
		forbidden = (i+1)%size;
		current = input[(i-1+size)%size];
		for(l = (i-2+size)%size; l!=forbidden; l=(l-1+size)%size){
			if(l == r) break;
			if(input[l]==current || input[l] == 'w') left++;
			else if(current == 'w'){
				current = input[l];
				left++;
			}
			else break;
		}
		total = left+right;
		if(total > max) max = total;

	}
	if(max<=size)
		cox<<max<<endl;
	else cox<<size<<endl;
	return 0;

}