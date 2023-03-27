// MFCSTMProjectDlg.h : header file
//

#pragma once

#include "CNotes.h"
#include "CSerialComm.h"
#include <vector>
#include <algorithm>

// Custom Defines
#define YTOP 50

// CMFCSTMProjectDlg dialog
class CMFCSTMProjectDlg : public CDialogEx
{
    // Construction
public:
    CMFCSTMProjectDlg(CWnd* pParent = nullptr);         // standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MFCSTMPROJECT_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

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
    afx_msg void OnDestroy();
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnBnClickedRHalfNote();
    afx_msg void OnBnClickedRQuarterNote();
    afx_msg void OnBnClickedREighthNote();
    afx_msg void OnBnClickedBtnList();
    afx_msg void OnBnClickedBtnErase();
    afx_msg void OnBnClickedBtnRedraw();
    afx_msg void OnBnClickedBtnSend();
    afx_msg void OnBnClickedBtnPlay();
    afx_msg void OnBnClickedRHalfRest();
    afx_msg void OnBnClickedRQuarterRest();
    afx_msg void OnBnClickedREighthRest();
    // SerialComm
    CSerialComm* m_comm = NULL;
    LRESULT OnThreadClosed(WPARAM length, LPARAM lpara);
    LRESULT OnReceive(WPARAM length, LPARAM lpara);
    afx_msg void OnBnClickedConnectClose();
    afx_msg void OnSelchangeComboBaud();
    afx_msg void OnSelchangeComboComport();
    afx_msg void OnDropdownComboComport();
    CComboBox m_comboCOMPort;
    CComboBox m_comboBaudRate;
    CString m_strCOMPort = _T("COM1");
    CString m_strBaudRate = _T("115200");
    bool comport_state = false;
    // functions
    void SortNotes();
    void DrawNotes(int x, int y, int dur, bool rest);
    // variables
    int m_nNoteLength = 2;
    bool m_bRest = false;
    std::vector<CNotes> m_vctNotes;
    CString m_strNoteDisp;
    CString m_strDebug;
};
