
// lab230223MFCDlg.h : header file
//

#pragma once


// Clab230223MFCDlg dialog
class Clab230223MFCDlg: public CDialogEx
{
// Construction
public:
	Clab230223MFCDlg(CWnd *pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB230223MFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Stores Calculation State
	CString m_upper;
	// Display Input & Value
	CString m_lower;
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedBtndel();
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedNumneg();
	afx_msg void OnBnClickedClear();
};
