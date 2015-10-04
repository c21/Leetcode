/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

    	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		return genTree(nums, 0, nums.size()-1);	
    	}
	
	TreeNode* genTree(vector<int>& nums, int begin, int end)
	{
		if(begin > end)
			return NULL;
		else
		{
			TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
			memset(p, 0, sizeof(p));
			int mid = (begin+end)/2;
			p->val = nums[mid];
		
			p->left = genTree(nums, begin, mid-1);
			p->right = genTree(nums, mid+1, end);
			return p;	
		}
	}
};

/*
  每次二分，选中间的元素作为树根。
*/
