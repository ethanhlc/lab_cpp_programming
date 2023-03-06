
// lab230228Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab230228.h"
#include "lab230228Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab230228Dlg dialog



Clab230228Dlg::Clab230228Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB230228_DIALOG, pParent)
	, m_editBox1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bDate = true;
}

void Clab230228Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editBox1);
}

BEGIN_MESSAGE_MAP(Clab230228Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
//	ON_WM_MOUSEHOVER()
ON_WM_MOUSEWHEEL()
ON_WM_TIMER()
ON_WM_RBUTTONDBLCLK()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Clab230228Dlg message handlers

BOOL Clab230228Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab230228Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Clab230228Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Clab230228Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int Clab230228Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	AfxMessageBox(L"윈도우가 생성되었습니다.", MB_OK | MB_ICONASTERISK);

	return 0;
}


void Clab230228Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	AfxMessageBox(L"Window Destroyed.", MB_YESNOCANCEL | MB_ICONSTOP);
}


void Clab230228Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//AfxMessageBox(L"L Button Double Click.");
	m_editBox1 = L"Mouse Double Click";
	UpdateData(0);

	CDialogEx::OnLButtonDblClk(nFlags, point);
}


BOOL Clab230228Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	CString sWheelTxt;
	if (zDelta > 0)
		sWheelTxt = L"Mouse Wheel Up";
	else
		sWheelTxt = L"Mouse Wheel Down";
	m_editBox1.Format(L"%s: %d, %d", sWheelTxt.GetString(), pt.x, pt.y);
	UpdateData(0);

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void Clab230228Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CTime time;
	time = CTime::GetCurrentTime();

	CString str_time, str_date;
	str_date.Format(L"%4d년 %d월 %d일 ", time.GetYear(), time.GetMonth(), time.GetDay());
	str_time.Format(L"%02d:%02d:%02d", time.GetHour(), time.GetMinute(), time.GetSecond());

	if(m_bDate == true)
		SetDlgItemText(IDC_EDIT1, str_date + str_time);
	else
		SetDlgItemText(IDC_EDIT1, str_time);

	CDialogEx::OnTimer(nIDEvent);
}


void Clab230228Dlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetTimer(1, 1000, NULL);
	AfxMessageBox(L"Timer Created");

	CDialogEx::OnRButtonDblClk(nFlags, point);
}


void Clab230228Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bDate = !m_bDate;
	if(m_bDate == true)
		AfxMessageBox(L"날짜 표시");
	else
		AfxMessageBox(L"날짜 미표시");

	CDialogEx::OnLButtonDown(nFlags, point);
}
