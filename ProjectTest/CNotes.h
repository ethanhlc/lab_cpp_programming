#pragma once


// CNotes dialog

class CNotes : public CDialogEx
{
	DECLARE_DYNAMIC(CNotes)

public:
	CNotes(CWnd* pParent = nullptr);   // standard constructor
	CNotes(int x, int y, int dur);
	virtual ~CNotes();
	int x = -1;
	int y = -1;
	int note = -1;
	int duration = -1;

	int GetNote();
	int GetDur();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTTEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
