#include "stdafx.h"
#include "I_02_01_RemoveDuplicateNodes.h"

int main()
{
	I_02_01_RemoveDuplicateNodes temp;
	vector<int> v = { 17, 23, 15, 30, 21, 5, 20, 14, 5, 9, 22, 6, 22, 20, 14, 12, 4, 21, 27, 5, 4, 21, 27, 0, 14, 21, 17, 27, 6, 12, 28, 17, 29, 8, 17, 13, 7, 26, 7, 31, 27, 8, 31, 19, 5, 23, 9, 0, 22, 0, 26, 30, 14, 10, 6, 8, 16, 24, 15, 21, 2, 3, 5, 15 };
	ListNode* head = new ListNode(0);
	ListNode* node = head;
	for (int x : v)
	{
		node->next = new ListNode(x);
		node = node->next;
	}

	head = temp.removeDuplicateNodes(head);
	node = head;
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;


	system("Pause");
	return 0;
}