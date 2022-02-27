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
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr)
			return nullptr;
		auto new_head = new ListNode(0,head);
		auto before = newhead;
		auto cur = head;
		auto after = head->next;
		while(after != nullptr){
			// before cur after
			before->next = after;
			cur->next = after->next;
			after->next = cur;
			// before after cur
			before = cur;
			cur = cur -> next;	
			if(cur == nullptr)
				break;
			after = cur -> next;
		}
		head = new_head->next;
		delete new_head;
		return head;
	}
};
