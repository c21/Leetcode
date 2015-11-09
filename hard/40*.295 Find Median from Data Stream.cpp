/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

class MedianFinder 
{

	priority_queue<int> big, small;

	public:
	// Adds a number into the data structure.
	void addNum(int num) 
	{
		small.push(num);
		int top = small.top();
		big.push(-top);
		small.pop();
		if(small.size() < big.size())
		{
			small.push(-big.top());
			big.pop();
		}			
	}

	// Returns the median of current data stream
	double findMedian() 
	{
		return small.size() > large.size() ? small.top() : 0.5*(small.top()-big.top());	
	}

};



// Your MedianFinder object will be instantiated and called as such:

// MedianFinder mf;

// mf.addNum(1);

// mf.findMedian();

/*
  	这道题没有想出来。
  	用的是两个堆，最大堆来存放前半段数，最小堆存放后半段数。
 	最大堆的数的个数==最小堆的数的个数(或+1)
*/


struct t1
{
	int v;
	bool operator < (const struct t1& x) const
	{
		return v < x.v;
	}
	t1(int a)
	{
		v = a;
	}
};

struct t2
{
	int v;
	bool operator < (const struct t2& x) const
	{
		return v > x.v;
	}
	t2(int a)
	{
		v = a;
	}
};

class MedianFinder 
{
	private:
    priority_queue<t1> max_heap;
    priority_queue<t2> min_heap;
	
    public:
    // Adds a number into the data structure.
    void addNum(int num) 
    {
    	if(max_heap.size() == 0)
    	{
    		max_heap.push(t1(num));
    	}
    	else if(max_heap.size() == min_heap.size())
    	{
    		t1 p1 = max_heap.top();
    		if(p1.v >= num)
    			max_heap.push(t1(num));
    		else
    		{
    			min_heap.push(t2(num));
    			t2 p2 = min_heap.top();
    			min_heap.pop();
    			max_heap.push(t1(p2.v));
    		}
    	}
    	else
    	{
    		t1 p1 = max_heap.top();
    		if(p1.v >= num)
    		{
    			max_heap.pop();
    			max_heap.push(t1(num));
    			min_heap.push(t2(p1.v));
    		}
    		else
    		{
    			min_heap.push(t2(num));
    		}
    	}
     }

    // Returns the median of current data stream
    double findMedian() 
    {
    	if(max_heap.size() == 0)
    		return 0;
    	else if(max_heap.size() > min_heap.size())
    		return max_heap.top().v;
    	else
    		return (max_heap.top().v+min_heap.top().v)*0.5;
    }

	
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


