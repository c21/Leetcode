/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**

 * Definition for singly-linked list with a random pointer.

 * struct RandomListNode {

 *     int label;

 *     RandomListNode *next, *random;

 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

 * };

 */

class Solution 
{

	public:

	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		unordered_map<RandomListNode*, RandomListNode*> map = unordered_map<RandomListNode*, RandomListNode*>();
		RandomListNode* h = NULL;
		RandomListNode* pre = NULL;
		RandomListNode* p = head;
		while(p != NULL)
		{
			RandomListNode* q = (RandomListNode*)malloc(sizeof(RandomListNode));
			q->label = p->label;
			q->next = NULL;
			q->random = p->random;	
			if(h == NULL)
			{
				h = q;
				pre = q;
			}	
			else
			{
				pre->next = q;
				pre = q;
			}
			map[p] = q;
			p = p->next;
		}
		p = h;
		while(p != NULL)
		{
			if(p->random != NULL)
			{
				p->random = map[p->random];
			}
			p = p->next;
		}			
		return h;	
	}

};

/*
  使用一个表记录新建结点和原始结点的对应关系。
  扫描第二遍时，将random从原始结点改成对应的新建结点。
*/
