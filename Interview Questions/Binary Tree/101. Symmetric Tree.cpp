/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/

1. O(N) O(LogN) or O(1)

class Solution
{
	// here we are comparing the subtrees not the left or right child of any single tree.
	// think in terms of subtrees not in left and right childs of single tree
	public:
		bool checkSubtree(TreeNode *leftt, TreeNode *rightt)
		{
			if (leftt == NULL && rightt == NULL) return true;	//leftt and rightt here represent pointers of left subtree and right subtree not the left and right children of any single parent  node in either left subtree or right subtree. 

			if (leftt == NULL or rightt == NULL) return false;

			if (leftt->val != rightt->val) return false;

			bool funtioncall1 = checkSubtree(leftt->left, rightt->right);	//first funtion call will compare child of leftsubtree with the right children of right subtree. 
			bool funtioncall2 = checkSubtree(leftt->right, rightt->left);	// second funtion call simuntanously comapre right children of left subtree with the left children of right subtree. 
			return funtioncall1 && funtioncall2;	//if both funtion will return true it means they are symmetric

		}
	bool isSymmetric(TreeNode *root)
	{
		if (root == NULL) return true;	// if node is NULL;

		return checkSubtree(root->left, root->right);	//passing the left children of root node and right children .

	}
};

2. O(N) O(h) h is height of tree  using queue


class Solution
{
	public:
		bool isSymmetric(TreeNode *root)
		{
			//if (root == NULL) return true;	//for single null node

			queue<TreeNode*> q;
			//no point of pushing first root, so directly pushing left nd right child  
			q.push(root->left);
			q.push(root->right);

			while (!q.empty())
			{
				TreeNode *leftt = q.front();
				q.pop();
				TreeNode *rightt = q.front();
				q.pop();
				if (leftt == NULL && rightt == NULL) continue;	// we have to put this statement before the  if(leftt == NULL || rightt == NULL  || rightt->val != leftt->val) return false; otherwise it will give wrong output . 

				if (leftt == NULL || rightt == NULL || rightt->val != leftt->val) return false;

				q.push(leftt->left);
				q.push(rightt->right);

				q.push(leftt->right);
				q.push(rightt->left);
			}
			return true;
		}
};

3. O(N) O(h) h = height of tree  using stack 

class Solution
{
	public:
		bool isSymmetric(TreeNode *root)
		{
			if (root == NULL) return true;	//for single null node

			stack<TreeNode*> s;
			//no point of pushing first root, so directly pushing left nd right child  
			s.push(root->left);
			s.push(root->right);

			while (!s.empty())
			{
				TreeNode *leftt = s.top();
				s.pop();
				TreeNode *rightt = s.top();
				s.pop();
				if (leftt == NULL && rightt == NULL) continue;	// we have to put this statement before the  if(leftt == NULL || rightt == NULL  || rightt->val != leftt->val) return false; otherwise it will give wrong output . 

				if (leftt == NULL || rightt == NULL || rightt->val != leftt->val) return false;

				s.push(leftt->left);
				s.push(rightt->right);

				s.push(leftt->right);
				s.push(rightt->left);
			}
			return true;
		}
};


