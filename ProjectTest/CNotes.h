#pragma once


// CNotes dialog

class CNotes
{

public:
	CNotes(int x, int y, int dur);
	virtual ~CNotes();
	int x = -1;
	int y = -1;
	int note = -1;
	int duration = -1;

	int GetNote();
	int GetDur();

	bool operator < (const CNotes& comp) const;
};
