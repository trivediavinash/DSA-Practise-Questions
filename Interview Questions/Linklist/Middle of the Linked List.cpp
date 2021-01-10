/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.


*/
Using extra space ..vector will store the pointers as  we have to return the pointer to the head.
1. class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A ;
        while (head != NULL ){
            A.push_back(head);
            head=head->next;
    }
        return A[A.size() / 2];
    }
};
2. o(n) 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid=head;
        ListNode* fast= head;
        int c=0;
        while(fast!=NULL ){
            if(c%2==1){   //If count is odd then only increase pointer mid in this wat it traverse only half way.
               
                mid=mid->next;
                
            }
             c++;
            fast=fast->next;
          
            
           
        }
        
        return fast;
    }
};









3.   class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode* fast= head;
        while(fast!=NULL and fast->next!=NULL ){   //if no of nodes are even fast will be null if odd fast->next will be null.
            
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

