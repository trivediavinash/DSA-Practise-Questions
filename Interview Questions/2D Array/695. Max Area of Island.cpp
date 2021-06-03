/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/




// DO DFS iterative BFS Recursive Iterative







/*Complexity Analysis

Time Complexity: O(R*C)O(R∗C), where RR is the number of rows in the given grid, and CC is the number of columns. We visit every square once.

Space complexity: O(R*C)O(R∗C), the space used by seen to keep track of visited squares, and the space used by the call stack during our recursion.   */
1. DFS Recursive

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    max_area=max(max_area,dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid,int i,int j){
       
        if(i<0 or i>=grid.size() or j<0 or j>=grid[i].size() or grid[i][j]==0){
            return 0;
        }
         grid[i][j]=0;   //making  that positin 0 so that it is will visited again
        int area=1;      //Counting the area of single cell as 1
        area+=dfs(grid, i+1, j);      // checking in lower part
        area+=dfs(grid, i, j+1);      //right part 
        area+=dfs(grid, i-1, j);      //  upper part
        area+=dfs(grid, i, j-1);    // left part
        return area;
    }
};


2. DFS Recursive When Grid Is not mutable i.e. when we can not modify array elements .

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0)); //intialising a grid with all false to check whether a node is visited or not by default vector is initialised with 0 declaring with size. 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    max_area=max(max_area,dfs(grid, visited, i, j));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited, int i,int j){
       
        if(i<0 or i>=grid.size() or j<0 or j>=grid[i].size() or grid[i][j]==0 or visited[i][j]==1){
            return 0;
        }
        visited[i][j]=1;
        int area=1;
        area+=dfs(grid, visited, i+1, j);
        area+=dfs(grid, visited, i-1, j);
        area+=dfs(grid, visited, i, j+1);
        area+=dfs(grid, visited, i, j-1);
        return area;
    }
};
