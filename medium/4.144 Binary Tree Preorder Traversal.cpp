/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

    	vector<int> preorderTraversal(TreeNode* root) 
	{
		// use a stack to store the child unvisited
		stack<TreeNode*> my_stack = stack<TreeNode*>();

		vector<int> result = vector<int>();

		if(root == NULL)
			return result;

		my_stack.push(root);
		while(my_stack.size() > 0)
		{
			TreeNode* p = my_stack.top();
			my_stack.pop();

			while(p != NULL)
			{
				result.push_back(p->val);
				if(p->right != NULL)
					my_stack.push(p->right);	
				p = p->left;
			}
		}		
		return result;	
    	}

};

/*
  迭代做法：使用一个栈来保存初始结点和未遍历的右子树结点，根据先序遍历函数调用特征，
  在遍历完左子树后，逆序遍历每个右子树。
*/
