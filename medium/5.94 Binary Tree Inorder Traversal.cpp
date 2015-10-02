/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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

struct node
{
	TreeNode* t_node;
	int visit;	// visit = 1 to represent this is the first time to visit this node
};

class Solution i
{

	public:

    	vector<int> inorderTraversal(TreeNode* root) 
	{
		// use a stack to store the root of subtree unvisited
		stack<node*> my_stack = stack<node*>();

		vector<int> result = vector<int>();

		if(root == NULL)	
			return result;

		node* x = (node*)malloc(sizeof(node));
		memset(x, 0, sizeof(x));
		x->t_node = root;
		x->visit = 0;
		my_stack.push(x);
		
		while(my_stack.size() > 0)
		{
			node* p = my_stack.top();
			p->visit++;
			// if this is the first time to visit this node, to visit its left node first
			if(p->visit == 1)
			{
				TreeNode* q = p->t_node;
				q = q->left;
				if(q != NULL)
				{
					node* x = (node*)malloc(sizeof(node));
                			memset(x, 0, sizeof(x));
                			x->t_node = q;
                			x->visit = 0;
                			my_stack.push(x);	
				}	
			}
			// else if this is the second time to visit the node, put it into array 
			// push the right child into stack
			else 
			{
				result.push_back(p->t_node->val);
				my_stack.pop();
				if(p->t_node->right != NULL)
				{
					node* x = (node*)malloc(sizeof(node));
                                        memset(x, 0, sizeof(x));
                                        x->t_node = p->t_node->right;
                                        x->visit = 0;
                                        my_stack.push(x);
				}
			}
			
		}	        
		return result;
    	}

};

/*
  迭代方法：使用一个栈来记录未遍历的结点，按照中序遍历的函数调用特征，
  每个结点相当于观察两次，第一次观察时不将其加入数组，去遍历它的左子树，
  第二次观察时将其加入数组，再遍历它的右子树。
*/
