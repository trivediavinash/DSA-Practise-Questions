/*

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

1.
class Solution {
public:
    vector<int> spiral(vector<vector<int>>& matrix){
    vector<int>v;
    int start_row=0;
    int start_col=0;
    int end_col=matrix[0].size()-1;
    int end_row=matrix.size()-1;
    while(start_row<=end_row and start_col<=end_col){
        
      //FIRST ROW  
    for (int i=start_col;i<=end_col;i++){
        int x=matrix[start_row][i];
        v.push_back(x);
    }
    start_row++;
    //LAST COLUMN
    for(int i =start_row;i<=end_row;i++){
        int x=matrix[i][end_col];
        v.push_back(x);
    }
    end_col--;
    //LAST ROW
    if(end_row>=start_row && end_col>=start_col){
    for(int i=end_col;i>=start_col;i--){
        int x=matrix[end_row][i];
        v.push_back(x);
    }
    end_row--;
  
    //FIRST COLUMN
  
    for(int i =end_row;i>=start_row;i--){
       int x=matrix[i][start_col];
        v.push_back(x);
    }
    start_col++;
    }
    }
        return v;
    
}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> ans=spiral(matrix);
        return ans;
         
    }
};