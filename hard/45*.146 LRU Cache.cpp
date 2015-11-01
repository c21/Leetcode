/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache
{

	private:
	unordered_map<int, list<pair<int,int> >::iterator> map;
	list<pair<int,int> > my_list;
	int num;
	
	public:

	LRUCache(int capacity) 
	{
		num = capacity;		
	}

    

    	int get(int key) 
	{
		if(map.find(key) == map.end())
		{
			return -1;
		}	
		else
		{
			pair<int,int> p = *(map[key]);
			my_list.erase(map[key]);
			my_list.push_front(p);
			map[key] = my_list.begin();
			return p.second;
		}
	}

    

	void set(int key, int value) 
	{
		if(map.find(key) == map.end())
		{
	
			if(map.size() == num)
			{
				map.erase(my_list.back().first);	
				my_list.pop_back();		
			}
			pair<int,int> p = make_pair(key, value);
				my_list.push_front(p);
				map[key] = my_list.begin();	
		}
		else
		{
			pair<int,int> p = *(map[key]);
			p.second = value;
			my_list.erase(map[key]);
			my_list.push_front(p);
			map[key] = my_list.begin();		
		}	 
	}

};

/*
  这题用哈希表超时。
  答案是用哈希表存储key和对应双向链表的位置。
  双向链表存储key和value.双向链表保持元素的新旧访问顺序。
  双向链表list 加入头部：push_front, 删除尾部：pop_back, 取头部：begin(), 取尾部：back(), 删除某个元素erase()
  为O(1)复杂度。
*/
