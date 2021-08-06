#include <iostream>
#include <stdio.h>
#include <climits>

namespace{
int max_ = INT_MAX - 100000;
class Solve{
 public:
	Solve(){
	//cin param
		scanf("%d%d%d%d",&vertexs_,&edges_,&s_,&t_);
		--s_;
		--t_;
	//set graph
		graph_ = new int*[vertexs_];
		for(int i = 0; i < vertexs_; ++i)
			graph_[i] = new int[vertexs_];
		for(int i = 0; i < vertexs_; ++i)
			for(int j = 0; j < vertexs_; ++j)
					graph_[i][j] = max_;
		//std::fill_n(*graph_, vertexs_*vertexs_, max_);
	//init graph
		for(int i = 0; i < edges_; ++i){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(w < graph_[u-1][v-1]){
				graph_[u-1][v-1] = w;
				graph_[v-1][u-1] = w;
			}
		}
	}
	~Solve(){
		for(int i = 0; i <vertexs_; ++i)
			delete []graph_[i];
		delete []graph_;
	}

//find the shortest path in dist
	int min_dist(int* dist, bool* visited){
		int min = max_;
		int node = -1;
		for(int i = 0; i < vertexs_; ++i){
			if(!visited[i] && (dist[i] < min)){
				min = dist[i];
				node = i;
			}
		}
		return node;
	}

	void Get_Answer(){
		//record shortest path from s_
		int* dist = new int [vertexs_];
		//record if this vertexs_ has been included into the dist
		bool* visited = new bool[vertexs_];
		//init
		for(int i = 0; i < vertexs_; ++i){
			dist[i] = graph_[s_][i];
			visited[i] = false;
		}
		//the dist to s_ is 0 and s_ has been visited
		dist[s_] = 0;
		visited[s_] = true;

		//node is the shortest and not visited vertex
		for(int i = 0; i < vertexs_ - 1; ++i){
			int node = min_dist(dist, visited);
			//node == -1 means all path = max
			if(node == -1)
				break;

			visited[node] = true;
			for(int i = 0; i < vertexs_; ++i)
				if(dist[node] + graph_[node][i] < dist[i])
					dist[i] = dist[node] + graph_[node][i];
		}
		//init len
		if(dist[t_] != max_)
			len_ = dist[t_];
	}

	void Print(){
		Get_Answer();
		printf("%d\n", len_);
	}
 private:
	int **graph_;
	int	vertexs_;
	int edges_;
	int s_, t_;
	int len_ = -1;
};
}//namespace

int main(){	
	int num;
	scanf("%d",&num);
	Solve *foo = new Solve[num];
	for(int i = 0; i < num; ++i)
		foo[i].Print();
	delete[] foo;
}
