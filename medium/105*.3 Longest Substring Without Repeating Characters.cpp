/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*		int flag[30];
		for(int i = 0; i < 26; i++)
			flag[i] = -1;
*/
		map<char, int> my_map = map<char,int>();
		int begin = 0;
		int max_len = 0;
		for(int i = 0; i < s.length(); i++)
		{
//			printf("b: place: %d\n", flag[1]);
//			int place = s[i]-'a';
//			if(flag[place] >= begin)
			if(my_map.find(s[i]) != my_map.end() && my_map[s[i]] >= begin)
			{
				int now_len = i-begin;
				if(now_len > max_len)
				{
//					printf("begin: %d, i: %d\n", begin, i);
					max_len = now_len;
			//		begin = flag[place] + 1;
			//		flag[place] = i;			
//					printf("new begin: %d\n", begin);
						
				}
				begin = my_map[s[i]] + 1;
                                my_map[s[i]] = i;	
			}
			else
			{
				my_map[s[i]] = i;
			}
		}				
       		
//		max_len = max(max_len, s.length()-begin);
		if(max_len < s.length()-begin)
			max_len = s.length()-begin;
		return max_len;
    }
};
