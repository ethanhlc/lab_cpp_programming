// MFCSTMProjectDlg.h : header file
//

#pragma once

#include "CNotes.h"
#include <vector>
#include <algorithm>

// CMFCSTMProjectDlg dialog
class CMFCSTMProjectDlg : public CDialogEx
{
    // Construction
public:
    CMFCSTMProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MFCSTMPROJECT_DIALOG };
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
    // message functions
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnBnClickedRHalfNote();
    afx_msg void OnBnClickedRQuarterNote();
    afx_msg void OnBnClickedREighthNote();
    afx_msg void OnBnClickedBtnList();
    afx_msg void OnBnClickedBtnErase();
    // functions
    void SortNotes();
    // variables
    int m_nNoteLength = 2;
    std::vector<CNotes> m_vctNotes;
    CString m_strNoteDisp;
    CString m_strDebug;
};
