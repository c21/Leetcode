/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/



class Solution
{

  public:

  bool search(vector<int>& nums, int target)
  {
          for(int i = 0; i < nums.size(); i++)
          {
                  if(target == nums[i])
                          return true;
          }
          return false;
  }

};

/*
  有最坏情况为O(n)的折半搜索方法，以后再做。
*/
