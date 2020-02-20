#pragma once

#include <utility>

#include "LibObjects.h"

namespace BookScanProblem
{

class DayScanSchdule //scan schedule for the day
{
public:
	DayScanSchdule(unsigned int inpCap)
		: m_capacity(inpCap)
		, m_books()
		, m_dayVal(0U)
	{}
	DayScanSchdule(const DayScanSchdule&) = default;
	DayScanSchdule(DayScanSchdule&&) = default;
	DayScanSchdule& operator= (const DayScanSchdule&) = default;
	DayScanSchdule& operator= (DayScanSchdule&&) = default;
	~DayScanSchdule() = default;

	decltype(auto) getCap() const { return m_capacity; }
	decltype(auto) getBooks() const { return m_books; }
	decltype(auto) getDayVal() const { return m_dayVal; }

	//Purpose: Attempts to insert book, returns false if fail
	bool insertBook(const Book& inpBook);

private:
	unsigned int m_capacity;
	std::vector<Book> m_books;
	unsigned int m_dayVal;
};

class BookScanSchedule
{
public:
	BookScanSchedule(unsigned int inpSignupDuration)
		: m_signupDuration(inpSignupDuration)
		, m_dayScanScheduleWAccumScores()
		, m_maxVal(0U)
		, m_days2Clear(0U)
	{}
	BookScanSchedule(const BookScanSchedule&) = default;
	BookScanSchedule(BookScanSchedule&&) = default;
	BookScanSchedule& operator= (const BookScanSchedule&) = default;
	BookScanSchedule& operator= (BookScanSchedule&&) = default;
	~BookScanSchedule() = default;

	void insertDaySchedule(const DayScanSchdule& inpBook);

	unsigned int getScore(unsigned int inpDayFrmSignup) const;

	decltype(auto) getSignupDuration() const { return m_signupDuration; }
	decltype(auto) getDayScanScheduleWAccumScores() const { return m_dayScanScheduleWAccumScores; }
	decltype(auto) getMaxVal() const { return m_maxVal; }
	decltype(auto) getDays2Clear() const { return m_days2Clear; }

private:
	unsigned int m_signupDuration;
	std::vector<std::pair<DayScanSchdule, unsigned int>> m_dayScanScheduleWAccumScores;
	unsigned int m_maxVal;
	unsigned int m_days2Clear;
};

class LibScheduleInfo
{
public:
	LibScheduleInfo(const Library& inpLib, const BookScanSchedule& inpScanSchedule)
		: m_lib(inpLib)
		, m_bookScanSchedule(inpScanSchedule)
	{}
	LibScheduleInfo(const LibScheduleInfo&) = default;
	LibScheduleInfo(LibScheduleInfo&&) = default;
	LibScheduleInfo& operator= (const LibScheduleInfo&) = default;
	LibScheduleInfo& operator= (LibScheduleInfo&&) = default;
	~LibScheduleInfo() = default;

	decltype(auto) getLib() const { return m_lib; }
	decltype(auto) getBookScanSchedule() const { return m_bookScanSchedule; }

private:
	Library m_lib;
	BookScanSchedule m_bookScanSchedule;
};


class BookScheduler
{
public:
	BookScheduler(const std::vector<Library>& inpLibList)
		: m_libs(inpLibList)
	{}

	//Purpose: Solve
	std::vector<LibScheduleInfo> solveSchedule(unsigned int inpDays);

private:
	LibScheduleInfo solveMaxForEachLib(const Library& inpLib);

	std::vector<Library> m_libs;
};

}