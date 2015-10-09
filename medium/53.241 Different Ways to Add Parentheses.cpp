/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

#include <vector>
#include <map>
#include <utility>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution 
{

	public:



	vector<int> diffWaysToCompute(string input) 
	{
		// get all the numbers and operators
		vector<char> op = vector<char>();
		vector<int> num = vector<int>();
		vector<int> result = vector<int>();
		map<pair<int,int>, vector<int> > my_map = map<pair<int,int>, vector<int> >();
		for(int i = 0; i < input.length(); i++)
		{
			int j = i;
			while(j < input.length() && input[j] >= '0' && input[j] <= '9')
				j++;
			int n = atoi(input.substr(i, j-i).c_str());
			num.push_back(n);
			if(j < input.length())
				op.push_back(input[j]);
			i = j;			
		}	
	

		// get result
		if(num.size() == 0)
			return result;
		else
		{
			result = gen_result(num, op, my_map, 0, num.size()-1);			
			return result;
		}
	}

	vector<int> gen_result(vector<int>& num, vector<char>& op, map<pair<int,int>, vector<int> >& my_map, int begin, int end)
	{
		pair<int,int> p(begin, end);
		if(my_map.find(p) != my_map.end())
		{
			return my_map[p];	
		}	
		else
		{
			vector<int> r = vector<int>();
			if(begin == end)
			{
				r.push_back(num[begin]);
				my_map[p] = r;
				return r;
			}	
			else
			{
				for(int i = begin; i <= end-1; i++)
				{
					vector<int> r1 = gen_result(num, op, my_map, begin, i);
					vector<int> r2 = gen_result(num, op, my_map, i+1, end);

					
					for(int j = 0; j < r1.size(); j++)
					{
						for(int k = 0; k < r2.size(); k++)
						{
							if(op[i] == '+')
								r.push_back(r1[j]+r2[k]);
							else if(op[i] == '-')
								r.push_back(r1[j]-r2[k]);	
							else if(op[i] == '*')
								r.push_back(r1[j]*r2[k]);
						}
					}
							
				}
				my_map[p] = r;
				return r;	
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
		vector<int> r = s.diffWaysToCompute(str);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << endl;
	}	
	return 0;	
}

/*
  依次枚举所有计算符号
*/  
