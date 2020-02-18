#pragma once

class Pizza
{
public:
	Pizza(int inpId, int inpNumSlices)
		: m_id(inpId)
		, m_numSlices(inpNumSlices)
	{}
	Pizza(const Pizza&) = default;
	Pizza(Pizza&&) = default;
	Pizza& operator= (const Pizza&) = default;
	Pizza& operator= (Pizza&&) = default;
	~Pizza() = default;

	decltype(auto) getId() const { return m_id; }

	decltype(auto) getNumSlice() const { return m_numSlices; }

private:
	int m_id;
	int m_numSlices;
};