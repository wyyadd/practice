struct node{
	int val;
	vector<node*> pre;
	vector<node*> after;
	node(int v): val(v) {};
};
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		// generate graph
		vector<node*> graph(numCourses);			 
		for(auto i = 0; i < graph.size(); ++i)
			graph[i] = new node(i);
		for(auto& i : prerequisites){
			// add pre node
			graph[i[0]]->pre.push_back(graph[i[1]]);
			// add after node
			graph[i[1]]->after.push_back(graph[i[0]]);	
		}

		vector<int> ans;
		// AOV sort algo
		auto head = getHeadNode(graph);
		while(head != -1){
			ans.push_back(graph[head]->val);
			deleteHead(graph,head);
			head = getHeadNode(graph);
		}
		if(graph.empty())
			return ans;
		else
			return vector<int>{};
	}

	int getHeadNode(vector<node*>& graph){
		for(auto n=0; n < graph.size(); ++n)
			if(graph[n]->pre.empty())
				return n;
		return -1;
	}

	void deleteHead(vector<node*>& graph, int head){
		auto node_head = graph[head];
		for(auto& a_node : node_head->after){
			auto& pre_node_set = a_node->pre;
			for(auto p_node = 0; p_node < pre_node_set.size(); ++p_node){
				if(pre_node_set[p_node] == node_head)
					pre_node_set.erase(pre_node_set.begin()+p_node);
			}
		}
		graph.erase(graph.begin() + head);
		delete node_head;
	}
};

