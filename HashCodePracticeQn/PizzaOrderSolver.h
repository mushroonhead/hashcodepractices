#pragma once

#include <vector>

#include "Pizza.h"

//Purpose:
//Contains method to solve pizza order
namespace PizzaOrderSolver
{
	//Purpose: solve on current pizza list given max num of slices allowed
	std::vector<Pizza> solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices);
}