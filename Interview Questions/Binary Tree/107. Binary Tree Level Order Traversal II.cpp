/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

1.  O(N) (N)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
       
          if(root==NULL) return ans;
        stack<vector<int>>s;
       
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
            s.push(crtlevel);
           
        }
       while (!s.empty()){
           ans.push_back(s.top());
           s.pop();
           }
        return ans;
    }
};

2. O(N) O(N)

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
       reverse(ans.begin(), ans.end());
       return ans;
    }
};
