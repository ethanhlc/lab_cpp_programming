#pragma once


// CDlgTab4 dialog

class CDlgTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTab4)

public:
	CDlgTab4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgTab4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
