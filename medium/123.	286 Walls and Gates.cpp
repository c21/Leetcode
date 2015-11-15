Walls and Gates

Question
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647. Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

 3  -1   0   1
 2   2   1  -1
 1  -1   2  -1
 0  -1   3   4
 
 struct node
{
    int x;
    int y;
    int d;
    node(int a, int b, int c)
    {
        x = a;
        y = b;
        d = c;
    }
};
class Solution 
{
    public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if(rooms.size() == 0 || rooms[0].size() == 0)
            return;
        for(int i = 0; i < rooms.size(); i++)
        {
            for(int j = 0; j < rooms[i].size(); j++)
            {
                if(rooms[i][j] == 0)
                    search(rooms, i, j);
            }
        }
    }
    
    int dic_x[4] = {0, -1, 0, 1};
    int dic_y[4] = {-1, 0, 1, 0};
    
    void search(vector<vector<int>>& rooms, int x, int y)
    {
        queue<node> my_queue;
        my_queue.push(node(x, y, 0);
        while(my_queue.size() > 0)
        {
            node p = my_queue.front();
            my_queue.pop();
            for(int i = 0; i < 4; i++)
            {
                int new_x = p.x+dic_x[i];
                int new_y = p.y+dic_y[i];
                if(new_x >= 0 && new_x < rooms.size() && new_y >= 0 && new_y < rooms[0].size() && rooms[new_x][new_y] > p.d+1)
                {
                    rooms[new_x][new_y] = p.d+1;
                    my_queue.push(node(new_x,new_y, p.d+1));
                }
            }
        }
    }
};

/*
  用广度优先搜索遍历所有的0点，确定最短距离。
*/
