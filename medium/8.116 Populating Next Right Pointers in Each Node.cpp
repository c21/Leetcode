/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


/**

 * Definition for binary tree with next pointer.

 * struct TreeLinkNode {

 *  int val;

 *  TreeLinkNode *left, *right, *next;

 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

 * };

 */

class Solution 
{

	public:

    	void connect(TreeLinkNode *root) 
	{
/*
		queue<TreeLinkNode*> my_queue = queue<TreeLinkNode*>();

		if(root != NULL)
		{
			my_queue.push(root);

			while(my_queue.size() > 0)
			{
				TreeLinkNode* p = my_queue.front();
				my_queue.pop();
				if(my_queue.size() > 0)
					p->next = my_queue.front();
				if(p->left != NULL)
					my_queue.push(p->left);
				if(p->right != NULL)
                                        my_queue.push(p->right);		
			}	
			TreeLinkNode* p = root;
			while(p != NULL)
			{
				p->next = NULL;
				p = p->right;
			}
		}		
*/
		if(root != NULL)
		{
			if(root->left != NULL && root->right != NULL)
			{
				root->left->next = root->right;
			
				// connect all the leftmost children and rightmost children
				TreeLinkNode* p = root->left->right;
				TreeLinkNode* q = root->right->left;
				while(p != NULL && q != NULL)
				{
					p->next = q;
					p = p->right;
					q = q->left;
				}		

				connect(root->left);
				connect(root->right);	
			}
		}	
    	}

};

/*
  一开始没想出来怎么做O(1)空间复杂度，使用队列进行广度优先搜索。
  后来发现可以对每个结点，将左孩子指向右孩子，以及左孩子的右结点指向右孩子的左结点，
  依次类推。
*/
