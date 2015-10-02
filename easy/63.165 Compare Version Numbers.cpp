/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

    	int compareVersion(string version1, string version2) 
	{
		int p1 = 0;
		int p2 = 0;
		int e1 = 0;
		int e2 = 0;
		while(p1 < version1.size() && p2 < version2.size())
		{
			while(e1 < version1.size() && version1[e1] != '.')
				e1++;
			int n1 = stoi(version1.substr(p1, e1-p1), NULL);

			while(e2 < version2.size() && version2[e2] != '.')
                                e2++;
                        int n2 = stoi(version2.substr(p2, e2-p2), NULL);			

			if(n1 < n2)
				return -1;
			else if(n1 > n2)
				return 1;
			e1++;
			e2++;
			p1 = e1;
			p2 = e2;		
			
		}
		while(e1 < version1.size())
		{
			while(e1 < version1.size() && version1[e1] != '.')
                                e1++;
                        int n1 = stoi(version1.substr(p1, e1-p1), NULL);
			if(n1 != 0)
				return 1;
			e1++;
			p1 = e1;
		}
	
		while(e2 < version2.size())
		{
			while(e2 < version2.size() && version2[e2] != '.')
                                e2++;
                        int n2 = stoi(version2.substr(p2, e2-p2), NULL);
			if(n2 != 0)
				return -1;
			e2++;
			p2 = e2;
		}
		return 0;
    	}

};

int main()
{
	Solution s;
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		cout << s.compareVersion(s1, s2) << endl;
	}		
	return 0;
}

/*
  模拟。
*/
