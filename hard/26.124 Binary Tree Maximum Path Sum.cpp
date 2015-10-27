/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution 
{

	public:


	int max_val = 0;
	int first_time = 1;
	int maxPathSum(TreeNode* root) 
	{
		first_time = 1;
		get_path(root);
		return max_val;		
	}

	pair<int,int> get_path(TreeNode* root) 
	{
		if(root == NULL)
			return make_pair(0,0);
		else if(root->left == NULL && root->right == NULL)
		{
			int r = root->val;
			if(first_time || max_val < r)
      {
        first_time = 0;
        max_val = r;
      }
			return make_pair(0,0);	
		}
		else if(root->left != NULL && root->right == NULL)
		{
			pair<int,int> p1 = get_path(root->left);
			int r1 = max(max(p1.first, p1.second),0) + root->left->val;	
			pair<int,int> result(r1, 0);	
			int r = max(r1,0) + root->val;
			if(first_time || max_val < r)
			{
				first_time = 0;
				max_val = r;
			}
				
			return result;	
		}	
		else if(root->left == NULL && root->right != NULL)
		{
			pair<int,int> p2 = get_path(root->right);
      int r2 = max(max(p2.first, p2.second),0) + root->right->val;
      pair<int,int> result(0, r2);
      int r = max(r2,0) + root->val;
			if(first_time || max_val < r)
      {
        first_time = 0;
        max_val = r;
      }

      return result;
		}	
		else	
		{
			pair<int,int> p1 = get_path(root->left);
      int r1 = max(max(p1.first, p1.second),0) + root->left->val;

			pair<int,int> p2 = get_path(root->right);
      int r2 = max(max(p2.first, p2.second),0) + root->right->val;

			int r = max(r1, 0) + max(r2, 0) + root->val;
			if(first_time || max_val < r)
      {
        first_time = 0;
        max_val = r;
      }

			pair<int,int> result(r1, r2);
			return result;	
		}
	}

};

/*
  求出每一点
  左子树(必须包括左孩子)的最大单路径和
  右子树(必须包括右孩子)的最大单路径和
  这样，再在每一点求最大左单路径和，最大右单路径和，和最大双路径和。
*/
