/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/

1. Two Pass Solution O(tlenght+tlenght-n+1) ITERATIONS O(1)

class Solution {
public:
    int len(ListNode* head){
        int lenght=0;
        while(head){
            head=head->next;
            lenght++;
        }
        return lenght;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int tlenght=len(head);
        ListNode* dummy = new ListNode(0);
         dummy->next = head;
        
      
        int lenght=0;
        ListNode* curr=dummy;
        while(curr){
            
            lenght++;
            
            if(lenght==tlenght-n+1){
                ListNode* del=curr->next;
                curr->next=del->next;
                delete del;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};

2. One Pass O(tlenght) O(1)
class Solution {
public:
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
     
        ListNode* dummy = new ListNode(0);
         dummy->next = head;
        
      
        int lenght=0;
        ListNode* first=dummy, *second=dummy;
        
        while(n+1){                     //Advance the first pointer by n+1 steps 
            first=first->next;
            n--;
        }
            
        while(first){                 //Then advance pointer by 1 1 step abd it will maintain gap of n
            second=second->next;
            first=first->next;
               
            }
          
        ListNode* del=second->next;
        second->next= del->next;
        delete del;
            
        return dummy->next;
    }
};
/*
You need to think about it in number of iterations of your loop
First solution makes (tlenght+tlenght-n+1) iteration
Second solution makes  tlenght iterations

N is one pass, 2N is two passes. Yes, you do touch N + N - n nodes in second solution.
There is no such thing called "two passes" defined in big O. O(2n) = O(n). So effectively two-pass or one-pass, both here is O(n).
*/


