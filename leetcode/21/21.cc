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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if(!l1 && !l2)
				return nullptr;
			if(!l1)
				return l2;
			if(!l2)
				return l1;
			ListNode *head = new ListNode();
			ListNode *node= head;
			ListNode *temp = head;
			while(l1 && l2){
				if(l1 -> val < l2 -> val){
					temp = new ListNode(l1 -> val);
					l1 = l1 -> next;
					node->next = temp;
					node = temp;
				}
				else{
					temp = new ListNode(l2 -> val);
					l2 = l2 -> next;
					node->next = temp;
					node = temp;
				}
			}
			node -> next = l1 ? l1 : l2;
			/*
			while(l1){
				temp = new ListNode(l1 -> val);
				l1 = l1 -> next;
				node->next = temp;
				node = temp;
			}
			while(l2){
				temp = new ListNode(l2 -> val);
				l2 = l2 -> next;
				node->next = temp;
				node = temp;
			}
			*/
			return head -> next;
    }
};
