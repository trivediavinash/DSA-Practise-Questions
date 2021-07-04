/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

1. O(M*N) O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i =0 ;i<n;i++){
            for(int j = 0 ;j<matrix[i].size();j++){
                if(matrix[i][j]==target) return 1;
            }
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

3.O(N*LogM) N= rows M =columns O(1)

class Solution {
  public:
    bool searchMatrix(vector < vector < int >> & matrix, int target) {
      int n = matrix.size();
      for (int i = 0; i < n; i++) {
        int s = 0, e = matrix[i].size() - 1;
        if (matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
          while (s <= e) {
            int mid = s + (e - s) / 2;
            if (matrix[i][mid] == target) return 1;
            else if (matrix[i][mid] > target) e = mid - 1;
            else s = mid + 1;
          }
        }
      }
      return 0;
    }
};

3.O(m + n) he worst situation will be at the last row and the first column.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0 , j = matrix[0].size()-1;
        while(j>=0 && i<matrix.size()){
            if(matrix[i][j]==target) return 1;
            else if (matrix[i][j]>target) j--;
            else i++;
        }
        return 0;
    }
};

