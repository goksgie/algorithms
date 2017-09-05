// Solution of Finding Largest Rectangle by using segment tree
// question link: https://www.hackerrank.com/challenges/largest-rectangle/problem
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
vector<long> inputArray;
vector<long> segmentTree;

pair<long, long> getMin(pair<long,long> f1, pair<long,long> f2){
	if(f1.second == -1) return f2;
	if(f2.second == -1) return f1;
	return (f1.second < f2.second)? f1:f2;
}

pair<long,long> generateSegmentTreeUtil(long left, long right, long treeIndex){
	if(left == right){
		segmentTree[treeIndex] = left;
		return make_pair(segmentTree[treeIndex],inputArray[left]);
	}
	long mid = left + (right - left) /2;
	pair<int,int> temp = getMin(generateSegmentTreeUtil(left,mid,2*treeIndex+1),
								generateSegmentTreeUtil(mid+1,right,2*treeIndex+2));
	segmentTree[treeIndex] = temp.first;
	return temp;
}

void generateSegmentTree(){
	long size = ceil(log2(inputArray.size()));
	long max_size = 2*pow(2,size) -1;
	segmentTree.resize(max_size);
	generateSegmentTreeUtil(0,inputArray.size()-1,0);
}

void printTree(){
	for(int i =0; i<segmentTree.size(); i++){
		cout<<segmentTree[i]<<endl;
	}
}

pair<long,long> getMinIntervalUtil(long start, long end, long left, long right, long treeIndex){
	//cout<<start<<" "<<end<<endl;
	if(start>=left && end <=right){
		long index = segmentTree[treeIndex];
		return make_pair(index,inputArray[index]);
	}
	if(end < left || start > right) return make_pair(-1,-1);
	long mid = start + (end - start)/2;
	return getMin(getMinIntervalUtil(start, mid, left,right,2*treeIndex+1),getMinIntervalUtil(mid+1,end,left,right,2*treeIndex+2));
}

long getMinInterval(long left, long right){
	if(left > right || right > inputArray.size() -1 ){
		return -1;
	}
	return getMinIntervalUtil(0,inputArray.size()-1,left,right,0).first;
}

long getMaxArea(long left,long right){
	if(left > right) return -1;
	if(left == right) return inputArray[left];
	long index = getMinInterval(left,right);
	return max(max(getMaxArea(left,index-1),getMaxArea(index+1,right)),inputArray[index]*(right-left+1));
}

int main(){
	ifstream fin("largestRect.in");
	long N;
	fin>>N;
	inputArray.resize(N);

	for(long i =0; i<N; i++){
		fin>>inputArray[i];
	}
	generateSegmentTree();
	//printTree();
	//cout<<getMinInterval(0,N-1);
	cout<<getMaxArea(0,N-1);
	return 0;
}