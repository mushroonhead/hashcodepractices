#include "LibScheduler.h"

#include <cassert>
#include <queue>

namespace BookScanProblem
{

namespace
{

class bookScanOrderComparator
{
public:
	bool operator() (const Book& lhs, const Book& rhs)
	{
		return lhs.getVal() < rhs.getVal();
	}
};

class libSignupComparator
{
public:
	bool operator() (const LibScheduleInfo& lhs, const LibScheduleInfo& rhs)
	{
		if (lhs.getBookScanSchedule().getDays2Clear() == rhs.getBookScanSchedule().getDays2Clear())
		{
			if (lhs.getBookScanSchedule().getMaxVal() == rhs.getBookScanSchedule().getMaxVal())
			{
				return lhs.getBookScanSchedule().getSignupDuration() > rhs.getBookScanSchedule().getSignupDuration();
			}
			return lhs.getBookScanSchedule().getDays2Clear() > rhs.getBookScanSchedule().getDays2Clear();
		}
		return lhs.getBookScanSchedule().getMaxVal() < rhs.getBookScanSchedule().getMaxVal();
	}
};

}

bool DayScanSchdule::insertBook(const Book& inpBook)
{
	if (m_books.size() < m_capacity)
	{
		m_books.emplace_back(inpBook);
		m_dayVal += inpBook.getVal();
		return true;
	}
	return false;
}

void BookScanSchedule::insertDaySchedule(const DayScanSchdule& inpDaySchedule)
{
	m_maxVal += inpDaySchedule.getDayVal();
	if (m_dayScanScheduleWAccumScores.size() == 0)
	{
		m_days2Clear += m_signupDuration;
	}
	++m_days2Clear;
	m_dayScanScheduleWAccumScores.emplace_back(std::make_pair(inpDaySchedule, m_maxVal));
}

unsigned int BookScanSchedule::getScore(unsigned int inpDayFrmSignup) const
{
	if ((inpDayFrmSignup <= m_signupDuration) || (m_dayScanScheduleWAccumScores.size() == 0))
	{
		return 0U;
	}
	else if (inpDayFrmSignup >= (m_dayScanScheduleWAccumScores.size() + m_signupDuration))
	{
		return m_dayScanScheduleWAccumScores.back().second;
	}
	else
	{
		return m_dayScanScheduleWAccumScores[inpDayFrmSignup - m_signupDuration].second;
	}
}

std::vector<LibScheduleInfo> BookScheduler::solveSchedule(unsigned int inpDays)
{
	std::vector<LibScheduleInfo> outputLibSchedule;
	std::priority_queue<LibScheduleInfo, std::vector<LibScheduleInfo>, libSignupComparator> signupQueue;
	for (const auto& library : m_libs)
	{
		signupQueue.emplace(solveMaxForEachLib(library));
	}

	unsigned int remainingDays = inpDays;
	unsigned int score = 0U;
	while (remainingDays > 0)
	{
		if (!signupQueue.empty())
		{
			auto& nextInQueue = signupQueue.top();
			if (remainingDays > nextInQueue.getBookScanSchedule().getSignupDuration())
			{
				remainingDays -= nextInQueue.getBookScanSchedule().getSignupDuration();
				outputLibSchedule.emplace_back(nextInQueue);
				score += nextInQueue.getBookScanSchedule().getScore(remainingDays);
			}
			signupQueue.pop();
		}
		else
		{
			break;
		}
	}

	return outputLibSchedule;
}

LibScheduleInfo BookScheduler::solveMaxForEachLib(const Library& inpLib)
{
	std::priority_queue<Book, std::vector<Book>, bookScanOrderComparator> valQueue;
	for (const auto& book : inpLib.getBooks())
	{
		valQueue.emplace(book);
	}

	BookScanSchedule bookScanSchedule(inpLib.getSignupTime());
	DayScanSchdule currentDaySchedule(inpLib.getBookFlow());
	while (!valQueue.empty())
	{
		if (!currentDaySchedule.insertBook(valQueue.top()))
		{
			bookScanSchedule.insertDaySchedule(currentDaySchedule);
			currentDaySchedule = DayScanSchdule(inpLib.getBookFlow());
			auto insertCheck = currentDaySchedule.insertBook(valQueue.top());
			assert(insertCheck); //no zero book flow places
		}
		valQueue.pop();
	}
	if (currentDaySchedule.getBooks().size() > 0)
	{
		bookScanSchedule.insertDaySchedule(currentDaySchedule);
	}

	return LibScheduleInfo(inpLib, bookScanSchedule);
}

}