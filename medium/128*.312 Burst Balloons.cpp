/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution 
{
    public:
    int maxCoins(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        vector<vector<int> > r(nums.size()+2, vector<int>(nums.size()+2, -1));
        vector<int> new_nums;
        new_nums.push_back(1);
        for(int i = 0; i < nums.size(); i++)
            new_nums.push_back(nums[i]);
        new_nums.push_back(1);
        return get_max(new_nums, r, 0, new_nums.size()-1);
    }
    
    int get_max(vector<int>& nums, vector<vector<int> >& r, int b, int e)
    {
        if(r[b][e] != -1)
            return r[b][e];
        else if(b+2 == e)
        {
            r[b][e] = nums[b]*nums[b+1]*nums[e];
            return r[b][e];
        }
        else
        {
            r[b][e] = 0;
            for(int i = b+1; i <= e-1; i++)
            {
                int r1 = 0;
                if(i-b >= 2)
                    r1 = get_max(nums, r, b, i);
                int r2 = 0;
                if(e-i >= 2)
                    r2 = get_max(nums, r, i, e);
                r[b][e] = max(r[b][e], r1+r2+nums[b]*nums[i]*nums[e]);
            }
            return r[b][e];
        }
    }
};

/*
  一开始没有想出来，是动态规划。设f(i,j)代表扎破i+1至j-1气球的最大收益。
  则枚举i+1至j-1中扎破的最后一个气球位置k (i+1 <= k <= j-1)
  f(i,j) = max(f(i,k) + f(k,j) + nums[i]*nums[k]*nums[j]).
*/
