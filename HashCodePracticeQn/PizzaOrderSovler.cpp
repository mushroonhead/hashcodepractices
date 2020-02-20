#include "PizzaOrderSolver.h"

#include <cassert>
#include <queue>

#include "GreedySolver.h"
#include "OrtoolsSolver.h"

std::vector<Pizza> PizzaOrderSolver::solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices, SolverType inpSolverType)
{
	switch (inpSolverType)
	{
	case SolverType::GREEDY:
	{
		return GreedySolver::solveOrder(inpPizzaList, inpMaxSlices);
	}
	case SolverType::OR_TOOLS:
	{
		return OrtoolsSolver::solveOrder(inpPizzaList, inpMaxSlices);
	}
	default:
	{
		assert(false);
		//no possible
	}

	}
}