/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    int max_num = nums[0];
    int min_num = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(max_num < nums[i])
            max_num = nums[i];
        if(min_num > nums[i])
            min_num = nums[i];
    }
    
    int b_size = (max_num-min_num)/nums.size()+1;
    int b_len = (max_num-min_num)/b_size+1;
    vector<vector<int> > bucket(b_len);
    for(int i = 0; i < nums.size(); i++)
    {
      int p = (nums[i]-min_num) / b_size;
      if(bucket[p].size() == 0)
      {
          bucket[p].push_back(nums[i]);
          bucket[p].push_back(nums[i]);
      }
      else
      {
        if(nums[i] < bucket[p][0])
            bucket[p][0] = nums[i];
        if(nums[i] > bucket[p][1])
            bucket[p][1] = nums[i];
      }
    }
    int res = 0;
    int prev = 0;
    for(int i = 1; i < b_len; i++)
    {
      if(bucket[i].size() > 0)
      {
        res = max(res, bucket[i][0] - bucket[prev][1]);
        prev = i;
      }
    }
    return res;
  }
};

/*
  bucket sorting 
*/
