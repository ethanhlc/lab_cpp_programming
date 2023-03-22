// MFCSTMProjectDlg.h : header file
//

#pragma once

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
    // functions
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    // variables
    int m_nNoteLength = 2;
    afx_msg void OnBnClickedRHalfNote();
    afx_msg void OnBnClickedRQuarterNote();
    afx_msg void OnBnClickedREighthNote();
};
