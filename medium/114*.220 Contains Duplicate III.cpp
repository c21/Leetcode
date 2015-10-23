/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

class Solution 
{

  public:

  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
  {
    if(k < 1 || t < 0 || nums.size() < 2)
      return false;
    
    map<long long, long long> my_map = map<long long, long long>();
    for(long long i = 0; i < nums.size(); i++)
    {
      map<long long, long long>::iterator p = my_map.lower_bound(nums[i]-t);
      if(p != my_map.end() && abs(p->first-nums[i]) <= t)
              return true;
      my_map[nums[i]] = i;
      if(i-k >= 0)
        my_map.erase(nums[i-k]);
    }
    return false;
  }

};

/*
  这题没有想出来。
  答案使用的方法是从左到右扫描，用map来存已经扫描的数，保持存的数的数目不超过k. 删除数用erase.
  查找使用lower_bound(i), 即找到不小于i的第一个数。
*/
