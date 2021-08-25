/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
 //O(N)  O(N) storing all the nodes in queue 
1. Iterstive BFS  using queue
class Solution
{
	public:
		vector<int> rightSideView(TreeNode *root)
		{
			vector<int> ans;

			if (root == NULL) return {};
			queue<TreeNode*> level;
			level.push(root);

			while (!level.empty())
			{

				int n = level.size();
				for (int i = 0; i < n; i++)
				{

					TreeNode *front = level.front();
					level.pop();
					if (i == n - 1) ans.push_back(front->val);	//if this is the rightmost element in the queue then this is the right node of curreent level, we will traverse from left node to right node in the queue 

					if (front->left) level.push(front->left);	// nodes which are not our answers we will process them first
					if (front->right) level.push(front->right);	//out potential ans will ne processed at last

				}
			}
			return ans;
		}
};

1.1 

class Solution
{
	public:
		vector<int> rightSideView(TreeNode *root)
		{
			vector<int> ans;

			if (root == NULL) return {};
			queue<TreeNode*> level;
			level.push(root);

			while (!level.empty())
			{

				int n = level.size();
				while (n--)
				{

					TreeNode *front = level.front();
					level.pop();
					if (n == 0) ans.push_back(front->val);	//if size of queue is zero after poping,  it means this was the last element of the queue nd last elemnt of queue is always rightmost in current level as we are pushing left children first(it will be at the front) and processing it before the right children .

					if (front->left) level.push(front->left);
					if (front->right) level.push(front->right);
				}
			}
			return ans;
		}
};

2.O(N) O(h) h = height of tree

class Solution
{
	void dfs(vector<int> &ans, TreeNode *root, int level)
	{
		if (root == NULL) return;	//if NULL just return 
		if (level == ans.size()) ans.push_back(root->val);	//makes sure the first element of that level will be added to the result list
		dfs(ans, root->right, level + 1);
		dfs(ans, root->left, level + 1);
	}
	public:
		vector<int> rightSideView(TreeNode *root)
		{
			vector<int> ans;
			dfs(ans, root, 0);

			return ans;
		}
};

// for each depth, we try to take the right side first. If there is one, we add it to the result, which increase the size of result and also prevents from taking the left side.
