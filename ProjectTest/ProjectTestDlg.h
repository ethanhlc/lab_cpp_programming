
// ProjectTestDlg.h : header file
//

#pragma once


// CProjectTestDlg dialog
class CProjectTestDlg : public CDialogEx
{
// Construction
public:
	CProjectTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CString m_strInput;
	int m_nNoteLength;
	afx_msg void OnBnClickedRHalf();
	afx_msg void OnBnClickedRQuarter();
	afx_msg void OnBnClickedREighth();
	//CImage image;
	//CBitmap bitm;
	CStatic m_Clef;
	afx_msg void OnBnClickedBnErase();
	std::vector<CNotes> m_vctNotes;
	afx_msg void OnBnClickedBtnList();
	CString m_NoteList;
};
