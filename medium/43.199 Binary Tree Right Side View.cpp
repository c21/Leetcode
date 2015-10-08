/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
	int level;
};

class Solution 
{

	public:

	
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> result = vector<int>();
		
		if(root == NULL)
			return result;
		else
		{	
			node* p = (node*)malloc(sizeof(node));
			memset(p, 0, sizeof(p));
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
                        		memset(q, 0, sizeof(q));
                        		q->t_node = p->t_node->left;
                        		q->level = p->level+1;
        				my_queue.push(q);
				}
				if(p->t_node->right != NULL)
                                {
                                        node* q = (node*)malloc(sizeof(node));
                                        memset(q, 0, sizeof(q));
                                        q->t_node = p->t_node->right;
                                        q->level = p->level+1;
                                        my_queue.push(q);
                                }

				if(my_queue.size() == 0 || my_queue.front()->level == p->level+1)
					result.push_back(p->t_node->val);		
			}

			return result;
		}	
	}


};

/*
  要注意并不是一直遍历右子树，是需要得到每层的最后一个结点，使用广度优先搜索即可。
*/
