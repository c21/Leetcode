/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

class Solution 
{

	public:

	int count = 0;

	void recoverTree(TreeNode* root) 
	{
		if(root != NULL)
		{
			vector<int> record = vector<int>();
			inorder(root, record);
	
			sort(record.begin(), record.end());		
	
			count = 0;		
			change(root, record);
		}
	}

	void inorder(TreeNode* root, vector<int>& record)
	{
		if(root != NULL)
		{
			if(root->left != NULL)
				inorder(root->left, record);
			record.push_back(root->val);
			if(root->right != NULL)
        inorder(root->right, record);
		}
	}

	void change(TreeNode* root, vector<int>& record)
	{
		if(root != NULL)
		{
			if(root->left != NULL)
        change(root->left, record);
      root->val = record[count];
			count++;
      if(root->right != NULL)
        change(root->right, record);
		}
	}
};

/*
  这里是O(N)空间复杂度的做法，O(1)的方法没有想出来，以后再做。
*/

/*
	下面是O(1)空间复杂度的做法。
	用线索二叉树来进行中序遍历，记录可能的一个或两个逆序位置。
	线索二叉树：右孩子结点指向中序遍历的后继结点。
	方法：
	1. 如果左孩子不为空。
		从左孩子的右结点遍历，找到指向该结点，或为空。
			1.1 如果指向该结点，说明左子树已经遍历过，这时检查该结点和该右结点，并且还原树结构
			1.2 如果指向空，说明左子树未遍历过，这时遍历左子树
	2. 如果左孩子为空。
		检查前驱结点和该结点，遍历右子树。
*/
class Solution 
{
    public:
    void recoverTree(TreeNode* root) 
    {
    	TreeNode* p1, *p1_next, *p2;
    	int count = 0;
    	TreeNode* p = root;
    	TreeNode* prev = NULL;
    	while(p != NULL)
    	{
    		if(p->left != NULL)
    		{
                    TreeNode* q = p->left;
    				while(q->right != NULL && q->right != p)
    					q = q->right;
    				if(q->right == NULL)
    				{
    					q->right = p;
    					p = p->left;
    				}
    				else
    				{
    					q->right = NULL;
    					if(prev != NULL)
            		    {   
            		        if(prev->val > p->val)
            		        {
            		            if(count == 1)
            		                p2 = p;
            		            else
            		            {
            		                p1 = prev;
            		                p1_next = p;
            		            }    
            		            count++;
            		        }
            		    }
                		prev = p;
                		p = p->right;
                	}
    		}
    		else
    		{
    		    if(prev != NULL)
    		    {   
    		        if(prev->val > p->val)
    		        {
    		            if(count == 1)
    		                p2 = p;
    		            else
    		            {
    		                p1 = prev;
    		                p1_next = p;
    		            }    
    		            count++;
    		        }
    		    }
    			
        		prev = p;
        		p = p->right;
    
    		}
    	}
    	if(count == 1)
    	{
    		int tmp = p1->val;
    		p1->val = p1_next->val;
    		p1_next->val = tmp;
    	}
    	else
    	{
    		int tmp = p1->val;
    		p1->val = p2->val;
    		p2->val = tmp;
    	}
    }
};
