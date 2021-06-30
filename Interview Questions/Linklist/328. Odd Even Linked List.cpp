/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

n == number of nodes in the linked list
0 <= n <= 104
-106 <= Node.val <= 106 */


1. O(N) O(N)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // We need seperate pointers to   *evenptr = even;   *oddptr = odd; to traverse over even and oddlinklist because even and odd will be at last postion of even and odd list and returning odd and even result in only last element  of odd or even lists.
        
        int i =1;
      
        ListNode *even  = new ListNode(0);
        ListNode  *odd  = new ListNode(0);
        ListNode *evenptr = even;
        ListNode *oddptr = odd;
        
        while(head){
            if(i%2==0){
                even->next = head;
                even = even->next;
             
            }
            else{
                odd ->next  = head;
                odd = odd->next;
              
                
            }
            head=head->next;
            i++;
        }
         even->next =NULL;             //even will be pointing to last node of newly formed even linklist.
         odd->next = evenptr->next;    // odd will be pointing to last node of newly formed odd linklist.
         // evenptr is pointing to the first element of newly formed even linklist .next is to skip the dummy node of consists of zero.
        
         
        return oddptr->next;   //odd is pointing to first node of newly formed linklist of odd indices element 
    }
};


2. O(N) O(1) 

// 1 2 3 4 5   odd will be at 5 and even will point to NULL (in last iteration)
//1 2 3 4 odd will point to 3 and even will point to 4 (in last iteration)  as even ka next is already pointing to NULL .
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;    // to keep track head of newly pointed even linklist so that it can be concanate at the end of all operations
        
        while(odd->next && odd->next->next){   //while(even && even ->next)
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
            
            
        }
        odd->next = evenHead;
        return head;
        
    }
};
