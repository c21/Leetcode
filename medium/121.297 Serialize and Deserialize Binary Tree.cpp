/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

struct node
{
    TreeNode* t_node;
    TreeNode* parent;
    int flag;
    node(TreeNode* a, TreeNode* b, int c)
    {
        t_node = a;
        parent = b;	
        flag = c;
    }
};

class Codec 
{
    public:

        // Encodes a tree to a single string.
    	string serialize(TreeNode* root) 
        {
            string s = "";
            if(root == NULL)
            return s;
            queue<node> my_queue;
            node r(root, NULL, 0);
            my_queue.push(r);
            while(my_queue.size() > 0)
            {
            	node p = my_queue.front();
            	my_queue.pop();
            	if(p.t_node == root)
            	{
            		s += "-1 0 " + to_string(p.t_node->val) + " " + to_string((long long)p.t_node);
            	}
            	else
            	{
            	    s += " " + to_string((long long)p.parent) + " " + to_string(p.flag) + " " + to_string(p.t_node->val) + " " + to_string((long long)p.t_node);
            	}
            	if(p.t_node->left != NULL)
            	{
            		node q(p.t_node->left, p.t_node, 0);
            		my_queue.push(q);
            	}
            	if(p.t_node->right != NULL)
            	{
            		node q(p.t_node->right, p.t_node, 1);
            		my_queue.push(q);
            	}
            }
            
            return s;	
        }

    	// Decodes your encoded data to tree.
    	TreeNode* deserialize(string data) 
        {
        	if(data == "")
        		return NULL;
        	long long parent;
        	long long now;
        	long long flag;
            long long val;
        	stringstream scin(data);
        	unordered_map<long long, TreeNode*> map;
        	int root;
            while(scin >> parent >> flag >> val >> now)
        	{
        		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
        		p->left = NULL;
        		p->right = NULL;
        		p->val = val;
        		map[now] = p;
        		if(parent == -1)
        		{
        			root = now;	
        		}
        		else if(map.find(parent) != map.end())
        		{
        			if(flag == 0)
        				map[parent]->left = p;
        			else
        				map[parent]->right = p;
        		}
        	}
        	return map[root];
      }
};

/*
  记录每个结点的地址，父亲结点的地址，结点的值，是左孩子还是右孩子。
*/
