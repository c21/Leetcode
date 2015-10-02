/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution
{

        public:

        int singleNumber(vector<int>& nums) 
        {
                unordered_map<int,int> my_map = unordered_map<int,int>();
                for(int i = 0; i < nums.size(); i++)
                {
                        if(my_map.find(nums[i]) == my_map.end())
                                my_map[nums[i]] = 1;
                        else
                                my_map[nums[i]]++;
                }
                for(unordered_map<int,int>::iterator p = my_map.begin(); p != my_map.end(); p++)
                {
                        if(p->second == 1)
                                return p->first;
                }

        }

};

/*
  使用unordered_map可以达到O(n)时间复杂度，不过使用了非常数空间。
  看了答案发现可以使用异或可以达到常数空间，需要知道两个整数相异或为按位异或。
  比如12^11^12^11 = 0
*/
