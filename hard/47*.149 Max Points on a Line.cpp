/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

class Solution 
{

	public:

	int maxPoints(vector<Point>& points) 
	{
		int max_num = 0;
		for(int i = 0; i < points.size(); i++)
		{
			unordered_map<double, int> map;
			int inf_count = 0;
			int this_max = 0;
			int same_count = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j != i)
				{
					if(points[j].x == points[i].x && points[j].y == points[i].y)
					{
						same_count++;
					}
					else if(points[j].x == points[i].x)
					{
						inf_count++;
						if(inf_count > this_max)
							this_max = inf_count;
					}
					else
					{
						double k = (points[j].y-points[i].y)*1.0/(points[j].x-points[i].x);
						if(map.find(k) == map.end())
							map[k] = 1;
						else
							map[k]++;
						if(map[k] > this_max)
							this_max = map[k];
					}	
				}
			}		
			if(max_num < this_max+same_count)
				max_num = this_max+same_count; 	
		}		
		return max_num;
	}

};

/*
  这题没有想出来。
  答案方法是对于每个点(x1, y1), 如果(x2, y2)和(x1, y1)在一条直线上，(x3, y3)和(x1, y1)也在这一条直线上
  那么(x2, y2)和(x3, y3)也在这一条直线上。
  也就是说：如果(y2-y1)/(x2-x1) == (y3-y1)/(x3-x1) == k，那么(y3-y2)/(x3-x2) == k.
  对于每个点，分别统计每一种斜率上的点数，最大数目即为与该点在同一条直线上的最多点数目。
  
*/
