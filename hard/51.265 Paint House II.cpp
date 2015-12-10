/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note
All costs are positive integers.

Follow up: Could you solve it in O(nk) runtime?
*/

class Solution 
{
    public:
    int minCostII(vector<vector<int>>& costs) 
    {
            vector<int> array(costs[0].size(), 0);
            vector<int> f(costs[0].size(), 0);
            for(int i = costs.size()-1; i >= 0; i--)
            {
                if(i == costs.size()-1)
                {
                    for(int j = 0; j < costs[i].size(); j++)
                        f[j] = costs[i][j];
                }
                else
                {
                    for(int j = 0; j < costs[i].size(); j++)
                        f[j] = costs[i][j] + array[j];
                }
                update_min(array, f);
            }
            int r = f[0];
            for(int i = 1; i < f.size(); i++)
                r = min(r, f[i]);
            return r;
    }
    
    void update_min(vector<int>& array, vector<int>& f)
    {
         int min_left = f[0];
         for(int i = 1; i < array.size(); i++)
         {
             array[i] = min_left;
             min_left = min(min_left, f[i]);
         }
         int min_right = f[array.size()-1];
         for(int i = array.size()-2; i >= 0; i--)
         {
             if(i == 0)
                 array[i] = min_right;
             else
                 array[i] = min(array[i], min_right);
             min_right = min(min_right, array[i]);
         }
    }
};
