/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window’s size.
Remove redundant elements and the queue should store only elements that need to be considered.
*/

struct node
{
	int val;
	int idx;
	bool operator < (const node& a) const
	{
		return val < a.val;
	}		
};


class Solution 
{

	public:

	vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{
		vector<int> result = vector<int>();
		if(nums.size() == 0)
			return result;

		priority_queue<node> my_queue = priority_queue<node>();
		for(int i = 0; i <= k-1; i++)
		{
			node s;
			s.val = nums[i];
			s.idx = i;
			my_queue.push(s);
		}			
		result.push_back(my_queue.front().val);
		for(int i = k; i <= nums.size(); i++)
		{
			while(my_queue.size() > 0 && my_queue.front().idx <= i-k)
				my_queue.pop();
			node s;
			s.val = nums[i];
			s.idx = i;
			my_queue.push(s);
			result.push_back(my_queue.front().val);	
		}		
		return result;	
	}

};

/*
  这里是O(nlogn)的方法，用优先队列来存放元素。
  O(n)的方法没有想出来，是用双端队列存放元素，可以从后往前删除那些比当前元素小的元素。
*/
