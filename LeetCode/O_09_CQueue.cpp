#include "O_09_CQueue.h"



O_09_CQueue::O_09_CQueue()
{
}


O_09_CQueue::~O_09_CQueue()
{
}

class CQueue 
{
private:
	stack<int> head, tail;

public:
	CQueue() 
	{

	}

	void appendTail(int value) 
	{
		tail.push(value);
	}

	int deleteHead() 
	{
		if (head.empty())
		{
			while (!tail.empty())
			{
				head.push(tail.top());
				tail.pop();
			}
		}

		if (!head.empty())
		{
			int temp = head.top();
			head.pop();
			return temp;
		}
		else
		{
			return -1;
		}
	}
};