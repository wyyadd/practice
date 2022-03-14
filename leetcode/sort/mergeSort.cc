class Solution {
public:
    ListNode* sortList(ListNode* head) {
				if(head == nullptr || head -> next == nullptr)
					return head;
				auto slow = head;
				auto fast = head;
				while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
					slow = slow -> next;
					fast = fast->next->next;
				}
				auto next_head = slow -> next;
				slow -> next = nullptr;
				return merge(sortList(head),sortList(next_head));	
		}

		ListNode* merge(ListNode* head1, ListNode* head2){
			ListNode* head = new ListNode();
			auto node = head;
			while(head1 != nullptr && head2 != nullptr){
				if(head1->val < head2->val){
					node -> next = head1;
					head1 = head1->next;
				}
				else{
					node -> next = head2;
					head2 = head2->next;
				}
				node = node->next;
			}
			if(head1 == nullptr)
				node -> next = head2;
			else
				node -> next = head1;
			return head->next;
		}
};