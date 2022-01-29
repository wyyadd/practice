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
    ListNode* reverseList(ListNode* head) {
			stack<int> s;
			auto node = head;
			while(node != nullptr){
				s.push(node->val);
				node = node->next;
			}
			node = head;
			while(!s.empty()){
				node -> val = s.top();
				s.pop();
				node = node->next;
			}
			return head;
    }
};
