/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution 
{

	public:

    	string intToRoman(int num) 
	{
		string table[12] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		int result = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string s = "";
		for(int i = 0; i < 12; i++)
		{
			while(num >= table[i])
			{
				s += table[i];
				num -= result[i];
			}
		}		
        	return s;

    	}

};

/*
  这题是要知道罗马数字的表示方法是1,4,5,9,10. 即1000, 900, 500, 400, 100, 90 ...
*/
