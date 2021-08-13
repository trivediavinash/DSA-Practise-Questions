/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
1. O(M*N) O(M+N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> row(m,0) ; vector<int> col(n,0);  //intialising row vector and col vector with size n & m with value zero . 
        for(int i =0; i< m ; i++){
            for (int j = 0; j<n ;j++){
                if(matrix[i][j] == 0 ){
                    row[i] = 1;    //flaging specific row number if zero is present at it
                    col[j] = 1;   //flaging specific col number if zero is present at it
                }
            }
        }
        for(int i =0; i< m ; i++){
            for (int j = 0; j<n ;j++){
                if(row[i] == 1 or col[j] == 1){  //checking if current row or column is flagged if it is flagged then set currnt matrix location to zero .
                    matrix[i][j] = 0;
                }
            }
        }
        
        
    }
};
