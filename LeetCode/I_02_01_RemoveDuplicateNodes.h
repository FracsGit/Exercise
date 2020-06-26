#pragma once
#include "stdafx.h"

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class I_02_01_RemoveDuplicateNodes
{
public:
	I_02_01_RemoveDuplicateNodes();
	~I_02_01_RemoveDuplicateNodes();

	ListNode* removeDuplicateNodes(ListNode* head);
};

