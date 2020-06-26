#include "I_02_01_RemoveDuplicateNodes.h"

I_02_01_RemoveDuplicateNodes::I_02_01_RemoveDuplicateNodes()
{
}

I_02_01_RemoveDuplicateNodes::~I_02_01_RemoveDuplicateNodes()
{
}

void check(ListNode* head)
{
	ListNode* tail = head->next;
	ListNode* temp = head;

	while (tail != nullptr)
	{
		if (head->val == tail->val)
		{
			temp->next = tail->next;
			delete tail;
			tail = temp->next;
		}
		else
		{
			temp = tail;
			tail = tail->next;
		}
	}
}

ListNode* I_02_01_RemoveDuplicateNodes::removeDuplicateNodes(ListNode* head)
{
	ListNode* tail = head;
	while (tail != nullptr)
	{
		check(tail);
		tail = tail->next;
	}
	
	return head;
}