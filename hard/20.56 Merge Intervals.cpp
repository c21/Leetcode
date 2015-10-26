/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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

	vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> r = vector<Interval>();
		if(intervals.size() == 0)
			return r;
		vector<pair<int,int> > array = vector<pair<int,int> >();
		for(int i = 0; i < intervals.size(); i++)
		{
			array.push_back(make_pair(intervals[i].start, intervals[i].end));
		}					
		sort(array.begin(), array.end());

		for(int i = 0; i < array.size(); i++)
		{
			int begin = array[i].first;
			int end =  array[i].second;
			int j = i+1;
			while(j < array.size() && array[j].first <= end)	
			{
				end = max(end, array[j].second);
				j++;
			}
			r.push_back(Interval(begin, end));
			i = j-1;
		}
		return r;	
	}

};

/*
  先排序，然后从头开始扫描，每次确定可以合并的间隔。
*/
