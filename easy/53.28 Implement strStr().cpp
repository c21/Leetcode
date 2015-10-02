/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution 
{

	public:

    	int strStr(string haystack, string needle) 
	{
		if( (haystack.length() < needle.length()))
			return -1;
		
		if(haystack == "" && needle == "")
			return 0;
		for(int i = 0; i <= haystack.length()-needle.length(); i++)
		{
			int j;
			for(j = 0; j < needle.length(); j++)
			{
				if(haystack[i+j] != needle[j])
					break;
			}
			if(j == needle.length())
				return i;
		}		
		return -1;
        

    	}

};

/*
  模拟
*/
