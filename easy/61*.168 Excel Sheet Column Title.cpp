/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{

	public:

    	string convertToTitle(int n) 
	{
		string s = "";
		int k = n;
		while(k > 0)
		{
			int r = k % 26;
			if(r == 0)
			{
				s += 'Z';
				k = k - 1;
			}
			else
			{
				s += (r-1)+'A';
			}
			k /= 26;
		}	
		reverse(s.begin(), s.end());	
		return s;
    	}

};

int main()
{
	Solution s;
	int n;
	while(cin >> n)
	{
		cout << s.convertToTitle(n) << endl;
	}	
	return 0;
}

/*
  这题没做出来，遇到26整数倍时，需要得到Z，然后减去1.
*/
