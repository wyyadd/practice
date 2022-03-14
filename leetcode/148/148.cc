#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class old_Solution {
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

int main(){
	auto head = new ListNode(-1);
	auto t1 = new ListNode(5);
	auto t2 = new ListNode(3);
	auto t3 = new ListNode(4);
	auto t4 = new ListNode(0);
	head->next = t1;
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	auto s = new Solution;
	s->sortList(head);
	while (head != nullptr)
	{
		cout << head->val << endl;
		head = head->next;
	}
	
	
}
