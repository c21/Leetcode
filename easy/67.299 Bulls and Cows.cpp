/*
You are playing the following Bulls and Cows game with your friend: You write a 4-digit secret number and ask your friend to guess it. Each time your friend guesses a number, you give a hint. The hint tells your friend how many digits are in the correct positions (called "bulls") and how many digits are in the wrong positions (called "cows"). Your friend will use those hints to find out the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

class Solution 
{
    public:
    string getHint(string secret, string guess) 
    {
    	int c1 = 0;
    	int c2 = 0;
    	unordered_map<char, int> map1;
    	unordered_map<char, int> map2;
    	for(int i = 0; i < secret.length(); i++)
    	{
    		if(secret[i] == guess[i])
    		{
    			c1++;
    		}
    		else
    		{
    			if(map1.find(secret[i]) == map1.end())
    				map1[secret[i]] = 1;
    			else
    				map1[secret[i]]++;
    
    			if(map2.find(guess[i]) == map2.end())
    				map2[guess[i]] = 1;
    			else
    				map2[guess[i]]++;
    			
    			if(map1.find(guess[i]) != map1.end())
    			{
    				if(map1[guess[i]] > 0)
    				{
    					map1[guess[i]]--;
    					map2[guess[i]]--;
    					c2++;	
    				}
    			}
    			if(map2.find(secret[i]) != map2.end())
    			{
    				if(map2[secret[i]] > 0)
    				{
    					map1[secret[i]]--;
    					map2[secret[i]]--;
    					c2++;	
    				}
    			}
    
    		}
    	}
    	return to_string(c1)+"A"+to_string(c2)+"B";
    }
};


/*
  使用两个map记录字符串中未匹配的字符。
*/
