/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

	vector<TreeNode*> generateTrees(int n) 
	{
		if(n == 0)
		{
			vector<TreeNode*> r = vector<TreeNode*>();
			r.push_back(NULL);
			return r;
		}
		else
			return gen_tree(1, n);	
	}

	vector<TreeNode*> gen_tree(int begin, int end)
	{
		vector<TreeNode*> result = vector<TreeNode*>();
		if(begin == end)
		{
			TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
                	memset(root, 0, sizeof(root));
			root->val = begin;
			root->left = NULL;
			root->right = NULL;
			result.push_back(root);
		}		
		else
		{
			for(int i = begin; i <= end; i++)
			{

				if(i == begin)
				{
					vector<TreeNode*> r1 = gen_tree(i+1, end);
					for(int j = 0; j < r1.size(); j++)
					{
						TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
                                		memset(root, 0, sizeof(root));
                                		root->val = i;
						root->right = r1[j];
						root->left = NULL;
						result.push_back(root);
					}
				}
				else if(i == end)
				{
					vector<TreeNode*> r1 = gen_tree(begin, i-1);
                                        for(int j = 0; j < r1.size(); j++)
                                        {
                                                TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
                                                memset(root, 0, sizeof(root));
                                                root->val = i;
                                                root->left = r1[j];
						root->right = NULL;
                                                result.push_back(root);
                                        }
				}
				else
				{
					vector<TreeNode*> r1 = gen_tree(begin, i-1);
                                        vector<TreeNode*> r2 = gen_tree(i+1, end);
					for(int j = 0; j < r1.size(); j++)
                                        {
						for(int k = 0; k < r2.size(); k++)
						{
                                                	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
                                                	memset(root, 0, sizeof(root));
                                                	root->val = i;
                                                	root->left = r1[j];
                                                	root->right = r2[k];
							result.push_back(root);
                                        	}
					}
				}
			}	
		}
		return result;
	}	

};

/*
  枚举
*/
