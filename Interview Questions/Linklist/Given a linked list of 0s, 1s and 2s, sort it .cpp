/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103

Company Tags
 Amazon MakeMyTrip Microsoft

*/

1. O(N) O(N)

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        Node *temp = new Node(0);
        Node *ans = temp;
       while(head){
           if(head->data==0) count0++;
           if(head->data==1) count1++;
           if(head->data==2) count2++;
           head=head->next;
       } 
       while(count0--){
           temp->next = new Node(0);
           temp = temp->next;
       }
      
       while(count1--){
           temp->next = new Node(1);
           temp = temp->next;
       }
      
       while(count2--){
           temp->next = new Node(2);
           temp = temp->next;
       }
       
       return ans->next;
        
    }
};


2. O(n) O(1)

class Solution {
  public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node * segregate(Node * head) {
      Node * l1 = new Node(0);
      Node * l2 = new Node(0);
      Node * l3 = new Node(0);

      Node * l1head = l1;
      Node * l2head = l2;
      Node * l3head = l3;
      Node * ans = l1head -> next;
      Node * curr = head;
      while (curr) {
        if (curr -> data == 0) {
          l1 -> next = curr;

          l1 = l1 -> next;
        } else if (curr -> data == 1) {
          l2 -> next = curr;
          l2 = l2 -> next;
        } else {
          l3 -> next = curr;
          l3 = l3 -> next;
        }

        curr = curr -> next;
      }
      if (l2head -> next) l1 -> next = l2head -> next;
      else l1 -> next = l3head -> next; // for cases like where list consisting of 1s is null.  0 0  0 2 2 2 2

      l2 -> next = l3head -> next;
      l3 -> next = NULL;

      delete l1head;
      delete l2head;
      delete l2head;

      return ans;

    }
};
