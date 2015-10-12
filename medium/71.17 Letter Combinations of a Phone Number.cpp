/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{

	public:

	string num[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	vector<string> letterCombinations(string digits) 
	{
		vector<int> flag = vector<int>();

		vector<string> result = vector<string>();
		
		if(digits.length() == 0)
			return result;
		else
		{
			for(int i = 0; i < digits.length(); i++)
				flag.push_back(-1);
			gen_comb(digits, flag, result, 0);
		}					
	}

	void gen_comb(string& digits, vector<int>& flag, vector<string>& result, int k)
	{
		if(k == digits.length())
		{
			string r = "";
			for(int i = 0; i < flag.size(); i++)
			{
				if(digits[i] >= '2' && digits[i] <= '9')
					r += num[digits[i]-'0'][flag[i]];
			}	
			result.push_back(r);
		}
		else
		{
			if(digits[k] == '0' || digits[k] == '1' || digits[k] == '*' || digits[k] == '#')
			{
				gen_comb(digits, flag, result, k+1);	
			}
			else if( (digits[k] >= '2' && digits[k] <= '6') || (digits[k] == '8'))
			{
				for(int i = 0; i <= 2; i++)
				{
					flag[k] = i;
					gen_comb(digits, flag, result, k+1);
				}		
			}
			else if(digits[k] == '9' || digits[k] == '7')
			{
				for(int i = 0; i <= 3; i++)
                                {
                                        flag[k] = i;
                                        gen_comb(digits, flag, result, k+1);
                                }
			}
		}	
	}

};

int main()
{
	Solution s;
	string str;
	while(cin >> str)
	{
		vector<string> r = s.letterCombinations(str);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << endl;
	}
	return 0;	
}

/*
  枚举
*/
