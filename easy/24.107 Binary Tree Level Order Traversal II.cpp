/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct q_node
{
	TreeNode* node;
	int level;		
};

class Solution 
{

	public:

    	vector<vector<int> > levelOrderBottom(TreeNode* root) 
	{
		
		// first get the height of root
		int len = height(root);

		vector<vector<int> > result;
		// initialize the vectors
		for(int i = 0; i < len; i++)
		{
			result.push_back(vector<int>());	
		}	

		if(root == NULL)
			return result;

		// breadth first search to store result
		
		// store the initial state
		queue<q_node*> my_queue;
		q_node* q = (q_node*)malloc(sizeof(q_node));
		memset(q, 0, sizeof(q));
		q->node = root;		
		q->level = 1;
	
		my_queue.push(q);

		while(my_queue.size() > 0)
		{
			q_node* p = my_queue.front();
			my_queue.pop();
		
			// put it into result, and put all its child into queue
			result[len-p->level].push_back(p->node->val);

			if(p->node->left != NULL)		
			{
				q_node* r = (q_node*)malloc(sizeof(q_node));
				memset(r, 0, sizeof(r));
                		r->node = p->node->left;
                		r->level = p->level+1;

				my_queue.push(r);
			}	

			if(p->node->right != NULL)
                        {
                                q_node* r = (q_node*)malloc(sizeof(q_node));
                                memset(r, 0, sizeof(r));
                                r->node = p->node->right;
                                r->level = p->level+1;

                                my_queue.push(r);
                        }
		}			

		return result;
	}

	// get the height of root
	int height(TreeNode* root)
	{
		if(root == NULL)
			return 0;
		else 
			return max(height(root->left),height(root->right))+1;
	}

};

/*
  感觉自己的方法效率不高。
  首先算出树的层数，为了能够初始化最终的结果的数组。
  然后广度优先搜索记录每层的结点。
*/
