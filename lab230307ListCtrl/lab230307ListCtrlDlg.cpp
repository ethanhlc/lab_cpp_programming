
// lab230307ListCtrlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab230307ListCtrl.h"
#include "lab230307ListCtrlDlg.h"
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


// Clab230307ListCtrlDlg dialog



Clab230307ListCtrlDlg::Clab230307ListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB230307LISTCTRL_DIALOG, pParent)
	, m_strAge(_T(""))
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab230307ListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(Clab230307ListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Clab230307ListCtrlDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Clab230307ListCtrlDlg::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// Clab230307ListCtrlDlg message handlers

BOOL Clab230307ListCtrlDlg::OnInitDialog()
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
	// Get ListControl size
	CRect rect;
	m_List.GetClientRect(&rect);

	// Add Column
	m_List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 300);

	// Add column, set width to (max - above)
	m_List.InsertColumn(1, _T("Age"), LVCFMT_LEFT, rect.Width() - 300);

	//// Add Data to arrays
	//CString sampleName[] = { _T("È«±æµ¿"), _T("±èÃ¶¼ö") };
	//CString sampleAge[] = { _T("12"), _T("14") };

	//for (int i = 0; i < 2; i++)
	//{
	//	// Add names
	//	m_List.InsertItem(i, sampleName[i], i % 5);
	//	// Add age
	//	m_List.SetItemText(i, 1, sampleAge[i]);
	//}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab230307ListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clab230307ListCtrlDlg::OnPaint()
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
HCURSOR Clab230307ListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Clab230307ListCtrlDlg::OnOK()
{
	OnBnClickedButtonAdd();
}


void Clab230307ListCtrlDlg::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	// Get m_strName/Age from edit box
	UpdateData(1);

	// Do nothing if input empty
	if (m_strName.GetLength() == 0 || m_strAge.GetLength() == 0)
	{
		AfxMessageBox(_T("Input fields are empty"), MB_ICONSTOP);
		return;
	}

	// Get number of items in list
	int nItemNum = m_List.GetItemCount();

	CString name = m_strName;
	CString age = m_strAge;

	// Add name
	m_List.InsertItem(nItemNum, name, rand() % 5);
	// Add age
	m_List.SetItemText(nItemNum, 1, age);

	// Clear edit box after adding info to list
	m_strName = "";
	m_strAge = "";

	// Update edit box w/ new values
	UpdateData(0);
}


void Clab230307ListCtrlDlg::OnBnClickedButtonDel()
{
	// TODO: Add your control notification handler code here
	int count = m_List.GetItemCount();

	// if items exist in list
	for (int i = count; i >= 0; i--)
	{
		if (m_List.GetItemState(i, LVIS_SELECTED) != 0)	// if item is selected
		{
			m_List.DeleteItem(i);
		}
	}
}
