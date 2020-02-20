#pragma once

#include <vector>

#include "Pizza.h"

namespace PizzaOrderSolver
{

namespace OrtoolsSolver
{
//Purpose: solve on current pizza list given max num of slices allowed using the greedy method
std::vector<Pizza> solveOrder(const std::vector<Pizza>& inpPizzaList, int inpMaxSlices);

}

}