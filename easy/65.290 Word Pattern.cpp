/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution 
{
    public:
    bool wordPattern(string pattern, string str) 
    {
    	unordered_map<char, string> map1;
    	unordered_map<string, char> map2;
      	int i = 0;
        stringstream scin(str);
        string s;
        while(scin >> s)
        {
	        if(i >= pattern.length())
		        return false;
	        if(map1.find(pattern[i]) == map1.end())
        	{
        		if(map2.find(s) != map2.end())
        			return false;
        		else
        		{
        			map1[pattern[i]] = s;
        			map2[s] = pattern[i];
        		}
        	}
        	else
        	{
        		if(s != map1[pattern[i]])
        			return false;
        	}
        	i++;
        }  
        if(i < pattern.length())
        	return false;
        else
            return true;
    }
};


/*
  模拟
*/
