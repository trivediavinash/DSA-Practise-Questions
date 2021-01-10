/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/.

1. Depth First Search 

class Solution {
public:
    int maxDepth(TreeNode* root) {
       // int count1=0,count2=0;
        if(root==NULL){
            return 0;
        }
        int count1= maxDepth(root->left);
        int count2= maxDepth(root->right);
        return max(count1,count2)+1;
        //return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

2. Breadth first Search

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int depth=0;
        queue< TreeNode* > level;
        level.push(root);
        
        while(!level.empty()){
            depth++;
            int n=level.size();
            for(int i=0;i<n;i++){
                TreeNode* front =level.front();
                level.pop();
                if(front->left) level.push(front->left);
                if(front->right) level.push(front->right);
            }
        }
        return depth;
    }
};