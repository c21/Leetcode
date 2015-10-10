/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
	node* prev;
	int level;
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if(root == NULL || p == NULL || q == NULL)
			return NULL;
		node* x = (node*)malloc(sizeof(node));
		x->t_node = root;
		x->prev = NULL;
		x->level = 1;
		
		queue<node*> my_queue = queue<node*>();
	
		my_queue.push(x);

		int flag = 0;
		node* np = NULL;
		node* nq = NULL;

		while(my_queue.size() > 0 && flag < 2)
		{
			node* x = my_queue.front();
			my_queue.pop();
			if(x->t_node == p)
			{
				np = x;
				flag++;
			}
			if(x->t_node == q)
			{
				nq = x;
				flag++;
			}
			if(x->t_node->left != NULL)
			{
				node* y = (node*)malloc(sizeof(node));
        y->t_node = x->t_node->left;
        y->prev = x;
        y->level = x->level+1;
				my_queue.push(y);
			}		
			if(x->t_node->right != NULL)
      {
        node* y = (node*)malloc(sizeof(node));
        y->t_node = x->t_node->right;
        y->prev = x;
        y->level = x->level+1;
        my_queue.push(y);
      }
		}			
	
		if(np == NULL || nq == NULL)
			return NULL;
		while(np->level > nq->level)
		{
			np = np->prev;
		}
		while(np->level < nq->level)
		{
			nq = nq->prev;
		}	
		while(np != nq)
		{
			nq = nq->prev;	
			np = np->prev;
		}
		return np->t_node;
	}


};

/*
  用的方法是用广度优先搜索找到两个点，并逐层向上搜索，找到最小公共祖先。
*/
