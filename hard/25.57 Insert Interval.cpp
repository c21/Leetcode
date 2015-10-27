/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**

 * Definition for an interval.

 * struct Interval {

 *     int start;

 *     int end;

 *     Interval() : start(0), end(0) {}

 *     Interval(int s, int e) : start(s), end(e) {}

 * };

 */

class Solution 
{

	public:

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
	{
		vector<Interval> result = vector<Interval>();
		if(intervals.size() == 0)
		{
			result.push_back(newInterval);
			return result;
		}	
		
		if(newInterval.end < intervals[0].start)
		{
			result.push_back(newInterval);
			for(int i = 0; i < intervals.size(); i++)
				result.push_back(intervals[i]);
			return result;
		}	
		else if(newInterval.end == intervals[0].start)
		{
			result.push_back(Interval(newInterval.start, intervals[0].end));
			for(int i = 1; i < intervals.size(); i++)
                                result.push_back(intervals[i]);
                        return result;
		}

		for(int i = 0; i < intervals.size(); i++)
		{
			if(newInterval.start > intervals[i].end)	
			{
				result.push_back(intervals[i]);
			}
			// find the first overlapping interval
			else
			{
				int begin = min(newInterval.start, intervals[i].start);
				// find the last overlapping interval
				int j = i;
				while(j < intervals.size() && newInterval.end >= intervals[j].start)
					j++;
				int end = max(newInterval.end, intervals[j-1].end);
				result.push_back(Interval(begin, end));
				for(int k = j; k < intervals.size(); k++)
					result.push_back(intervals[k]);
				return result;
			}
		}	

		result.push_back(newInterval);		
		return result;
	}

};

/*
  模拟。
  考虑好边界的情况：
  1.intervals.size() == 0
  2.newInterval.end < intervals[0].start
  3.newInterval.end == intervals[0].start
  4.newInterval.start > intervals[n].end
*/
