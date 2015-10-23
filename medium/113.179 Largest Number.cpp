/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

bool cmp(string a, string b)
{
	string s1 = a+b;
	string s2 = b+a;
	if(s1 < s2)
		return true;
	else
		return false;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) 
	{

		string s = "";
		if(nums.size() == 0)	
			return s;
		else
		{
			vector<string> sa = vector<string>();
			for(int i = 0; i < nums.size(); i++)
				sa.push_back(to_string(nums[i]));
			sort(sa.begin(), sa.end() , cmp);
			for(int i = sa.size()-1; i >= 0; i--)
			{
				s += sa[i];
			}	

			int i = 0;
			while(i < sa.size() && s[i] == '0')
			{
				i++;
			}
			if(i == sa.size())
				return "0";
			else if(i == 0)
				return s;
			else
				return s.substr(i, s.length()-i);	
		}
	}
};

/*
  对于两个字符串a, b进行排序，如果a+b < b+a, 那么a < b, 否则a > b. 
*/  
