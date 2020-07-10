#include "stdafx.h"

int maxProfit(vector<int>& prices) 
{
	if (prices.size() < 2)
		return 0;

	int has = -prices[0];
	int notHas = 0;
	int cold = 0;

	for (size_t i = 1; i < prices.size(); ++i)
	{
		int newhas = max(has, notHas - prices[i]);
		int newnotHas = max(notHas, cold);
		cold = has + prices[i];
		has = newhas;
		notHas = newnotHas;
	}

	return max(notHas, cold);
}