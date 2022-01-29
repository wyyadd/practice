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
    bool hasCycle(ListNode *head) {
       while (head != NULL) {
				 if(set.find(head) != set.end())
					 return true;
				 set.insert(head);
				 head = head->next;
			 }
			 return false;
    }
};
