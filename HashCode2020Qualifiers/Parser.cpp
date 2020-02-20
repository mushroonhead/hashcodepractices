#include "Parser.h"

#include <cassert>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace BookScanProblem;

bool Parser::parseInputFile(std::unordered_map<unsigned int, Book>& outBookDict, std::vector<Library>& outLibList, int& outNumDays, const std::string& inpFilePath)
{
	try
	{
		std::ifstream inputFile(inpFilePath);
		if (inputFile.is_open())
		{
			std::string data;
			char splitChar = ' ';

			std::getline(inputFile, data, splitChar);
			int numBooks = std::stoi(data);
			std::getline(inputFile, data, splitChar);
			int numLib = std::stoi(data);
			std::getline(inputFile, data);
			int numDays = std::stoi(data);

			outBookDict.clear();
			std::getline(inputFile, data);
			std::stringstream ss(data);
			for (int bookId = 0; bookId < numBooks; ++bookId)
			{
				std::string strScore;
				std::getline(ss, strScore, splitChar);
				outBookDict.emplace(std::make_pair(bookId, Book(bookId, std::stoi(data))));
			}

			if (numBooks != outBookDict.size())
			{
				throw std::exception("wrong number of books in total");
			}

			for (int libId = 0; libId < numLib; ++libId)
			{
				std::getline(inputFile, data);
				std::stringstream libss(data);
				std::getline(libss, data, splitChar);
				int numBookInLib = std::stoi(data);
				std::getline(libss, data, splitChar);
				int signupTime = std::stoi(data);
				std::getline(libss, data, splitChar);
				int flow = std::stoi(data);

				std::getline(inputFile, data);
				std::stringstream bookss(data);
				std::vector<Book> bookList;
				for (int bkInd = 0; bkInd < numBookInLib; ++bkInd)
				{
					std::getline(bookss, data, splitChar);
					int bookId = std::stoi(data);
					bookList.emplace_back(outBookDict.at(bookId));
				}

				if (numBookInLib != bookList.size())
				{
					throw std::exception("wrong number of books in lib");
				}

				outLibList.emplace_back(libId, signupTime, flow, bookList);
			}

			if (numLib != outLibList.size())
			{
				throw std::exception("wrong number of lib");
			}

			inputFile.close();

			return true;
		}
		else
		{
			throw std::exception("unable to open file");
		}
	}

	catch (const std::exception & e)
	{
		std::cout << "error: " << e.what() << std::endl;
		return false;
	}
}

bool Parser::parseOutputFile(std::vector<LibScheduleInfo>& libList, const std::string& inpFileDir)
{
	try
	{
		std::string fileName = "solution.out";
		std::ofstream solutionFile(inpFileDir + fileName);

		solutionFile << libList.size() << std::endl;

		for (const auto& libSch : libList)
		{
			solutionFile << libSch.getLib().getId() << ' ' << libSch.getLib().getBooks().size() << std::endl;
			for (const auto& dayOrder : libSch.getBookScanSchedule().getDayScanScheduleWAccumScores())
			{
				for (const auto& book : dayOrder.first.getBooks())
				{
					solutionFile << book.getId() << ' ';
				}
			}
			solutionFile << std::endl;
		}

		return true;
	}

	catch (const std::exception & e)
	{
		std::cout << "error: " << e.what() << std::endl;
		return false;
	}
}