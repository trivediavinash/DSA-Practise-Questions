/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/

1. O(m+n) O(1)

class Solution {
  public:
    bool searchMatrix(vector < vector < int >> & matrix, int target) {
      int i = 0, j = matrix[0].size() - 1;
      while (i < matrix.size() && j >= 0) {
        if (matrix[i][j] == target) return 1;
        else if (matrix[i][j] > target) j--;
        else i++;
      }
      return 0;
    }
};

2.O(N*LogM) N= rows M =columns O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i =0 ;i<n;i++){
            int s = 0 , e = matrix[i].size()-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(matrix[i][mid]==target) return 1;
                else if(matrix[i][mid]>target) e = mid-1;
                else s = mid+1;
            }
        }
        return 0;
    }
};

