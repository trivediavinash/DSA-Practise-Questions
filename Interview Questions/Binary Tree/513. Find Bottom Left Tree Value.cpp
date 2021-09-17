/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/


1. O(N)+O(N)  O(LogN)+O(LogN)+O(nodes on last level)

// finding height then again traversing to identify the last level
class Solution
{
	public:
		int height(TreeNode *root)
		{
			if (root == NULL) return 0;

			return 1 + max(height(root->left), height(root->right));
		}

	void traversal(TreeNode *root, vector<int> &ans, int ht, int level)
	{
		if (root == NULL) return;

		if (level == ht - 1) ans.push_back(root->val);

		traversal(root->left, ans, ht, level + 1);
		traversal(root->right, ans, ht, level + 1);
	}

	public:
		int findBottomLeftValue(TreeNode *root)
		{
			if (root == NULL) return 0;
			vector<int> ans;
			int ht = height(root);
			traversal(root, ans, ht, 0);
			return ans[0];
		}
};

2.
// O(height) O(LOgN) 
class Solution
{
	void dfs(TreeNode *root, int depth, int &maxDepth, int &ans)
	{
		if (root == NULL) return;

		dfs(root->left, depth + 1, maxDepth, ans);
		dfs(root->right, depth + 1, maxDepth, ans);

		if (depth > maxDepth)
		{
			maxDepth = depth;	//ans will be corrct as we are calling the left funtion first it will not update after it by calling right funtion fo the same level
			ans = root->val;
		}
	}
	public:
		int findBottomLeftValue(TreeNode *root)
		{

			int ans = root->val, maxDepth = 0;	//passing maxDepth and ans as refrence so that its value get updated after each funtion called
			dfs(root, 0, maxDepth, ans);
			return ans;
		}
};

3. O(N) O(N)
class Solution
{

	public:
		int findBottomLeftValue(TreeNode *root)
		{
			queue<TreeNode*> q;
			q.push(root);

			while (!q.empty())
			{
				root = q.front();
				q.pop();

				if (root->right) q.push(root->right);
				if (root->left) q.push(root->left);
			}
			return root->val;	//ans will always be last element processed in the queue 
		}
};
