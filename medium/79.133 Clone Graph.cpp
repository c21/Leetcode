/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**

 * Definition for undirected graph.

 * struct UndirectedGraphNode {

 *     int label;

 *     vector<UndirectedGraphNode *> neighbors;

 *     UndirectedGraphNode(int x) : label(x) {};

 * };

 */

class Solution 
{

	public:

	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> my_map;
	
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
	{
		if(node == NULL)
			return NULL;
		else
		{
			my_map = unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>();
			return clone_g(node);			
		}
	}

	UndirectedGraphNode* clone_g(UndirectedGraphNode* root)
	{
		UndirectedGraphNode* p = new UndirectedGraphNode(root->label);
		my_map[root] = p;
		p->neighbors = vector<UndirectedGraphNode *>();
		for(int i = 0; i < root->neighbors.size(); i++)
		{
			if(my_map.find(root->neighbors[i]) == my_map.end())
			{
				p->neighbors.push_back(clone_g(root->neighbors[i]));	
			}
			else
			{
				p->neighbors.push_back(my_map[root->neighbors[i]]);
			}
		}	
		return p;	
	}
};

/*
  深度优先搜索
*/
