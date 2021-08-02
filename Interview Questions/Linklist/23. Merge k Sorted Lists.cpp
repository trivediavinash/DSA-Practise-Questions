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

2. Merge Lists one by one 

// complexity - suppose every linklist is of n size then 
// n + 2n + 3n + 4n + 5n ...... kn 
// n  k(k+1)/2 = O(n)(k^2) where n = size of on linklist and k is no of linklist
//O(1)

2. ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
  ListNode * l3 = new ListNode;
  ListNode * l4 = l3;

  while (l1 and l2) {
    if (l1 -> val < l2 -> val) {
      l3 -> next = l1;

      l1 = l1 -> next;

    } else {
      l3 -> next = l2;

      l2 = l2 -> next;
    }
    l3 = l3 -> next;

  }

  if (l1 == NULL) l3 -> next = l2; //if first list is exhausted move pointer of newly formed list to second list .
  if (l2 == NULL) l3 -> next = l1;
  return l4 -> next;
}
class Solution {
  public:

    ListNode * mergeKLists(vector < ListNode * > & lists) {
      //  if(lists.size()==1) return lists[0];
      if (lists.size() == 0) return {};

      ListNode * head = lists[0];
      for (int i = 1; i < lists.size(); i++) {
        head = mergeTwoLists(head, lists[i]); //merging list one by one ,head will always point to newly formed linklist.
      }
      return head;
    }
};

3. Divide and conquor 

//O(NLogK)  O(1) 
//O(Logk) in dividing the array every time  into half for N elemtns total elements in the lists 
class Solution {
  private:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
      ListNode * l3 = new ListNode;
      ListNode * l4 = l3;

      while (l1 and l2) {
        if (l1 -> val < l2 -> val) {
          l3 -> next = l1;

          l1 = l1 -> next;

        } else {
          l3 -> next = l2;

          l2 = l2 -> next;
        }
        l3 = l3 -> next;

      }

      if (l1 == NULL) l3 -> next = l2;
      if (l2 == NULL) l3 -> next = l1;
      return l4 -> next;
    }
  public:
    ListNode * mergeKLists(vector < ListNode * > & lists, int s, int e) {
      if (s > e) return NULL;
      if (s == e) return lists[s];
      int mid = (s + e) / 2;
      ListNode * left = mergeKLists(lists, s, mid);
      ListNode * right = mergeKLists(lists, mid + 1, e);
      return mergeTwoLists(left, right);

    }
  public:
    ListNode * mergeKLists(vector < ListNode * > & lists) {
      return mergeKLists(lists, 0, lists.size() - 1);
    }
};
