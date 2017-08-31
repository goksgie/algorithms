#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> luckyNumbers;

void luckyNumber(long long num, long long max){
	if(num > max) return;
	luckyNumbers.push_back(num);
	luckyNumber(num*10 + 4,max);
	luckyNumber(num*10 + 7,max);
}

int main(){
	int n;
	cin>>n;
	luckyNumber(0,n);
	sort(luckyNumbers.begin(), luckyNumbers.end());
	// unique does not change the size of the array, it basicly replaces duplicate element with next one
	// then returns the iterator of new last element.
	luckyNumbers.resize(unique(luckyNumbers.begin(), luckyNumbers.end()) - luckyNumbers.begin());
	// lower_bound returns an iterator to point where n<*it holds.
	//cout<<lower_bound(luckyNumbers.begin(), luckyNumbers.end(),n) - luckyNumbers.begin() << endl;
	// but there is another way through if we just compute the vector until the last element is our number
	// then returning the last position which is size-1 will return desired answer.
	cout<<luckyNumbers.size()-1<<endl;
	return 0;
}