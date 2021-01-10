/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

1. 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next=head;   
	ListNode*cur=dummy;

	int duplicate;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			duplicate = cur->next->val;
			while (cur->next && cur->next->val ==duplicate ) 
				cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	return dummy->next;

    }
};