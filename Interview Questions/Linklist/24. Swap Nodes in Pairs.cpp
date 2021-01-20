/*
Given a linked list, swap every two adjacent nodes and return its head.

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
 

Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.)

*/
1. Recursive 

class Solution {
public:
    int len(ListNode* node){
        int lenght=0;
        while(node){
            lenght++;
            node=node->next;
        }
        return lenght;
    }
    ListNode* swapPairs(ListNode* head) {
    
       if(len(head)<2) return head;
        ListNode* curr=head, *prev=NULL;
        for(int  i=0;i<2;i++){
           ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        head->next= swapPairs(curr);
        return prev;
    }
};

2.
