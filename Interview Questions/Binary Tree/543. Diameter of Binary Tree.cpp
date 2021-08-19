/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

*/

1. O(N) O(logN) for balanced binary tree or O(N) for skewed tree linklist like structure

//diameter = no of edgees 
class Solution {
  public:
    int diameterOfBinaryTree(TreeNode * root) {
      int maxDia = 0;

      height(root, maxDia);
      return maxDia;
    }
  private:
    int height(TreeNode * root, int & maxDia) {
      if (root == NULL) return 0;

      int leftHeight = height(root -> left, maxDia);
      int rightHeight = height(root -> right, maxDia);

      int currDia = leftHeight + rightHeight; //calculating diameter at ecah node
      maxDia = max(maxDia, currDia); //taking maximum of all diameter nd updating it accordingly

      return max(leftHeight, rightHeight) + 1; // returning  height for each parent node so that it can help to calculate dimatr for next parent node while returning (bottom up). this returned value will act as a height for parent node which may be again act as left child or right child (parent node).
      // leftHeight + rightHeight........this returned value act as a left height or right height will depend on node that node again may be a left or child of any other node.

    }
}; 
