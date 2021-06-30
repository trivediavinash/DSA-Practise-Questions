/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
Accepted
524,062
Submissions
976,345*/
/*
Let N be the length of the input arrays.

Time complexity : O(N).

Building the hashmap takes O(N) time, as there are N nodes to add, and adding items to a hashmap has a cost of O(1), so we get N⋅O(1)=O(N).

Building the tree also takes O(N) time. The recursive helper method has a cost of O(1) for each call (it has no loops), and it is called once for each of the N nodes, giving a total of O(N).

Taking both into consideration, the time complexity is O(N).

Space complexity : O(N).

Building the hashmap and storing the entire tree each requires O(N) memory. The size of the implicit system stack used by recursion calls depends on the height of the tree, which is O(N) in the worst case and O(logN) on average. Taking both into consideration, the space complexity is O(N).   */

1.
class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int> &um, int inStart, int inEnd){
        if(inStart > inEnd) return 0;
        TreeNode* root = new TreeNode(preorder[preStart]);
          
        int mid = um[preorder[preStart]];   //finding the index of element from preorder  this indexed element will act as root of new tree.
         preStart++;    //increasing the index to search another element from preoderer which will act as root for new tree
        
        root->left = buildTree(preorder, um,  inStart, mid-1);  // recursively build left subtree 
        root->right = buildTree(preorder, um,  mid+1, inEnd);   // recursively build right subtree
        return root;
    }




    int preStart = 0;  // global varible to indicate the preorder array index
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,  int> um;
        for(int i=0;i<inorder.size();i++){   // use hashmap to improve search speed
            um[inorder[i]] = i;
        }
        return buildTree(preorder, um, 0,   inorder.size()-1);
    }
};

2. o(N^2)

class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,  int inStart, int inEnd){
        if(inStart > inEnd) return 0;
        TreeNode* root = new TreeNode(preorder[preStart]);
          int mid ;
          for(int i = inStart; i<inEnd; i++){
              if(inorder[i]==root->val){
                  mid = i;
                  break;
              }
          }  
        //finding the index of element from preorder  this indexed element will act as root of new tree.
         preStart++;    //increasing the index to search another element from preoderer which will act as root for new tree
        
        root->left = buildTree(preorder, inorder,   inStart, mid-1);  // recursively build left subtree 
        root->right = buildTree(preorder, inorder,   mid+1, inEnd);   // recursively build right subtree
        return root;
    }
    
    
    
    int preStart = 0;  // global varible to indicate the preorder array index
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTree(preorder, inorder, 0,   inorder.size()-1);
    }
};
