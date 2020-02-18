#include "GreedySolver.h"

#include <queue>

using namespace PizzaOrderSolver;

namespace
{

class solverPizzaComparator
{
public:
	bool operator() (const Pizza& lhs, const Pizza& rhs)
	{
		return lhs.getNumSlice() < rhs.getNumSlice();
	}

};

class pizzaIdComparator
{
public:
	bool operator() (const Pizza& lhs, const Pizza& rhs)
	{
		return lhs.getId() > rhs.getId();
	}

};

}

std::vector<Pizza> GreedySolver::solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices)
{
	//Sort by size from largest to smallest first
	std::priority_queue<Pizza, std::vector<Pizza>, solverPizzaComparator> pizzaQueue;
	for (const auto& pizza : inpPizzaList)
	{
		pizzaQueue.emplace(pizza);
	}

	std::priority_queue<Pizza, std::vector<Pizza>, pizzaIdComparator> outputQueue;
	int remainingSize = inpMaxSlices;
	//Add in the pizza into order list from largest to smallest, throw if cant fit in
	//Sort by Id at the same time
	while (!pizzaQueue.empty())
	{
		auto& nextPizza = pizzaQueue.top();
		if (nextPizza.getNumSlice() <= remainingSize)
		{
			remainingSize -= nextPizza.getNumSlice();
			outputQueue.emplace(nextPizza);
		}
		pizzaQueue.pop();
	}

	std::vector<Pizza> outputOrder;
	while (!outputQueue.empty())
	{
		outputOrder.emplace_back(outputQueue.top());
		outputQueue.pop();
	}
	return outputOrder;
}