/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

1.Recursive

class Solution {
public:
    //paasing ans by reference so that after each call of traversal fun  vector ans get update in main funtion.
    void traversal(TreeNode* root, vector<int>&ans){ 
        if(root==NULL) return ;
         traversal(root->left ,ans);
         ans.push_back(root->val);
         traversal(root->right ,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
         traversal(root,ans);
         return ans;
    }
};

2.Iterative

class Solution {
public:
   
    
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
         stack<TreeNode*>s;
         TreeNode* curr=root;
        while(curr!=NULL || !s.empty()){
             while(curr!=NULL){
                 s.push(curr);
                 curr=curr->left;
                 
             }
            curr=s.top();  //storing value of top element of stack.
             s.pop();
            ans.push_back(curr->val);
           
            curr=curr->right;
        }
           
        return ans;
    }
};