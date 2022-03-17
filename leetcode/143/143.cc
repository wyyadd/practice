/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
	ListNode* reverse(ListNode* node){
		auto pre = node;
		auto cur = node -> next;
		while(cur != nullptr){
			auto temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		node -> next = nullptr;
		return pre;
	}
public:
	void reorderList(ListNode* head) {
		if(head -> next == nullptr)
			return;
		auto slow = head;
		auto fast = head;
		while(fast != nullptr && fast->next != nullptr){
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		auto head2 = reverse(slow);

		auto node1 = head;	
		auto node2 = head2;
		auto node = head;
		bool flag = true;
		while(node2 != nullptr){
			if(flag){
				node -> next = node2;
				node = node2;
				node2 = node2->next;
				flag = false;
			}
			else{
				node -> next = node1;
				node = node1;
				node1 = node1->next;
				flag = true;
			}
		}
	}
};
