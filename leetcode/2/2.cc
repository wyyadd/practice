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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			//new a return listnode 
			ListNode *head = nullptr;
			ListNode *listnode = nullptr;
			//carry flag
			int flag = 0;
			//while one list reach to end, and two of them
			while (l1 != nullptr && l2 != nullptr) {
				ListNode *temp = new ListNode();
				//if listnode is the first one
				if(listnode != nullptr)
					listnode->next = temp;
				else
					head = temp;
				listnode = temp;
				listnode->val = l1->val + l2->val + flag;
				//bigger than 10
				if(listnode->val >= 10){
					listnode->val -= 10;
					flag = 1;
				}
				else
					flag = 0;
				l1 = l1->next;
				l2 = l2->next;
			}
			//if l1 not reach to end, continue to plus
			while(l1 != nullptr){
				ListNode *temp = new ListNode();
				listnode->next = temp;
				listnode = temp;
				listnode->val = l1->val + flag;	
				if(listnode->val >= 10){
					listnode->val -= 10;
					flag = 1;
				}
				else
					flag = 0;
				l1 = l1->next;
			}
			//if l2 not reach to end, continue to plus
			while(l2 != nullptr){
				ListNode *temp = new ListNode();
				listnode->next = temp;
				listnode = temp;
				listnode->val = l2->val + flag;	
				if(listnode->val >= 10){
					listnode->val -= 10;
					flag = 1;
				}
				else
					flag = 0;
				l2 = l2->next;
			}
			//add 1
			if(flag == 1){
				ListNode *temp = new ListNode(1);
				listnode->next = temp;
			}
			//return addup listnode
			return head;
    }
};
