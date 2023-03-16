// CNotes.cpp : implementation file
//

#include "pch.h"
#include "ProjectTest.h"
#include "CNotes.h"
#include "afxdialogex.h"


// CNotes dialog

IMPLEMENT_DYNAMIC(CNotes, CDialogEx)

CNotes::CNotes(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECTTEST_DIALOG, pParent)
{

}

CNotes::~CNotes()
{
}

CNotes::CNotes(int x, int y, int dur)
	: x(x), y(y), duration(dur)
{
	int y_note = y - 40;	// (linepos - 10)
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

void CNotes::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNotes, CDialogEx)
END_MESSAGE_MAP()


// CNotes message handlers
