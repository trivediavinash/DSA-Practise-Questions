/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

1. O(N) + O(NLogN) + O(N) O(N) + O(N)

class Solution {
  public:

    ListNode * mergeKLists(vector < ListNode * > & lists) {
      int n = lists.size();
      int i = 0;
      vector < int > v;
      ListNode * l = new ListNode(0); //Allocating new node 
      ListNode * t = l;
      while (n--) {
        ListNode * head = lists[i]; //pointing to the head for first linklist
        while (head) { //exhasting the lists and adding the node value

          v.push_back(head -> val);
          head = head -> next;

        }
        i++;
      }
      sort(v.begin(), v.end()); //sorting the vector  
      for (int i = 0; i < v.size(); i++) { //copying the sorted value of vectors into linklist
        l -> next = new ListNode(v[i]);
        l = l -> next;
      }
      return t -> next;
    }
};

2.
