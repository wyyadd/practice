#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>

namespace{
using std::vector;
using std::priority_queue;
using std::unordered_set;
using std::pair;
//link is edge between vertexs, v1, v2 are vertexs, w is weight
struct link{
	int v1;
	int v2;
	int w;
};
class Solve{
 public:
	Solve(){
		//cin vertexs and num_of_edges
		scanf("%d%d", &vertex_, &num_of_edges_);
		int graph[vertex_ + 1][vertex_ + 1] = {0};
		//the function of graph is to avoid multiedges
		for(int i=0; i<num_of_edges_; ++i){
			link temp;
			scanf("%d%d%d", &temp.v1, &temp.v2, &temp.w); 
			if(graph[temp.v1][temp.v2] != 0){
				if(graph[temp.v1][temp.v2] > temp.w){
					edges.push_back(temp);
					graph[temp.v1][temp.v2] = temp.w;	
					graph[temp.v2][temp.v1] = temp.w;	
				}
			}
			else{
					edges.push_back(temp);
					graph[temp.v1][temp.v2] = temp.w;	
					graph[temp.v2][temp.v1] = temp.w;	
			}
		}
	}
	~Solve(){}

	bool if_circle(const link &e, vector<unordered_set<int>*> &set){
		if(kruskal_tree.size() == 0){
			unordered_set<int> *temp = new unordered_set<int>;
			temp->insert(e.v1);
			temp->insert(e.v2);
			set.push_back(temp);
			return true;
		}

		vector<int> po;
		for(size_t i = 0; i < set.size(); ++i){
			//means in graph_i, this is a circle
			if(set[i]->find(e.v1) != set[i]->end() && set[i]->find(e.v2) != set[i]->end())
				return false;
			//record which two different graph contains e's vertex
			if(set[i]->find(e.v1) != set[i]->end() || set[i]->find(e.v2) != set[i]->end())
				po.push_back(i);
		}
		//0 means no vertex link this edge, create a new graph
		if(po.size() == 0){
			unordered_set<int> *temp = new unordered_set<int>;
			temp->insert(e.v1);
			temp->insert(e.v2);
			set.push_back(temp);
			//printf("%d and %d size=0\n", e.v1,e.v2);
			return true;
		}
		//1 means only a graph contains this edge's vertex, link this edge to graph
		if(po.size() == 1){
			set[po[0]]->insert(e.v1);
			set[po[0]]->insert(e.v2);
			//printf("%d and %d size=1\n", e.v1,e.v2);
			return true;
		}
		//2 means this edge link two diffrent graph, link this two graph together
		if(po.size() == 2){
			for(auto i : *set[po[1]])
				set[po[0]]->insert(i);
			set.erase(std::next(set.begin(),po[1]));
			//printf("%d and %d size=2\n", e.v1,e.v2);
			return true;
		}
		//unknown condition
		return false;
	}
	void Get_Answer(){
		//lambda function for compare
		auto my_cmp = [](const link& x, const link& y){
			return x.w > y.w;
		};
		//Init a heap(priority_queue)
		priority_queue<link, vector<link>, decltype(my_cmp)> queue(my_cmp);
		for(auto i : edges){
			queue.push(i);
		}
		//unordered_hashset to record the vertexs in kruska_tree
		vector<unordered_set<int>*> vertex_set;
	//kruskal algrithom	
		while(kruskal_tree.size() < (size_t) num_of_edges_ - 1 && !queue.empty()){
			auto e = queue.top();
			queue.pop();
			if(if_circle(e, vertex_set)){
				kruskal_tree.push_back(e);
				weight_ += e.w;
			}
		}	
	//means cannt generate a spanning tree 
		//for(auto i : kruskal_tree)
		//	printf("%d and %d = %d\n",i.v1,i.v2,i.w);
		//printf("size = %ld\n", kruskal_tree.size());
		if(kruskal_tree.size() != (size_t)vertex_ - 1 || kruskal_tree.size() == 0)
			weight_ = -1;
	}
	void Print(){
		Get_Answer();
		printf("%d\n", weight_);
	}
 private:
	int weight_ = 0;
	int vertex_;
	int num_of_edges_;
	vector<link> kruskal_tree;
	vector<link> edges; 
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
