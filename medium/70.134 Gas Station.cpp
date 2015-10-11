/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution 
{

	public:

  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int begin = 0;
		int sum = 0;
		for(int i = 0; i < gas.size(); i++)
		{
			if(sum < 0)
			{
				begin = i;
				sum = 0;
			}		
			sum += gas[i]-cost[i];
		}		
		if(begin == 0)
		{
			if(sum >= 0)
				return begin;
			else
				return -1;
		}
		else
		{
			for(int i = 0; i <= begin-1; i++)
			{
				sum += gas[i]-cost[i];
			}	
			if(sum >= 0)
				return begin;
			else
				return -1;
		}	
	}

};

/*
  从0点开始出发，如果到达一个地方i没有油了，那么从1至i-1都无法到达i. 将i设为新的假设起点出发。
  回到0点后，再一直到达假设起点，如果能到达，则成功，否则失败。时间复杂度为O(n).
*/
