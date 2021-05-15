/*

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of linked lists <= 106
0 <= numbers in list <= 104

*/

1. O(N) O(N)


// Function to remove duplicates from the linked list
// root: root of the linked list
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        Node *curr=head;
        Node *prev=NULL;
        unordered_set< int > us ;
        while(curr){
            if(us.find(curr->data)==us.end()){  //checking that if node is previous visited or not 
                us.insert(curr->data);
                prev=curr;
                curr=curr->next;  // 1
            }
            else{
                 prev->next=curr->next;
                  delete curr;
                 curr=curr->next; //2
                // delete curr;
            }
            //curr=curr->next; ,,,work same if remove statment 1 and stament 2
        }
        return head;
    }
};



