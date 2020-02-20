#include "LibObjects.h"
#include "LibScheduler.h"
#include "Parser.h"

#include <iostream>

using namespace BookScanProblem;

std::string inputFilePath = "../HashCode2020Qualifiers/ProblemSet/e_so_many_books.txt";
std::string outputFileDir = "../HashCode2020Qualifiers/ProblemSet/";

int main()
{
	std::cout << "Hash Code 2020 Qualifier Qn" << std::endl;

	std::unordered_map<unsigned int, Book> bookDict;
	std::vector<Library> libList;
	int numDays;

	Parser::parseInputFile(bookDict, libList, numDays, inputFilePath);
	BookScheduler scheduler(libList);
	auto soln = scheduler.solveSchedule(numDays);
	

	Parser::parseOutputFile(soln, outputFileDir);

	std::string dataIn;
	std::cout << "press key + enter to continue" << std::endl;
	std::cin >> dataIn;
}