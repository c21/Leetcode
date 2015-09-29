/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;


class Solution 
{

	public:

	vector<int> plusOne(vector<int>& digits) 
	{
		// store the new number reversely
		// then reverse the new number
		vector<int> result = vector<int>();	
		
		int carry = 1;
		// calculate from the least significant digit
		for(int i = digits.size()-1; i >= 0; i--)
		{
			if(digits[i]+carry >= 10)
			{
				result.push_back(digits[i]+carry-10);
				carry = 1;
			}
			else
			{
				result.push_back(digits[i]+carry);
                                carry = 0;
			}
		}

		if(carry == 1)
			result.push_back(1);

		reverse(result.begin(), result.end());			
    	
		return result;
	}

};

int main()
{
	int n;
	vector<int> r = vector<int>();
	while(scanf("%d", &n) == 1)
		r.push_back(n);

	Solution s;
	vector<int> r2 = s.plusOne(r);

	for(int i = 0; i < r2.size(); i++)
		printf("%d ", r2[i]);
	printf("\n");		
}

/*
  模拟
*/
