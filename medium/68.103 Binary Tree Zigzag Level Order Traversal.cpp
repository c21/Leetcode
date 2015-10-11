/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

  vector<vector<int> > zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		if(root == NULL)
			return result;
		
		node* p = (node*)malloc(sizeof(node));
		p->t_node = root;
		p->level = 1;
		queue<node*> my_queue = queue<node*>();
		my_queue.push(p);

		vector<int> r = vector<int>();	

		while(my_queue.size() > 0)
		{
			node* p = my_queue.front();
			my_queue.pop();
			if(p->t_node->left != NULL)
			{
				node* q = (node*)malloc(sizeof(node));
                		q->t_node = p->t_node->left;
                		q->level = p->level+1;
                		my_queue.push(q);
			}
			if(p->t_node->right != NULL)	
			{
				node* q = (node*)malloc(sizeof(node));
                                q->t_node = p->t_node->right;
                                q->level = p->level+1;
                                my_queue.push(q);	
			}

			if(my_queue.size() == 0 || p->level != my_queue.front()->level)
			{
				r.push_back(p->t_node->val);
				if(p->level % 2 == 0)
					reverse(r.begin(), r.end());
				result.push_back(r);
				r = vector<int>();	
			}	
		}	 
		return result;				
	}

};

/*
  广度优先搜索
*/
