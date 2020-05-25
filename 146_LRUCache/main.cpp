#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache 
{
private:
	unordered_map<int, pair<int, list<int>::iterator>> m_key_value_pos;
	list<int> keylist;
	int capacity;
	int count;
public:
	LRUCache(int capacity) : capacity(capacity), count(0)
	{

	}

	int get(int key) 
	{
		auto ite = m_key_value_pos.find(key);
		if (ite == m_key_value_pos.end())
			return -1;
		setKey(key);
		return ite->second.first;
	}

	void put(int key, int value) 
	{
		auto ite = m_key_value_pos.find(key);
		if (ite == m_key_value_pos.end())
		{
			keylist.push_back(key);
			m_key_value_pos.insert({ key, {value, --keylist.end()} });
			++count;
			if (count > capacity)
			{
				int oldkey = *keylist.begin();
				m_key_value_pos.erase(oldkey);
				keylist.pop_front();
				--count;
			}
		}
		else
		{
			setKey(key);
			m_key_value_pos.find(key)->second = { value, --keylist.end() };
		}
	}

	void setKey(int key)
	{
		auto ite = m_key_value_pos.find(key);
		keylist.erase(ite->second.second);
		keylist.push_back(key);
		ite->second.second = --keylist.end();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
	LRUCache cache = LRUCache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2) << endl;       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1) << endl;         // 返回 -1 (未找到)
	cout << cache.get(3) << endl;        // 返回  3
	cout << cache.get(4) << endl;        // 返回  4

	system("Pause");
	return 0;
}