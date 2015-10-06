/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution 
{

	public:

    	bool searchMatrix(vector<vector<int> >& matrix, int target) 
	{
       		if(matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int p = search_first(matrix, target, 0, matrix.size()-1);

		if(p == -1)
			return false;
		else
			return search_second(matrix[p], target, 0, matrix[p].size()-1); 

    	}

	// search the first dimension
	int search_first(vector<vector<int> >& array, int target, int begin, int end)
	{
		if(begin == end)
		{
			if(array[begin][0] > target)
				return -1;
			else
				return begin;
		}
		else if(begin+1 == end)
		{
			if(array[begin][0] > target)
				return -1;
			else if(array[end][0] > target)
				return begin;
			else
				return end;
		}	
		else if(begin < end)
		{
			int mid = (begin+end)/2;
			if(array[mid][0] > target)
			{
				return search_first(array, target, begin, mid-1);
			}	
			else
			{
				return search_first(array, target, mid, end);
			}
		}
	}

	// search the second dimension
	bool search_second(vector<int>& array, int target, int begin, int end)
        {
		if(begin <= end)
		{
			int mid = (begin+end)/2;
			if(array[mid] == target)
				return true;
			else if(array[mid] < target)
				return search_second(array, target, mid+1, end);
			else
				return search_second(array, target, begin, mid-1);
		}
		return false;
	}
};

/*
  先折半搜索该数字所在的第一维数组，再折半搜索该数字在该数组的位置。
*/
