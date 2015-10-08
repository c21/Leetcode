/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class BSTIterator 
{

	public:

	stack<TreeNode*> my_stack;

  BSTIterator(TreeNode *root) 
	{
		my_stack = stack<TreeNode*>();
		TreeNode* p = root;
		while(p != NULL)
		{
			my_stack.push(p);
			p = p->left;
		}	 
  }



  /** @return whether we have a next smallest number */

  bool hasNext() 
	{
		return my_stack.size() != 0;
  }



  /** @return the next smallest number */

  int next() 
	{
		TreeNode* result = my_stack.top();
		my_stack.pop();
		if(result->right != NULL)
		{
			TreeNode* p = result->right;
			while(p != NULL)
			{
				my_stack.push(p);
				p = p->left;
			}	
		}
		return result->val;	
  }

};



/**

 * Your BSTIterator will be called like this:

 * BSTIterator i = BSTIterator(root);

 * while (i.hasNext()) cout << i.next();

 */
 
 /*
  模仿中序遍历，使用一个栈来存放当前还未遍历的子树根结点。
  如果遍历结点结束，将该结点的右孩子，以及右孩子的子树的所有最左结点依次压栈，保留大小顺序。
  由于每个结点压栈，出栈各1次，next()操作平均时间复杂度为O(1). 
  由于栈上最多存放从根结点到栈顶结点路径上的所有结点，所以空间复杂度为O(h).
 */
