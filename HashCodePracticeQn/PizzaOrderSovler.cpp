#include "PizzaOrderSolver.h"

#include <cassert>
#include <queue>

#include "GreedySolver.h"

std::vector<Pizza> PizzaOrderSolver::solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices, SolverType inpSolverType)
{
	switch (inpSolverType)
	{
	case SolverType::GREEDY:
	{
		return GreedySolver::solveOrder(inpPizzaList, inpMaxSlices);
	}
	case SolverType::OS_TOOLS:
	{

	}
	default:
	{
		assert(false);
		//no possible
	}

	}
}