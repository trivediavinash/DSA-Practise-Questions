/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

*/

1. O(N) O(N)+O(N) STACK+VECTOR

class Solution {
public:
    bool isValidBST(TreeNode* root) {
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
       
         for(int i=0;i<ans.size()-1;i++){
             if(ans[i]<ans[i+1]){
                 continue;
             }
            return false;;
        }
       return true;;
    }
};

2. O(N) O(N)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
         TreeNode* prev=NULL;
         stack<TreeNode*>s;
         TreeNode* curr=root;
        while(curr!=NULL || !s.empty()){
             while(curr!=NULL){
                 s.push(curr);
                 curr=curr->left;
                 
             }
            curr=s.top();  //storing value of top element of stack.
            s.pop();
             // prev=curr->val;
            if(prev!=NULL && prev->val >=curr->val ){
                return false;
               // continue;
                
            }
            prev=curr;
            curr=curr->right;
        }
       
       return true;;
    }
};

3. O(N) O(N) STACK SIZE  ITERATIVE RANGE BASED

class Solution {
private:
    bool validate(TreeNode* root ,long  low, long  high){
         if(root==NULL) return true;
         if(root->val > low && root->val < high){
            return (validate(root->left, low, root->val) && validate(root->right, root->val, high));
        } else {
            return false;
        }
    }
        
public:
    bool isValidBST(TreeNode* root) {
         return validate(root, LONG_MIN, LONG_MAX);
    }
};


4. 
