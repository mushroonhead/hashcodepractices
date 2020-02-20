#pragma once

#include <vector>

namespace BookScanProblem
{

class Book
{
public:
	Book(unsigned int inpId, unsigned int inpVal)
		: m_id(inpId)
		, m_value(inpVal)
	{}
	Book(const Book&) = default;
	Book(Book&&) = default;
	Book& operator= (const Book&) = default;
	Book& operator= (Book&&) = default;
	~Book() = default;

	decltype(auto) getId() const { return m_id; }
	decltype(auto) getVal() const { return m_value; }

private:
	unsigned int m_id;
	unsigned int m_value;
};


class Library
{
public:
	Library(unsigned int inpId, unsigned int inpSignupTIme, unsigned int inpBookFlow, const std::vector<Book> inpBooks)
		: m_id(inpId)
		, m_signupTime(inpSignupTIme)
		, m_bookFlow(inpBookFlow)
		, m_books(inpBooks)
	{}
	Library(const Library&) = default;
	Library(Library&&) = default;
	Library& operator= (const Library&) = default;
	Library& operator= (Library&&) = default;
	~Library() = default;

	decltype(auto) getId() const { return m_id; }
	decltype(auto) getSignupTime() const { return m_signupTime; }
	decltype(auto) getBookFlow() const { return m_bookFlow; }

	decltype(auto) getBooks() const { return m_books; }

private:
	unsigned int m_id;
	unsigned int m_signupTime;
	unsigned int m_bookFlow;

	std::vector<Book> m_books;
};

}