/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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

    	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> path = vector<string>();
		if(root == NULL)
			return path;

		string s = to_string(root->val);
		if(root->left == NULL && root->right == NULL)
		{
			path.push_back(s);
			return path;	
		}
		
		if(root->left != NULL)
		{
			vector<string> p2 = binaryTreePaths(root->left);
			for(int i = 0; i < p2.size(); i++)
			{
				path.push_back(s + "->" + p2[i]);
			}		
			
		}
		if(root->right != NULL)
		{
			vector<string> p2 = binaryTreePaths(root->right);
                        for(int i = 0; i < p2.size(); i++)
                        {
                                path.push_back(s + "->" + p2[i]);
                        }
		}
		return path;
       
    	}

};

/*
  模拟
*/
