
// lab230228ClockDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab230228Clock.h"
#include "lab230228ClockDlg.h"
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


// Clab230228ClockDlg dialog



Clab230228ClockDlg::Clab230228ClockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB230228CLOCK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bDate = true;
}

void Clab230228ClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clab230228ClockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Clab230228ClockDlg message handlers

BOOL Clab230228ClockDlg::OnInitDialog()
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
	////
	// start IDC_TIME font
	static CFont font;
	LOGFONT LogFont;

	GetDlgItem(IDC_TIME)->GetFont()->GetLogFont(&LogFont);
	LogFont.lfWeight = 100;
	LogFont.lfHeight = 32;

	font.CreateFontIndirectW(&LogFont);
	GetDlgItem(IDC_TIME)->SetFont(&font);
	// end IDC_TIME font
	////


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab230228ClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab230228ClockDlg::OnPaint()
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
HCURSOR Clab230228ClockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int Clab230228ClockDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 1000, NULL);
	m_bRunning = true;

	return 0;
}


void Clab230228ClockDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CTime time;
	time = CTime::GetTickCount();

	CString strTime, strDate;
	strTime.Format(L"%02d:%02d:%02d", time.GetHour(), time.GetMinute(), time.GetSecond());
	strDate.Format(L"%4d년 %d월 %d일 ", time.GetYear(), time.GetMonth(), time.GetDay());
	if (m_bDate == true)
		SetDlgItemText(IDC_TIME, strDate + strTime);
	else
		SetDlgItemText(IDC_TIME, strTime);

	CDialogEx::OnTimer(nIDEvent);
}


void Clab230228ClockDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bDate = !m_bDate;
	if (m_bDate == true)
		AfxMessageBox(L"날짜 표시", MB_ICONASTERISK);
	else
		AfxMessageBox(L"날짜 미표시", MB_ICONASTERISK);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Clab230228ClockDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bRunning = !m_bRunning;
	if (m_bRunning)
	{
		SetTimer(1, 1000, NULL);
		AfxMessageBox(L"시계를 시작합니다.", MB_ICONASTERISK);
	}
	else
	{
		KillTimer(1);
		AfxMessageBox(L"시계를 멈춥니다.", MB_ICONERROR);
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}


void Clab230228ClockDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}
