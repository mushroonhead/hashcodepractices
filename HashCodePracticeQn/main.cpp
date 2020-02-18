#include <iostream>
#include <string>

#include "PizzaOrderSolver.h"
#include "OrderParser.h"

std::string inputFilePath = "../HashCodePracticeQn/ProblemSet/e_also_big.in";
std::string outputFileDir = "../HashCodePracticeQn/ProblemSet/";

int main()
{
	std::cout << "Hash Code Practive Question" << std::endl;

	std::vector<Pizza> pizzaList; int maxOrderSize;
	auto readSuccess = OrderParser::parseInputFile(pizzaList, maxOrderSize, inputFilePath);

	if (readSuccess)
	{
		auto outputOrder = PizzaOrderSolver::solveOrder(pizzaList, maxOrderSize, SolverType::GREEDY);

		int score = 0;
		for (const auto& pizza : outputOrder)
		{
			score += pizza.getNumSlice();
			std::cout << "Pizza Id: " << pizza.getId() << "\tSize: " << pizza.getNumSlice() << std::endl;
		}
		std::cout << "Score: " << score << " out of " << maxOrderSize << std::endl;

		bool writeSuccess = OrderParser::parseOutputFile(outputOrder, outputFileDir);
		if (writeSuccess)
		{
			std::cout << "Output file written to: " << outputFileDir << std::endl;
		}
		else
		{
			std::cout << "File writing fail" << std::endl;
		}
	}
	else
	{
		std::cout << "Read Fail" << std::endl;
	}
	

	std::string dataIn;
	std::cout << "press key + enter to continue" << std::endl;
	std::cin >> dataIn;
}