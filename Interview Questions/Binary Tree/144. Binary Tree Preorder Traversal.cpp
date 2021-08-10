/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up:

Recursive solution is trivial, could you do it iteratively?
*/
1.Recursive o(N) o(N) call stack space

class Solution {
public:
    //paasing ans by reference so that after each call of traversal fun  vector ans get update in main funtion.
    void traversal(TreeNode* root, vector<int>&ans){ 
        if(root==NULL) return ;
        ans.push_back(root->val);
         traversal(root->left ,ans);
       
         traversal(root->right ,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
         traversal(root,ans);
         return ans;
    }
};

2.Iterative O(N) O(N) 

class Solution {
public:
  
    
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
         if(root==NULL) return ans;
         stack<TreeNode*>s;
         s.push(root);
         while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            ans.push_back(node->val);
             if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
                
            }
           
        }
        return ans;
    }
};

3. Iterative O(N) O(N)  Pushes only right nodes to stack 

class Solution {
public:
  
    
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
         if(root==NULL) return ans;
         stack<TreeNode*>s;
         s.push(root);
         TreeNode* curr= root;
         while(!s.empty() ){
              // if current node is not null, print it and push its right child
             // to the stack and move to its left child
             if(curr!=NULL){
                 ans.push_back(curr->val);   //pushing only the left children into ans 
                 if(curr->right){               
                     s.push(curr->right);   //checking right nodes and pushing it into stack 
                     
                 }
               curr=curr->left;
             }   
           
             else{
                 // else if current node is null, we pop a node from the stack
                // set current node to the popped node
                 curr=s.top();
                 s.pop();
             }
           
         }  
        return ans;
    }
};
