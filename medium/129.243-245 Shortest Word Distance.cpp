/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding", word2 = "practice", return 3. Given word1 = "makes", word2 = "coding", return 1.
*/

class Solution 
{
    public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        int min_dist = words.size();
        int p1 = -1, p2 = -1;
        for(int i = 0; i < words.size(); i++)
        {
            if(word1 == words[i])
                p1 = i;
            else if(word2 == words[i])
                p2 = i;
            if(p1 != -1 && p2 != -1)
                min_dist = min(min_dist, abs(p1-p2));
        }    
        return min_dist;
    }
};

/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,

Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding”, word2 = "practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

Note
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
*/

class solution
{
    private:
    unordered_map<string, vector<int> > map;
    
    public:
    solution(vector<string>& words)
    {
        for(int i = 0; i < words.size(); i++)
        {
            if(map.find(words[i]) == map.end())
                map[words[i]] = vector<int>();
            map[words[i]].push_back(i);
        }
    }
    
    int shortestDistance(string word1, string word2) 
    {
        vector<int>& v1 = map[word1];
        vector<int>& v2 = map[word2];
        int min_dist = abs(v1[0]-v2[0]);
        int p1 = 0, p2 = 0;
        while(p1 < v1.size() && p2 < v2.size())
        {
            if(v1[p1] > v2[p2])
                p2++;
            else
                p1++;
            min_dist = min(min_dist, abs(v1[p1]-v2[p2]));
        }        
        return min_dist;
    }
};

/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,

Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "makes", word2 = "coding", return 1. Given word1 = "makes", word2 = "makes", return 3.

Note:

You may assume word1 and word2 are both in the list.
*/

class Solution 
{
    public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) 
    {
        int min_dist = words.size();
        int p1 = -1, p2 = -1;
        for(int i = 0; i < words.size(); i++)
        {
            if(word1 == word2)
            {
                if(words[i] == word1)
                {
                    if(p1 >= p2)
                        p2++;
                    else
                        p1++;
                }
            }
            else
            {
                if(words[i] == word1)
                    p1++;
                else if(words[i] == word2)
                    p2++;
            }
            if(p1 != -1 && p2 != -1)
                min_dist = min(min_dist, abs(p1-p2));
        }    
        return min_dist;
    }
};
