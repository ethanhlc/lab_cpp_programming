
// ProjectTestDlg.h : header file
//

#pragma once

#include <vector>
#include <algorithm>
#include "CNotes.h"
#include "SerialCom.h"

// CProjectTestDlg dialog
class CProjectTestDlg : public CDialogEx
{
// Construction
public:
	CProjectTestDlg(CWnd* pParent = nullptr);	// standard constructor

	CSerialComm* m_comm;
	LRESULT		OnThreadClosed(WPARAM length, LPARAM lpara);
	LRESULT		OnReceive(WPARAM length, LPARAM lpara);

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
	bool sortFunc(const CNotes& a, const CNotes& b);
	afx_msg void OnBnClickedBtnConnect();
	BOOL comport_state;

	CComboBox m_combo_comport_list;
	CString m_str_comport = _T("COM17");
	CComboBox m_combo_baudrate_list;
	CString m_combo_baudrate = _T("115200");
	CEdit m_edit_rcv_view;
	CEdit m_edit_send_data;
	afx_msg void OnBnClickedBtnSend();
};
