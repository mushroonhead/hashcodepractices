#pragma once

#include <string>
#include <unordered_map>

#include "LibObjects.h"
#include "LibScheduler.h"

namespace BookScanProblem
{

namespace Parser
{

bool parseInputFile(std::unordered_map<unsigned int, Book>& outBookDict, std::vector<Library>& outLibList, int& outNumDays, const std::string& inpFilePath);

bool parseOutputFile(std::vector<LibScheduleInfo>& libList, const std::string& inpFileDir);

}



}