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
//快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode *fast = head;
			ListNode *p_former = head;
			ListNode *p = head;
			for (int i = 0; i < n; i++)
				fast = fast -> next;
			while (fast != nullptr) {
				if(p != head)
					p_former = p_former -> next;
				p = p -> next;
				fast = fast -> next;
			}
			if(p != head){
				p_former -> next = p-> next;
				delete p;
			}
			else{
				head = p -> next;
				delete p;
			}
			return head;
    }
};
