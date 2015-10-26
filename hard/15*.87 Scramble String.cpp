/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() == 0 )
            return true;
        
        vector<vector<vector<bool> > > record = vector<vector<vector<bool> > >();
        for(int i = 0; i < s1.length(); i++)
        {
            record.push_back(vector<vector<bool> >());
            for(int j = 0; j < s1.length(); j++)
            {
                record[i].push_back(vector<bool>());
                record[i][j].push_back(true);
                for(int k = 1; k <= s1.length(); k++)
                {
                    if(k == 1 && s1[i] == s2[j])
                        record[i][j].push_back(true);
                    else
                        record[i][j].push_back(false);
                }
            }
        }
        
        for(int len = 2; len <= s1.length(); len++)
        {
            for(int i = 0; i+len-1 <= s1.length()-1; i++)
            {
                for(int j = 0; j+len-1 <= s1.length()-1; j++)
                {
                    for(int k = 1; k <= len-1; k++)
                    {
                        record[i][j][len] = record[i][j][len] || 
                            ( (record[i][j][k] && record[i+k][j+k][len-k]) || 
                                (record[i][j+len-k][k] && record[i+k][j][len-k]));
                    }
                }   
            }
        }
        return record[0][0][s1.length()];
    }
};

/*
  DP.
  f(i,j,k): if s2[j-(j+k-1)] is scamble string of s1[i-(i+k-1)] or not.
  f(i, j, k) = U ( (f(i,j,x) && f(i+x,j+x,k-x)) U (f(i,j+k-x,x) && f(i+x,j,k-x)) ) for  1 <= x <= k-1. 
*/
