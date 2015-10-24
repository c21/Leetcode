/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution 
{

	public:
	
	string numberToWords(int num) 
	{
		
		if(num >= pow(10, 9))
		{
			int t = pow(10, 9);	
			int p = num / t;
			int r = num % t;
			string s1 = "", s2 = "";
			s1 = numberToWords(p);	
			if(r != 0)
				s2 = " " + numberToWords(r);
			return s1 + " Billion" + s2;	
		}	
		else if(num >= pow(10, 6))
		{
			int t = pow(10, 6);     
			int p = num / t;
			int r = num % t;
			string s1 = "", s2 = "";
			s1 = numberToWords(p);      
			if(r != 0)
			    s2 = " " + numberToWords(r);
			return s1 + " Million" + s2;	
		}	
		else if(num >= pow(10, 3))
		{
			int t = pow(10, 3);
			int p = num / t;
			int r = num % t;
			string s1 = "", s2 = "";
			s1 = numberToWords(p);
			if(r != 0)
			    s2 = " " + numberToWords(r);
			return s1 + " Thousand" + s2;
		}
		else if(num >= pow(10, 2))
		{
			int t = pow(10, 2);
		   	int p = num / t;
			int r = num % t;
			string s1 = "", s2 = "";

			s1 = numberToWords(p);
			if(r != 0)
				s2 = " " + numberToWords(r);
			return s1 + " Hundred" + s2;	
		}
		else if(num >= pow(10, 1))
		{
			int t = pow(10, 1);
			int p = num / t;
			int r = num % t;
			string s1 = "", s2 = "";
			if(num == 10)
          return "Ten";
      else if(num >= 11 && num <= 19)
      {
        switch(num)
        {
          case 11: s1 = "Eleven"; break;
          case 12: s1 = "Twelve"; break;
          case 13: s1 = "Thirteen"; break;
          case 14: s1 = "Fourteen"; break;
          case 15: s1 = "Fifteen"; break;
          case 16: s1 = "Sixteen"; break;
          case 17: s1 = "Seventeen"; break;
          case 18: s1 = "Eighteen"; break;
          case 19: s1 = "Nineteen"; break;
        }
        return s1;
      }
			if(r != 0)
				s2 = " " + numberToWords(r);
			switch(p)
			{
				case 1: s1 = "Ten"; break;
				case 2: s1 = "Twenty"; break;
				case 3: s1 = "Thirty"; break;
				case 4: s1 = "Forty"; break;
				case 5: s1 = "Fifty"; break;
				case 6: s1 = "Sixty"; break;
				case 7: s1 = "Seventy"; break;
				case 8: s1 = "Eighty"; break;
				case 9: s1 = "Ninety"; break;	
			}
                        return s1 + s2;	
		}	
		else
		{
		    	string s1;
			switch(num)
			{
				case 0: s1 = "Zero"; break;
				case 1: s1 = "One"; break;
				case 2: s1 = "Two"; break;
				case 3: s1 = "Three"; break;
				case 4: s1 = "Four"; break;
				case 5: s1 = "Five"; break;
				case 6: s1 = "Six"; break;
				case 7: s1 = "Seven"; break;
				case 8: s1 = "Eight"; break;
				case 9: s1 = "Nine"; break;
			}
			return s1;	
		}	
	}

};

/*
  根据该数>=10^9, 10^6, 10^3, 100, 10来分别划分考虑。 
*/
