struct node{
	int key;
	node* before;
	node* next;
	node(): key(-1), next(nullptr), before(nullptr){};
	node(int val): key(val), next(nullptr), before(nullptr){};
};

class LRUCache {
private:
	// pair : first->value, second->position in deque 
	unordered_map<int, pair<int, node*>> map;
	node* head;
	node* back;
public:
    LRUCache(int capacity) {
			head = new node;
			auto n = head;
			for(int i = 0; i < capacity - 1; ++i){
				auto temp = new node;
				n -> next = temp;
				temp -> before = n;
				n = temp;
			}
			back = n;
    }

	~LRUCache(){
		auto node = head;
		while (node != nullptr)
		{
			auto temp = node;
			node = node -> next;
			delete temp;
		}
	}
    
    int get(int key) {
		if(map.find(key) != map.end()){
			auto& it = map.at(key);
			// update que
			deleteNode(it.second);
			push_frontNode(key);
			// update map
			it.second = head;
			return it.first;
		}
		else
			return -1;
    }
    
    void put(int key, int value) {
		if(map.find(key) != map.end()){
			// must & to refer
			auto& it  = map.at(key);
			// push_front
			deleteNode(it.second);
			push_frontNode(key);
			// update map
			it.first = value;
			it.second = head;
		}
		else{
			auto remove_key = back->key;
			// remove que back
			if(remove_key != -1)
				map.erase(remove_key);
			deleteNode(back);
			// push_front and insert hash map
			push_frontNode(key);
			map.insert(make_pair(key, make_pair(value, head)));
		}
    }

	void push_frontNode(int key){
		auto n = new node(key);
		if(head == nullptr){
			head = back = n;
			return;
		}
		n -> next = head;
		head -> before = n;
		head = n;
	}

	void deleteNode(node* n){
		if(n -> next == nullptr && n -> before == nullptr){
			delete n;
			head = back = nullptr;
			return;
		}
		if(n -> next == nullptr){
			back = n -> before;
			back -> next = nullptr;
			delete n;
			return;
		}
		if(n -> before == nullptr){
			head = n -> next;
			delete n;
			return;
		}
		n->before->next = n->next;	
		n->next->before = n->before;
		delete n;
	}
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
