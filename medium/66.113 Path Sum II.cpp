/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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

  vector<vector<int> > pathSum(TreeNode* root, int sum) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		if(root == NULL)
			return result;
		else if(root->left == NULL && root->right == NULL)
		{
			if(root->val != sum)
				return result;
			else
			{
				vector<int> r = vector<int>();
				r.push_back(sum);
				result.push_back(r);
				return result;
			}
		}
		else
		{
			vector<vector<int> > r1 = pathSum(root->left, sum-root->val);
			vector<vector<int> > r2 = pathSum(root->right, sum-root->val);	
			for(int i = 0; i < r1.size(); i++)
			{
				vector<int> r = vector<int>();
				r.push_back(root->val);
				for(int j = 0; j < r1[i].size(); j++)
				{
					r.push_back(r1[i][j]);
				}
				result.push_back(r);
			}
			for(int i = 0; i < r2.size(); i++)
      {
        vector<int> r = vector<int>();
        r.push_back(root->val);
        for(int j = 0; j < r2[i].size(); j++)
        {
                r.push_back(r2[i][j]);
        }
        result.push_back(r);
      }
			return result;	
		}	
  }

};

/*
  枚举
*/  
