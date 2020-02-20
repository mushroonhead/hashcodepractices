#include "OrtoolsSolver.h"

#define _SECURE_SCL 0
#define _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
#define NOMINMAX

#define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS


#include "ortools/algorithms/knapsack_solver.h"

using namespace operations_research;

std::vector<Pizza> PizzaOrderSolver::OrtoolsSolver::solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices)
{
	KnapsackSolver solver(KnapsackSolver::KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER, "OrtoolsPizzaSolver");

	std::vector<int64> values(inpPizzaList.size());
	for (const auto& pizza : inpPizzaList)
	{
		values.emplace_back(pizza.getNumSlice());
	}
	std::vector<std::vector<int64>> weights = std::vector<std::vector<int64>>{ values };

	std::vector<int64> capacity{ inpMaxSlices };

	solver.Init(values, weights, capacity);
	solver.Solve();

	std::vector<Pizza> outputOrder;
	for (int i = 0; i < values.size(); ++i)
	{
		if (solver.BestSolutionContains(i))
		{
			outputOrder.emplace_back(inpPizzaList[i]);
		}
	}
	return outputOrder;

}