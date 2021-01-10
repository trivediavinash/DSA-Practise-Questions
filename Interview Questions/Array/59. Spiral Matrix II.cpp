/*

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/

1.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> a(n,vector<int>(n));  //Created vector of size n and inside it created vector of same size n (i.e.vector of vector).
    int start_row=0;
    int start_col=0;
    int end_col=n-1;
    int end_row=n-1;
    int x=1; 
    while(start_row<=end_row and start_col<=end_col){
        
      //TOP  
    for (int i=start_col;i<=end_col;i++){
        a[start_row][i]=x;
        x++;
    }
    start_row++;
    //Right
    for(int i =start_row;i<=end_row;i++){
        a[i][end_col]=x;
        x++;
    }
    end_col--;
    //Bottom
  
    for(int i=end_col;i>=start_col;i--){
        a[end_row][i]=x;
        x++;
    }
    end_row--;
   
    //Left
   
    for(int i =end_row;i>=start_row;i--){
        a[i][start_col]=x;
        x++;
    }
    start_col++;
   
    }
        
        
         return a;












    }
};