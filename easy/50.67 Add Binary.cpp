/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{

	public:

    	string addBinary(string a, string b) 
	{
		int p1 = a.length()-1;
		int p2 = b.length()-1;
		string ans = "";
		int carry = 0;
		while(p1 >= 0 && p2 >= 0)		
		{
			int r = a[p1]-'0' + b[p2]-'0'+carry;
			if(r >= 2)
			{
				r = r-2;
				carry = 1;
			}	
			else
			{
				carry = 0;
			}
			ans += (r+'0');
//			cout << "ans: " << ans<< endl;	
			p1--;
			p2--;
		}
//		cout << "p1: " << p1 << endl;
		while(p1 >= 0)
		{
			int r = a[p1]-'0'+carry;
			if(r >= 2)
                        {
                                r = r-2;
                                carry = 1;
                        }
                        else
                        {
                                carry = 0;
                        }
                        ans += (r+'0');
//			cout << "ans: " << ans << endl;
			p1--;
		}
		while(p2 >= 0)
                {
                        int r = b[p2]-'0'+carry;
                        if(r >= 2)
                        {
                                r = r-2;
                                carry = 1;
                        }
                        else
                        {
                                carry = 0;
                        }
                        ans += (r+'0');
//			cout << "ans: " << ans << endl;
                        p2--;
                }

		if(carry == 1)
			ans += '1';
//		cout << "ans: " << ans << endl;
		reverse(ans.begin(), ans.end());
    		return ans;
	}

};


int main()
{
	Solution s;
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		cout << s.addBinary(s1, s2) << endl;
	}
	return 0;
}

/*
  模拟
*/
