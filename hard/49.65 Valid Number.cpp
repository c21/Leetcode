/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	bool isNumber(string s) 
	{
		if(s.length() == 0)
			return false;
		// get rid of the space
		int i;
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		for(i = 0; i < s.length(); i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				int j = i;
				while(j < s.length() && (s[j] >= '0' && s[j] <= '9'))
				{
					j++;
				}
				if(j == s.length())
					return true;
				if(s[j] == 'e')
				{
					count3++;
					if(count3 > 1)
						return false;
					int k = j+1;
					int flag = 0;
					if(k < s.length() && (s[k] == '+' || s[k] == '-'))
					{
						count2++;
						if(count2 > 2)
							return false;
						k++;
						flag = 1;
					}
					while(k < s.length() && (s[k] >= '0' && s[k] <= '9'))
						k++;
					if(k == j+1+flag)
						return false;
					else if(k == s.length())
						return true;
					else if(s[k] == ' ')
					{
						for(int a = k+1; a < s.length(); a++)	
						{
							if(s[a] != ' ')
								return false;
						}	
						return true;
					}	
					else
						return false;			
				}
				else if(s[j] == '.')
				{
					count1++;
					if(count1 > 1)
						return false;
					int k = j+1;
          while(k < s.length() && (s[k] >= '0' && s[k] <= '9'))
                  k++;
					if(k == j+1 && k == s.length())
					{
						return true;
					}	
					else if(k == s.length())
            return true;
					else if(s[k] == ' ')
          {
                  for(int a = k+1; a < s.length(); a++)
                  {
                          if(s[a] != ' ')
                                  return false;
                  }
                  return true;
          }
          else if(s[k] == 'e')
					{
						count3++;
						if(count3 > 1)
							return false;
						int k2 = k+1;
            int flag = 0;
						if(k2 < s.length() && (s[k2] == '+' || s[k2] == '-'))
          	{
                  	count2++;
                 	 	if(count2 > 2)
                          	return false;
                  	k2++;
                  	flag = 1;
          	}
          	while(k2 < s.length() && (s[k2] >= '0' && s[k2] <= '9'))
                  	k2++;
          	if(k2 == k+1 + flag)
                  	return false;
          	else if(k2 == s.length())
                  	return true;
          	else if(s[k2] == ' ')
          	{
                  	for(int a = k2+1; a < s.length(); a++)
                  	{
                          	if(s[a] != ' ')
                                  	return false;
                 	 	}
                  	return true;
          	}
          	else
                  	return false;	
					}
					else
            return false;
				}
				else if(s[j] == ' ')
				{
					for(int k = j+1; k < s.length(); k++)
					{
						if(s[k] != ' ')
							return false;
					}
					return true;
				}
				else
					return false;
			}
			else if(s[i] == '.')
			{
				count1++;
				if(i+1 < s.length() && ((s[i+1] >= '0' && s[i+1] <= '9')))
				{
				//	cout << "here\n";
            continue;
				}
        else
            return false;
			}
			else if(s[i] == '-' || s[i] == '+')
      {
				count2++;	
      	if(i+1 < s.length() && (s[i+1] == '.' || (s[i+1] >= '0' && s[i+1] <= '9')))
              	continue;
      	else
              	return false;
      }
/*
    	else if(s[i] == 'e')
    	{
            	if(i+1 < s.length())
            	{
                    	int j = i+1;
                    	if(!(s[j] == '-' || (s[j] >= '0' && s[j] <= '9')))
                            	return false;
            	}
            	else
                    	return false;
    	}
*/		else if(s[i] != ' ')
				return false;	
		}
		return false;					
	}


};


int main()
{
	Solution s;
	string s1;
	while(getline(cin, s1))
	{
		cout << s.isNumber(s1) << endl;
	}		
	return false;
}

/*
  模拟
*/
