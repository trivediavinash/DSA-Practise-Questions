/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order. 
If there are no such elements return an empty array. In this case the output will be printed as -1.

 

Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)

 

Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers.

Company Tags
 MAQ Software Microsoft VMWare
*/

1. O(n+n2+n3) O(n1+n2+n3) 

class Solution {
  public:
    vector < int > commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
      unordered_set < int > us1;
      unordered_set < int > us2;
      vector < int > res;

      for (int i = 0; i < n1; i++) us1.insert(A[i]);
      for (int i = 0; i < n2; i++) us2.insert(B[i]);
      int prev = 0;
      for (int i = 0; i < n3; i++) {
        if (us1.count(C[i]) && us2.count(C[i])) {

          if (prev != C[i]) res.push_back(C[i]);
          prev = C[i]; //to avoid duplicates in the solution vector 
          /*3 3 3
          3 3 3
          3 3 3
          3 3 3 */
        }
      }
      return res;
    }
};

2. O(n+n2+n3) O(n1+n2+n3) 

class Solution {
  public:
    vector < int > commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
      vector < int > res;

      int i = 0, j = 0, k = 0;

      while (i < n1 and j < n2 and k < n3) {
        while (i < n1 - 1 and A[i + 1] == A[i]) {    //to avoid duplicates in array 
          i++;
        }

        while (j < n2 - 1 and B[j + 1] == B[j]) {
          j++;
        }

        while (k < n3 - 1 and C[k + 1] == C[k]) {
          k++;
        }

        if (i < n1 and j < n2 and k < n3) {
          if (A[i] == B[j] and B[j] == C[k]) {
            res.push_back(A[i]);

            i++;
            j++;
            k++;
          } else if (A[i] < B[j]) {
            i++;
          } else if (B[j] < C[k]) {
            j++;
          } else {
            k++;
          }
        }
      }

      return res;
    }
};
