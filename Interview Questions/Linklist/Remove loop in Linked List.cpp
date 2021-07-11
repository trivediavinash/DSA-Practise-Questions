/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
Note: The generated output will be 1 if your submitted code is correct.


Expected time complexity : O(N)
Expected auxiliary space : O(1)


Constraints:
1 ≤ N ≤ 104

Company Tags
 Adobe Amazon Goldman Sachs Kuliza MakeMyTrip Microsoft Morgan Stanley Netskope Oracle Qualcomm Snapdeal VMWare Walmart
*/

1. O(N) O(1)

class Solution {
  public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node * head) {
      if (!head) return;
      if (head -> next == NULL) return;
      Node * fast = head;
      Node * slow = head;
      while (fast and fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) break;

      }
      if (slow == head) //if cycle is from the head node only then 
      {
        slow = head;

        while (slow -> next != head) // move the slow pointer to the last node of linklist and make next of it as NULL
        {
          slow = slow -> next;
        }

        slow -> next = NULL; //last node of linklist and make it as NULL.
      }
      if (slow == fast) {
        slow = head;
        while (slow -> next != fast -> next) { //before meeting up the slow and fast remove the link only not the cycle nodes
          slow = slow -> next;
          fast = fast -> next;
        }
        fast -> next = NULL; //questionn is to remove the cycle in linklist not to remove the whole cycle nodes thats why fast->next should be null not slow->next should be null
      }
      //return head; 
    }

};
