/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
	int num;
};

class Solution 
{

	public:
	
	vector<int> postorderTraversal(TreeNode* root) 
	{
		stack<node*> my_stack = stack<node*>();
		vector<int> result = vector<int>();
		if(root == NULL)
			return result;
		node* p = (node*)malloc(sizeof(node));
		p->t_node = root;
		p->num = 0;
		my_stack.push(p);

		while(my_stack.size() > 0)
		{
			node* p = my_stack.top();
			if(p->num == 0)
			{
				p->num = 1;
				if(p->t_node->left != NULL)
				{
					node* q = (node*)malloc(sizeof(node));
    			q->t_node = p->t_node->left;
    			q->num = 0;
    			my_stack.push(q);
				}	
			}	
			else if(p->num == 1)
			{
				p->num = 2;
				if(p->t_node->right != NULL)
        {
          node* q = (node*)malloc(sizeof(node));
          q->t_node = p->t_node->right;
          q->num = 0;
          my_stack.push(q);
        }
			}
			else
			{
				my_stack.pop();
				result.push_back(p->t_node->val);
			}
		}					

		return result;		
	}

};

/*
  使用一个栈来记录还未遍历完的结点。
*/
