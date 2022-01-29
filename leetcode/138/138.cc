/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
	unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
			if(head == NULL)
				return NULL;
			// init
			auto new_head = new Node(head->val); 
			map.insert(make_pair(head, new_head));
			auto new_node = new_head;
			auto node = head -> next;
			// first loop to copy next
			while(node != NULL) {
				auto temp_node = new Node(node->val);		
				new_node->next = temp_node;
				new_node = temp_node;
				map.insert(make_pair(node,new_node));
				node = node->next;
			}
			// second loop to copy random
			node = head;
			new_node = new_head;
			while(node != NULL) {
				auto temp_node = node -> random;
				new_node -> random = map[temp_node];	
				node = node -> next;
				new_node = new_node -> next;
			}
			return new_head;
    }
};
