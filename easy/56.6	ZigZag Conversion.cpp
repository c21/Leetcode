/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

    	string convert(string s, int numRows) 
	{
		if(numRows == 1 || s == "" || numRows >= s.length())
			return s;
		string r = "";
		for(int i = 1; i <= numRows; i++)
		{
			r += s[i-1];
			int p1 = 2*(numRows-i);
			int p2 = 2*(i-1);

			if(i == 1)
			{
				for(int j = i-1+p1; j < s.length(); j = j+p1)
				{
					r += s[j];	
				}
			}
			else if(i == numRows)
			{
				for(int j = i-1+p2; j < s.length(); j = j+p2)
                                {
                                        r += s[j];
                                }
			}			
			else
			{
				int c = 1;
				for(int j = i-1+p1; j < s.length();)
                                {
                                        r += s[j];
					if(c == 1)
					{
						j = j + p2;
						c = 2;
					}
					else if(c == 2)
					{
						j = j + p1;
						c = 1;
					}
                                }
			}
		}	

		return r;	
    	}

};

int main()
{
	Solution s;
	string str;
	int n;
	while(cin >> str >> n)
	{
		cout << s.convert(str, n) << endl;
	}	
	return 0;
	
}

/*
  模拟
*/
