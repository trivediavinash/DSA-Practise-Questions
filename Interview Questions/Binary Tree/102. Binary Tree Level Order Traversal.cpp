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
DFS
1.//  T.C.=(N) S.C. = o(1) for tree having only one child (like linklist)   
//S.C.= O(N) ,for perefect tree it will have n/2 nodes in last level ,occupy the same numbr of nodes in the queue somewhere .  

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

2. BFS  
// T.c. = O(N), S.c. = O(LogN) - for full tree

// S.c. = O(N) for skewed tree link linklist .  

//vector < vector < int >> res; we declare it globally if we do not wamt to pass it to funtion(dfs) each time. 
class Solution {
  private:
    void dfs(vector < vector < int >> & res, TreeNode * root, int level) {
      if (root == NULL) return; //if NULL just return 
      if (level == res.size()) res.push_back({}); //pushing new vector for each level .

      res[level].push_back(root -> val); //pushing value of root 
      dfs(res, root -> left, level + 1); //calling for left subpart and right subpart 
      dfs(res, root -> right, level + 1);
    }
  public:
    vector < vector < int >> levelOrder(TreeNode * root) {
      vector < vector < int >> res;
      dfs(res, root, 0);
      return res;
    }
};

/*
there are tradeoffs,
for very 'lean' tree (most non-leaf node have only one child), this dfs appoach consume O(n) memory, while bfs approach with queue cost almost constant space.
for near complete tree (most non-leaf node have two child), dfs approach cost O(log(n)) memory, whereas bfs approach cost O(n) memory
*/
