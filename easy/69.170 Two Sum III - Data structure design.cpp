/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add(input) – Add the number input to an internal data structure.

find(value) – Find if there exists any pair of numbers which sum is equal to the value.

For example, add(1); add(3); add(5); find(4)->true; find(7)->false


*/

/*
add – O(1) runtime, find – O(n) runtime, O(n) space
*/
class solution
{
    private:
    unordered_set<int> set;
    
    void add(int n) 
    {
        set.insert(n);
    }
    
    bool find(int n)
    {
        for(unordered_set<int>::iterator p = set.begin(); p != set.end(); p++)
        {
            if(set.find(n-*p) != set.end())
                return true;
        }
        return false;
    }
};

/*
add – O(n) runtime, find – O(1) runtime, O(n2) space
*/
class solution
{
    private:
    vector<int> array;
    unordered_set<int> set;
    
    void add(int n) 
    {
        for(int i = 0; i < array.size(); i++)
            set.insert(array[i] + n);
        array.push_back(n);
    }
    
    bool find(int n)
    {
       return set.find(n) != set.end();
    }
};

/*
add – O(log n) runtime, find – O(n) runtime, O(n) space
*/

class solution
{
    private:
    list<int> my_list;
    
    void add(int n) 
    {
        if(my_list.size() == 0)
            my_list.push_front(n);
        else
        {
            list<int>::iterator it = lower_bound(my_list.begin(), my_list.end(), n);
            my_list.insert(it, n);
        }
    }
    
    bool find(int n)
    {
        vector<int> array;
        for(list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
        {
            array.push_back(*it);
        }
        int begin = 0, end = array.size()-1;
        while(begin < end)
        {
            if(array[begin] + array[end] == n)
                return true;
            else if(array[begin] + array[end] > n)
            {
                end--;
            }
            else
            {
                begin++;
            }
        }
        return false;
    }
};
