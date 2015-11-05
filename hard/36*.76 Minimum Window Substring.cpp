/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

class Solution 
{

	public:

	string minWindow(string s, string t) 
	{
		if(s.length() == 0 || t.length() == 0)
			return "";
	
		unordered_map<char, int> map;
		for(int i = 0; i < t.length(); i++)
		{
			if(map.find(t[i]) == map.end())
				map[t[i]] = 1;
			else
				map[t[i]]++;
		}			

		int left = 0;
		int right = 0;
		int min_len = s.length()+1;
		int min_left = -1;
		int count = 0;
		for(right = 0; right < s.length(); right++)
		{
			if(map.find(s[right]) == map.end())
				continue;
			map[s[right]]--;
			if(map[s[right]] >= 0)
			{
				count++;
				while(count == t.length())
				{
					if(min_len > right-left+1)
					{
						min_left = left;
						min_len  =right-left+1;
					}
					if(map.find(s[left]) != map.end())
					{
						map[s[left]]++;
						if(map[s[left]] > 0)
							count--;
					}		
					left++;
				}
			}		
		}			
		if(min_left == -1)
			return "";
		else
			return s.substr(min_left, min_len);	
	}

};

/*
  这题没有想出来。
  用一个哈希表存储字符及其出现次数。
  当遇到一个在哈希表中的字符，对应出现次数减一。
  如果减到0了，就需要移动滑动窗口时跳过。
*/

/*
	用双端队列维护可能的最大值，队列中元素依次递减。
	遇到一个新数，从队列尾开始观察是否有数比它小，如果是，就弹出。
	所有元素入队出队各一次，时间复杂度为O(n).
*/

class Solution 
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
    	vector<int> r;
    	deque<int> queue;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(queue.size() > 0 && queue.front() <= i-k)
    			queue.pop_front();
    		while(queue.size() > 0 && nums[queue.back()] < nums[i])
    			queue.pop_back();
    		queue.push_back(i);
    		if(i >= k-1)
    			r.push_back(nums[queue.front()]);
    	}
    	return r;
    }
};

