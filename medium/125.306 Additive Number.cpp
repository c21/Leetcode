/*
Additive number is a positive integer whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string represents an integer, write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/

#include <iostream>
#include <string>
using namespace std;

class Solution 
{
    public:
    bool isAdditiveNumber(string num) 
    {
        long long max_val = 1;
	max_val = (max_val << 31);
        if(num.size() < 3)
            return false;
        for(int i = 0; i <= num.length()-3; i++)
        {
            for(int j = i+1; j <= num.length()-2; j++)
            {
/*		cout << "now here\n";
		cout << "i: " << i << ", j: " << j << endl;
  */
              if((i > 0 && num[0] == '0') || (j-i > 1 && num[i+1] == '0'))
                    continue;

                long long n1 = stoll(num.substr(0, i+1));
                long long n2 = stoll(num.substr(i+1, j-i));
//		cout << "n1: " << n1 << " n2: " << n2 << endl;
    /*            if(n1+n2 >= max_val)
                    continue;
*/
//		cout << "here\n";
                long long n3 = n1+n2;
                int k = j+1;
                int flag = 1;
                while(k < num.length())
                {
                    string s = to_string(n3);
 //                   cout << "s: " << s << endl;	
		    if(s.length() > num.length()-k)
                    {
                        flag = 0;
                        break;
                    }
                    string s2 = num.substr(k, s.length());
//		    cout << "s2: " << s2 << endl;
                    if(s != s2)
                    {
                        flag = 0;
                        break;
                    }
                    k += s.length();
                    if(k >= num.length())
                        break;
                    long long new_n3 = n2+n3;
/*                    if(new_n3 >= max_val)
                    {
                        flag = 0;
                        break;
                    }
  */                  n2 = n3;
                    n3 = new_n3;
                }
                if(flag)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
	Solution s;
	string s1;
	while(cin >> s1)
	{
		cout << s.isAdditiveNumber(s1) << endl; 
	}
	return 0;
}

/*
  枚举第一个和第二个数，其他数验证是否正确，注意string转为long long为stoll.
*/
