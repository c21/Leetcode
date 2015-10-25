/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> my_map = map<int,int>();
        for(int i = 0; i < nums.size(); i++)
          my_map[nums[i]] = 1;
        int len = 1;
        int pre = 0;
        int t_len = 0;
        for(map<int,int>::iterator p = my_map.begin(); p != my_map.end(); p++)
        {
          if(p == my_map.begin())
          {
                  t_len = 1;
          } 
          else
          {
                  if(pre + 1 == p->first)
                  {
                          t_len++;
                  }
                  else
                  {
                          if(t_len > len)
                                  len = t_len;
                          t_len = 1;
                  }        
          }       
          pre = p->first;
        }
        return max(t_len, len);
    }
};

/*
  这里的方法是O(nlogn). 记录每个结点，然后扫描。
  O(n)的方法可以是用哈希表记录每个结点的值和位置。
  然后对每个结点进行扫描，以该结点的中心，向两边+/-1扫描检查。
*/
