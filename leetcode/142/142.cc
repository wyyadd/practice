/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
unordered_set<ListNode*> set;
public:
	ListNode *detectCycle(ListNode *head) {
       while (head != NULL) {
				 if(set.find(head) != set.end())
					 return head;
				 set.insert(head);
				 head = head->next;
			 }
			 return NULL;
    }
};

