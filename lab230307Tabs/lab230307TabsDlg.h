
// lab230307TabsDlg.h : header file
//

#pragma once

// Tab Headers
#include "CDlgTab1.h"
#include "CDlgTab2.h"
#include "CDlgTab3.h"
#include "CDlgTab4.h"


// Clab230307TabsDlg dialog
class Clab230307TabsDlg : public CDialogEx
{
// Construction
public:
	Clab230307TabsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB230307TABS_DIALOG };
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
	CTabCtrl m_Tab;
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	CDlgTab1* dlg1;
	CDlgTab2* dlg2;
	CDlgTab3* dlg3;
	CDlgTab4* dlg4;
};
