/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

class Solution 
{

	public:

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		if(numCourses == 0 || numCourses == 1)
			return true;
		vector<vector<int> > edge = vector<vector<int> >();
		vector<int> visit = vector<int>();
		for(int i = 0; i < numCourses; i++)
		{
			edge.push_back(vector<int>());
			visit.push_back(0);
		}
		for(int i = 0; i < prerequisites.size(); i++)
		{
			edge[prerequisites[i].first].push_back(prerequisites[i].second);
		}			

		for(int i = 0; i < edge.size(); i++)
		{
			if(visit[i] == 0)
			{
				if(!dfs_search(i, edge, visit))
					return false;
			}
		}	

		return true;	
	}

	bool dfs_search(int x, vector<vector<int> >& edge, vector<int>& visit)
	{
		visit[x] = 1;
		for(int i = 0; i < edge[x].size(); i++)
		{
			if(visit[edge[x][i]] == 1)
				return false;
			else
			{
				if(!dfs_search(edge[x][i], edge, visit))
					return false;
			}
		}
		visit[x] = 2;
		return true;
	}
};

/*
  能够上完全部课等价于该有向图中没有环，需要检测该图中是否有环即可，使用深度优先搜索。
  如果出现一个点指向尚未遍历结束的点，则有环。否则，无环。
*/
