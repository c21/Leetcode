/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

    	vector<vector<int> > levelOrder(TreeNode* root) 
	{
		vector<vector<int> > result = vector<vector<int> >();

		if(root == NULL)
			return result;

		// breadth first search to record each level's node
		// record the initial node				
		queue<node*> my_queue = queue<node*>();

		node* p = (node*)malloc(sizeof(node));
		memset(p, 0, sizeof(p));
		p->t_node = root;	
		p->level = 0;
		int pre_level = -1;

		my_queue.push(p);

		while(my_queue.size() > 0)
		{
			p = my_queue.front();
			my_queue.pop();

			if(p->level != pre_level)
			{
				result.push_back(vector<int>());
				pre_level = p->level;
			}

			// put the node into vector
			result[p->level].push_back(p->t_node->val);

			// if possible, put the children of node into queue
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

		}		
		return result;						
    	}

};

/*
  逐层遍历用BFS, 模拟。
*/
