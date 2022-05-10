#pragma once

class PMBASECLASSAPI CPM_RITICAL_SECTION
{
public:
	CPM_RITICAL_SECTION(CRITICAL_SECTION * pSection);
	virtual ~CPM_RITICAL_SECTION(void);

	void PMEnterCriticalSection();

	void PMLeaveCriticalSection();

protected:

	CRITICAL_SECTION * m_pSection;
};
