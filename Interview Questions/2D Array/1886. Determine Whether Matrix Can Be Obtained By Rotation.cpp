/*Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.  */

1. O(n^2)

class Solution {
  public:
    bool findRotation(vector < vector < int >> & mat, vector < vector < int >> & target) {
      int n = mat.size();
      int z = target.size();
      int count = 3;
      if (target == mat) return true;
      while (count--) {

        for (int i = 0; i < n; i++) {
          for (int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
          }
        }
        for (int i = 0; i < n; i++) {
          reverse(mat[i].begin(), mat[i].end());
        }
        /*   for (int i = 0; i < n; i++) {
              for (int j = i; j < n; j++) {
                if (mat[i][j] == target[i][j]) {
                   return true;
                }
              }
            }  */
        if (mat == target) return true;          //    n C++ generally == is overloaded for value comparison. A reference comparison can be done with the & operator, eg. "&mat == &target" which would be comparing if they have the same address. If mat and target were pointer types, then == would be a reference comparison and in order to do a value comparison you would need to use the * operator to dereference.

      }
      return false;

    }

};


2 .

class Solution {
  public:
    bool findRotation(vector < vector < int >> & mat, vector < vector < int >> & target) {
      int n = mat.size();
      int z = target.size();
      int count = 3; // more rotations with 90, 180, 270 degree's.
      if (target == mat) return true; //// rotation by 0 degree.
      while (count--) {
        bool f = 0;
        for (int i = 0; i < n; i++) {
          for (int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]); // transpose of matrix
          }
        }
        for (int i = 0; i < n; i++) { // reverse each row.
          reverse(mat[i].begin(), mat[i].end());
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) {
              f = 1;
            }
          }
        }
        if (f == 0) return true; 
      }
      return false;

    }

};
