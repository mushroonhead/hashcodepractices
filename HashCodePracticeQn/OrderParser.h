#pragma once

#include <string>
#include <vector>

#include "Pizza.h"

//Purpose:
//Contains methods to parse the inputs and the outputs
namespace OrderParser
{

//Purpose: Parse input file for competition, returns true if success
bool parseInputFile(std::vector<Pizza>& outPizzaList, int& outMaxOrder, const std::string& inpFilePath);

//Purpose: Parse output file for competition, returns true if success
bool parseOutputFile(const std::vector<Pizza>& pizzaOrderList, const std::string& inpFileDir);

}