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
    ListNode* sortList(ListNode* head) {
			vector<int> arr;
			auto node = head;
			while(node != nullptr){
				arr.push_back(node->val);
				node = node->next;
			}
			sort(arr.begin(),arr.end());
			node = head;
			int po = 0;
			while(node != nullptr){
				node -> val = arr[po++];
				node = node->next;
			}
			return head;
    }
};
