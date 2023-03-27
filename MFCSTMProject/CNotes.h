// CNotes.h : class header file

#pragma once
class CNotes
{
public:
    CNotes(int x, int y, int dur, bool rest);
    virtual ~CNotes();
    int x = -1;
    int y = -1;
    int note = -1;
    int duration = -1;
    bool rest = false;

    int GetNote();
    int GetDur();
    bool GetRest();

    bool operator < (const CNotes& comp) const;
};
