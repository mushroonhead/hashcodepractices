#pragma once

#include <vector>

#include "Pizza.h"

//Purpose:
//Available methods to use
enum class SolverType
{
	GREEDY,
	OS_TOOLS
};

//Purpose:
//Contains method to solve pizza order
namespace PizzaOrderSolver
{
	//Purpose: solve on current pizza list given max num of slices allowed
	std::vector<Pizza> solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices, SolverType inpSolverType);
}