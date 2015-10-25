/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**

 * Definition for binary tree with next pointer.

 * struct TreeLinkNode {

 *  int val;

 *  TreeLinkNode *left, *right, *next;

 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

 * };

 */

struct node
{
	TreeLinkNode* t_node;
	int level;	
};

class Solution 
{

	public:

	void connect(TreeLinkNode *root) 
	{
		if(root == NULL)
			return;
		node* p = (node*)malloc(sizeof(node));
		p->t_node = root;
		p->level = 1;
		queue<node*> my_queue = queue<node*>();
		my_queue.push(p);

		while(my_queue.size() > 0)
		{
			node* p = my_queue.front();
			my_queue.pop();
			if(p->t_node->left != NULL)
			{
				node* q = (node*)malloc(sizeof(node));
    		q->t_node = p->t_node->left;
    		q->level = p->level + 1;
    		my_queue.push(q);
			}		
			if(p->t_node->right != NULL)
      {
        node* q = (node*)malloc(sizeof(node));
        q->t_node = p->t_node->right;
        q->level = p->level + 1;
        my_queue.push(q);
      } 
			p->t_node->next = NULL;
			if(my_queue.size() > 0 && my_queue.front()->level == p->level)
			{
				p->t_node->next = my_queue.front()->t_node;
			}
		}						
	}

};

/*
  没有使用常数空间，用广度优先搜索。
*/
