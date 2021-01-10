/*
102. Binary Tree Level Order Traversal
Medium

3853

92

Add to List

Share
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

1.//  T.C.=(N) S.C.= o(1) for tree having only one child (like linklist) )   (N) ,for perefect tree it will have n/2 nodes in last level ,occupy the same numbr of nodes in the queue somewhere .  

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
          if(root==NULL) return ans;
       
        queue< TreeNode* > level;
        level.push(root);
        
        while(!level.empty()){
          
           int n=level.size();
           vector<int> crtlevel;
           for(int i=0;i<n;i++){
                TreeNode* front =level.front();
                level.pop();
                crtlevel.push_back(front->val);
                //level.pop();
         
                if(front->left) level.push(front->left);
                if(front->right) level.push(front->right);
        }
            ans.push_back(crtlevel);
           
        }
        return ans;
    }
};


