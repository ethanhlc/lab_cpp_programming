
// lab230228StopwatchDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab230228Stopwatch.h"
#include "lab230228StopwatchDlg.h"
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


// Clab230228StopwatchDlg dialog



Clab230228StopwatchDlg::Clab230228StopwatchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB230228STOPWATCH_DIALOG, pParent)
	, m_sTimer(_T(""))
	, m_sLaps(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bReset = false;
	m_bRun = false;
}

void Clab230228StopwatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TIMER, m_sTimer);
	DDX_Text(pDX, IDC_LAPS, m_sLaps);
}

BEGIN_MESSAGE_MAP(Clab230228StopwatchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
//	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_START, &Clab230228StopwatchDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_RESET, &Clab230228StopwatchDlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_LAP, &Clab230228StopwatchDlg::OnBnClickedLap)
	ON_BN_CLICKED(IDC_SAVE, &Clab230228StopwatchDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// Clab230228StopwatchDlg message handlers

BOOL Clab230228StopwatchDlg::OnInitDialog()
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

	GetDlgItem(IDC_TIMER)->GetFont()->GetLogFont(&LogFont);
	LogFont.lfWeight = 100;
	LogFont.lfHeight = 72;

	font.CreateFontIndirectW(&LogFont);
	GetDlgItem(IDC_TIMER)->SetFont(&font);
	// end IDC_TIME font
	////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab230228StopwatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab230228StopwatchDlg::OnPaint()
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
HCURSOR Clab230228StopwatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int Clab230228StopwatchDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_sTimer = L"00:00.00";

	return 0;
}


void Clab230228StopwatchDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void Clab230228StopwatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	static int subSec = 0;
	static int minutes, seconds;

	if (m_bReset)
	{
		m_bReset = false;
		subSec = 0;
		seconds = 0;
		minutes = 0;
	}

	if (++subSec > 99)
	{
		subSec = 0;
		seconds++;
	}
	if (seconds > 59)
	{
		seconds = 0;
		minutes++;
	}

	//CString timer;
	//timer.Format(L"%02d:%02d.%02d", minutes, seconds, subSec);
	//SetDlgItemText(IDC_TIMER, timer);
	m_sTimer.Format(L"%02d:%02d.%02d", minutes, seconds, subSec);
	UpdateData(0);

	CDialogEx::OnTimer(nIDEvent);
}


void Clab230228StopwatchDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bRun)
	{
		// pause
		KillTimer(1);
		GetDlgItem(IDC_START)->SetWindowTextW(L"START");
	}
	else
	{
		// start & restart
		SetTimer(1, 10, NULL);
		GetDlgItem(IDC_START)->SetWindowTextW(L"PAUSE");
	}
	m_bRun = !m_bRun;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Clab230228StopwatchDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// if already reset, do nothing
	if (m_sTimer == L"00:00.00")
		return;

	int retval = AfxMessageBox(L"타이머를 초기화 하시겠습니까?", MB_YESNO | MB_ICONEXCLAMATION);
	if (retval == IDYES)
	{
		// reset
		// AfxMessageBox(L"YES");
		KillTimer(1);
		m_sTimer = L"00:00.00";
		GetDlgItem(IDC_START)->SetWindowTextW(L"START");
		m_bRun = false;
		m_bReset = true;
		UpdateData(0);
	}
	else if (retval == IDNO)
	{
		// no reset
		// AfxMessageBox(L"NO");
		;
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}


void Clab230228StopwatchDlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bRun)
	{
		m_sLaps = m_sLaps + m_sTimer + L"\r\n";
		UpdateData(0);
	}

	CDialogEx::OnMButtonDown(nFlags, point);
}


//void Clab230228StopwatchDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	// NOT WORKING DUE TO EDITBOX
//	CString ch;
//	ch.Format(L"%d", nChar);
//	AfxMessageBox(ch);
//
//	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
//}


void Clab230228StopwatchDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	if (m_bRun)
	{
		// pause
		KillTimer(1);
		GetDlgItem(IDC_START)->SetWindowTextW(L"START");
	}
	else
	{
		// start & restart
		SetTimer(1, 10, NULL);
		GetDlgItem(IDC_START)->SetWindowTextW(L"PAUSE");
	}
	m_bRun = !m_bRun;
}


void Clab230228StopwatchDlg::OnBnClickedReset()
{
	// TODO: Add your control notification handler code here
	// if already reset, do nothing
	if (m_sTimer == L"00:00.00")
		return;
	int retval = AfxMessageBox(L"타이머를 초기화 하시겠습니까?", MB_YESNO | MB_ICONEXCLAMATION);
	if (retval == IDYES)
	{
		// reset
		// AfxMessageBox(L"YES");
		KillTimer(1);
		m_sTimer = L"00:00.00";
		GetDlgItem(IDC_START)->SetWindowTextW(L"START");
		m_sLaps = "";
		m_bRun = false;
		m_bReset = true;
		UpdateData(0);
	}
	else if (retval == IDNO)
	{
		// no reset
		// AfxMessageBox(L"NO");
		;
	}
}


void Clab230228StopwatchDlg::OnBnClickedLap()
{
	// TODO: Add your control notification handler code here
	if (m_bRun)
	{
		m_sLaps = m_sLaps + m_sTimer + L"\n";
		UpdateData(0);
	}
}


void Clab230228StopwatchDlg::OnBnClickedSave()
{
	// TODO: Add your control notification handler code here
	//CFile file;
	CStdioFile file;

	// if file open failed
	if (file.Open(L"laptimes.txt", CFile::modeWrite | CFile::modeCreate) == false)
		return;

	file.WriteString(m_sLaps);
	file.Close();

	AfxMessageBox(L"Lap Times Saved", MB_ICONASTERISK);
}
