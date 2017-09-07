/*
ID:goksgie2
PROG: castle
LANG: C++11
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


vector<pair<int,vector<int>>> buildGraph(vector<vector<int>>& building, int M, int N){
	vector<pair<int,vector<int>>> graph(M*N);
	for(int i =0; i<N; i++){
		int next = i*M;
		for(int j=0; j<M; j++){
			int number = building[i][j];
			vector<int> neighbors;
			if((number & 1) == 0){
				neighbors.push_back(next+j-1);
			}
			if((number & 2) == 0){
				neighbors.push_back(next-M+j);
			}
			if((number & 4)== 0){
				neighbors.push_back(next+j+1);
			}
			if((number & 8) == 0){
				neighbors.push_back(next+j+M);
			}
			graph[next+j] = make_pair(-3,neighbors);
		}
	}
	return graph;
}

void printGraph(vector<pair<int,vector<int>>>& graph){
	for(int i =0; i<graph.size(); i++){
		cout<<"neighbors of room:"<<i<<endl;
		for(int j =0; j<graph[i].second.size(); j++){
			cout<<graph[i].second[j]<<" ";
		}
		cout<<"\n####"<<endl;
	}
}

int flood_fill(vector<pair<int,vector<int>>>& graph, int component){
	int num_visited = 0;
	int room_count = 0;
	vector<int> room;
	do{
		num_visited = 0;
		for(int i =0; i<graph.size(); i++){
			pair<int,vector<int>>* currentNode = &graph[i];
			if(currentNode->first == -2){
				room.push_back(i);
				num_visited++;
				room_count++;
				currentNode->first = component;
				for(int j =0; j<currentNode->second.size(); j++){
					if(graph[currentNode->second[j]].first == -3)
						graph[currentNode->second[j]].first= -2;
				}
			}
		}
		//cout<<num_visited<<endl;
	}while(num_visited!=0);
	//return make_pair(room_count,room);
	return room_count;
}

pair<pair<int,int>,pair<int,char>> findWall_v2(vector<pair<int,vector<int>>>& graph, vector<int>& rooms,int M, int N){
	int max_room=-1;
	int x=0;
	int y = 0;
	char wall= 'E';
	for(int i =0; i<M; i++){
		for(int j=N-1; j>=0; j--){
			int next = i + j*M;
			if(next-M >=0 && graph[next].first != graph[next-M].first){
				if(rooms[graph[next].first] + rooms[graph[next-M].first] > max_room){
					max_room = rooms[graph[next].first] + rooms[graph[next-M].first];
					wall = 'N';
					x = j+1;
					y = i+1;
				}
			}
			if(i+1 < M && graph[next].first != graph[next+1].first){
				if(rooms[graph[next].first] + rooms[graph[next+1].first] > max_room){
					max_room = rooms[graph[next].first] + rooms[graph[next+1].first];
					wall = 'E';
					x = j+1;
					y = i+1;
				}
			}
		}
	}
	//cout<<max_room<<endl;
	//cout<<x<<" "<<y<<" "<<wall<<endl;
	return make_pair(make_pair(x,y),make_pair(max_room,wall));
}

pair<pair<int,int>,vector<int>> countRooms(vector<pair<int,vector<int>>>& graph,int M, int N){
	int num_components = -1;
	int biggest = -1;
	//vector<pair<int,vector<int>>> rooms;
	vector<int> rooms;
	for(int i =0; i<graph.size(); i++){
		if(graph[i].first == -3){
			num_components++;
			graph[i].first = -2;
			//pair<int,vector<int>> room = flood_fill(graph,num_components);
			int room = flood_fill(graph,num_components);
			rooms.push_back(room);
			biggest = max(biggest,room);
			//rooms.push_back(room);
		}
	}
	//findWall_v2(graph,rooms,M,N);
	return make_pair(make_pair(num_components,biggest),rooms);
}

int main(){
	ifstream f_in("castle.in");
	ofstream f_out("castle.out");
	int M,N;
	int wallPosition;
	f_in >> M >> N;
	vector<vector<int>> building(N);
	for(int i =0; i<N; i++){
		vector<int> row(M);
		for(int j=0; j<M; j++){
			f_in>>row[j];
		}
		building[i] = row;
	}
	vector<pair<int,vector<int>>> graph = buildGraph(building, M, N);
	//printGraph(graph);
	auto roomInfo = countRooms(graph,M,N);
	f_out << roomInfo.first.first +1<<endl<<roomInfo.first.second<<endl;
	auto wallInfo = findWall_v2(graph,roomInfo.second,M,N);
	f_out << wallInfo.second.first<<endl<<wallInfo.first.first<<" "<<wallInfo.first.second<<" "<<wallInfo.second.second<<endl;
	//cout<< ret.first.first<<" "<<ret.first.second<<endl;
}