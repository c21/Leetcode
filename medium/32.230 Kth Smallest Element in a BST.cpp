/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
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

    	int kthSmallest(TreeNode* root, int k) 
	{
		vector<int> array = vector<int>();

		get_array(root, array);	
		return array[k-1];	
    	} 

	void get_array(TreeNode* root, vector<int>& array)
	{
		if(root != NULL)
		{
			get_array(root->left, array);
			array.push_back(root->val);
			get_array(root->right, array);	
		}
	}
};

/*
  中序遍历二叉搜索树，得到序列，再选择第k个即可。
*/
