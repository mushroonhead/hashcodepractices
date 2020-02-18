#include "OrderParser.h"

#include <exception>
#include <iostream>
#include <fstream>

bool OrderParser::parseInputFile(std::vector<Pizza>& outPizzaList, int& outMaxOrder, const std::string& inpFilePath)
{
	try 
	{
		std::ifstream inputFile(inpFilePath);
		if (inputFile.is_open())
		{
			std::string data;
			char splitChar = ' ';

			std::getline(inputFile, data, splitChar);
			int maxOrder = std::stoi(data);
			std::getline(inputFile, data);
			int numExpPizza = std::stoi(data);

			int nextId = 0;
			std::vector<Pizza> outputPizzaList;
			while (std::getline(inputFile, data, splitChar))
			{
				outputPizzaList.emplace_back(nextId, stoi(data));
				++nextId;
			}

			if (numExpPizza != outputPizzaList.size())
			{
				throw std::exception("wrong number of pizza parsed");
			}

			outMaxOrder = maxOrder;
			std::swap(outPizzaList, outputPizzaList);

			inputFile.close();

			return true;
		}
		else
		{
			throw std::exception("unable to open file");
		}
	}

	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
		return false;
	}
}


bool OrderParser::parseOutputFile(const std::vector<Pizza>& inpPizzaOrderList, const std::string& inpFileDir)
{
	try
	{
		std::string fileName = "solution.out";
		std::ofstream solutionFile(inpFileDir + fileName);
		
		solutionFile << inpPizzaOrderList.size() << std::endl;

		for (const auto& pizza : inpPizzaOrderList)
		{
			solutionFile << pizza.getId() << ' ';
		}

		return true;
	}

	catch (const std::exception & e)
	{
		std::cout << "error: " << e.what() << std::endl;
		return false;
	}
}