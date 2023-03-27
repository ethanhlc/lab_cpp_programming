// CNotes.cpp : class implementation file

#include "pch.h"
#include "CNotes.h"
#include "MFCSTMProjectDlg.h"

CNotes::~CNotes()
{
}

CNotes::CNotes(int x, int y, int dur, bool rest)
    : x(x), y(y), duration(dur), rest(rest)
{
    if (rest)
    {
        note = -1;
        return;
    }
    int y_note = y - (YTOP + 10);   // (linepos + 10)
    y_note = y_note / 10;
    note = 10 - y_note;
}

int CNotes::GetNote()
{
    return note;
}

int CNotes::GetDur()
{
    return duration;
}

bool CNotes::GetRest()
{
    return rest;
}

bool CNotes::operator<(const CNotes& comp) const
{
    return x < comp.x;
}
